// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_CHASSIS_CHASSISCONTROLCOMPONENT_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_CHASSIS_CHASSISCONTROLCOMPONENT_H

/************************************************************
 ChassisControlComponent class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/Pkg_Chassis.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/Module.h"
#include "CarFactoryLibrary/Pkg_CarFactoryLibrary.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ChassisChassisControlComponent__Controller.h"
#include "MindsensorsPapyrusLibrary/ConcreteClasses/CppNumericPad.h"

// Include from Include stereotype (header)
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class StopProcess;
}
}
namespace CarFactoryLibrary {
namespace events {
class ErrorDetection;
}
}
namespace CarFactoryLibrary {
namespace events {
class EndOfModule;
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILcd;
}
}
}
namespace CarFactoryLibrary {
class IModule;
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class RestartAfterEmergencyStop;
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class PrepareConveyor;
}
}

// End of Include stereotype (header)

namespace CarFactoryLibrary {
namespace events {
class ErrorDetection;
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Chassis {

/************************************************************/
/**
 * 
 */
class ChassisControlComponent: public ::CarFactoryLibrary::Module {
public:
	/**
	 * 
	 */
	::CarFactoryLibrary::Colors front_color;
	/**
	 * 
	 */
	::CarFactoryLibrary::Colors back_color;
	/**
	 * 
	 */
	::CarFactoryLibrary::Colors roof_color;
	/**
	 * 
	 */
	::CarFactoryLibrary::BluetoothSlaveEnum msg;
	/**
	 * 
	 */
	::MindsensorsPapyrusLibrary::ConcreteClasses::CppNumericPad keypad;
	/**
	 * 
	 */
	int x;
	/**
	 * 
	 */
	int y;
	/**
	 * 
	 */
	int z;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisControlComponent__Controller chassiscontrolcomponentController;

	StateMachine ChassisControlStateMachine {
		InitialState Initialization;
		State Misplace;
		PseudoChoice choice0;
		State EmergencyStopState {
			InitialState CheckState;
			PseudoChoice choice1;
			State StopMotors;
		};
		PseudoChoice choice2;
		State EmergencyButtonPressState;
		State EmergencyStopDisplay;
		PseudoChoice choice13;
		State SendRestartEvent;
		State PrepareConveyor;
		PseudoChoice choice5;
		State PlaceOrder;
		State SendStopMessage;
		FinalState FinalState2;
		State ChooseBackFrontOrder;
		PseudoChoice choice;
		FinalState FinalState1;
		PseudoChoice choice4;
		SignalEvent<CarFactoryLibrary::events::EndOfModule> EndOfModule;
		SignalEvent<CarFactoryLibrary::events::ErrorDetection> ErrorDetection;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::StopProcess> StopProcess;
		TimeEvent(TE_50_ms_, 50)
		TransitionTable {
			//For external transtition: ExT(name, source, target, guard, event, effect)
			//For local transtition: LoT(name, source, target, guard, event, effect)
			//For internal transtition: ExT(name, source, guard, event, effect)
			ExT(fromInitializationtoChoice13 , Initialization , choice13 , NULL , NULL , NULL );
			ExT(fromMisplacetoChoice0 , Misplace , choice0 , NULL , NULL , NULL );
			ExT(fromEmergencyStopStatetoChoice2 , EmergencyStopState , choice2 , NULL , EndOfModule , NULL );
			ExT(fromEmergencyStopStatetoMisplace , EmergencyStopState , Misplace , NULL , ErrorDetection , effectFromEmergencyStopStatetoMisplace );
			ExT(fromEmergencyStopStatetoEmergencyButtonPressState , EmergencyStopState , EmergencyButtonPressState , NULL , StopProcess , NULL );
			ExT(fromCheckStatetoChoice1 , CheckState , choice1 , NULL , NULL , NULL );
			ExT(fromStopMotorstoEmergencyButtonPressState , StopMotors , EmergencyButtonPressState , NULL , NULL , NULL );
			ExT(fromEmergencyButtonPressStatetoEmergencyStopDisplay, EmergencyButtonPressState , EmergencyStopDisplay , NULL , NULL , NULL );
			ExT(fromEmergencyStopDisplaytoChoice5 , EmergencyStopDisplay , choice5 , NULL , NULL , NULL );
			ExT(fromSendRestartEventtoPrepareConveyor , SendRestartEvent , PrepareConveyor , NULL , NULL , NULL );
			ExT(fromPrepareConveyortoEmergencyStopState , PrepareConveyor , EmergencyStopState , NULL , NULL , NULL );
			ExT(fromPlaceOrdertoPrepareConveyor , PlaceOrder , PrepareConveyor , NULL , NULL , NULL );
			ExT(fromSendStopMessagetoFinalState , SendStopMessage , FinalState2 , NULL , NULL , NULL );
			ExT(fromChooseBackFrontOrdertoPlaceOrder , ChooseBackFrontOrder , PlaceOrder , NULL , NULL , NULL );
			ExT(fromChoice0toSendRestartEvent , choice0 , SendRestartEvent , fromChoice0toSendRestartEventGuard , NULL , choice0toSendRestartEventEffect );
			ExT(fromChoice0toChoice , choice0 , choice , NULL , NULL , NULL );
			ExT(fromChoice1toCheckState , choice1 , CheckState , NULL , TE_50_ms_ , NULL );
			ExT(fromChoice1toStopMotors , choice1 , StopMotors , fromChoice1toStopMotorsGuard , NULL , NULL );
			ExT(fromChoice2toSendStopMessage , choice2 , SendStopMessage , NULL , NULL , rewind_last_module );
			ExT(fromChoice2toPrepareConveyor , choice2 , PrepareConveyor , fromChoice2toPrepareConveyorGuard , NULL , fromChoice2toPrepareConvoyerEffect );
			ExT(fromChoice13toChooseBackFrontOrder , choice13 , ChooseBackFrontOrder , fromChoice13toChooseBackFrontOrderGuard , NULL , NULL );
			ExT(fromChoice13toFinalState1 , choice13 , FinalState1 , NULL , NULL , NULL );
			ExT(fromChoice5toChoice4 , choice5 , choice4 , NULL , NULL , NULL );
			ExT(fromChoice5toSendRestartEvent , choice5 , SendRestartEvent , fromChoice5toSendRestartEventGuard , NULL , NULL );
			ExT(fromChoicetoMisplace , choice , Misplace , NULL , NULL , NULL );
			ExT(fromChoicetoSendRestartEvent , choice , SendRestartEvent , fromChoicetoSendRestartEventGuard , NULL , NULL );
			ExT(fromChoice4toSendRestartEvent , choice4 , SendRestartEvent , fromChoice4toSendRestartEventGuard , NULL , NULL );
			ExT(fromChoice4toEmergencyStopDisplay , choice4 , EmergencyStopDisplay , NULL , NULL , NULL );
		}
	};
	/**
	 * 
	 */
	InFlowPort<LegoCarFactoryRefactoringForSync::signals::StopProcess> pStopProcess_Convoyer;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::ErrorDetection> pErrDetect;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo;
	/**
	 * 
	 */
	OutFlowPort<LegoCarFactoryRefactoringForSync::signals::StopProcess> pOutStopProcess_Shelf;
	/**
	 * 
	 */
	OutFlowPort<LegoCarFactoryRefactoringForSync::signals::StopProcess> pOutStopProcess_RoboticArm;
	/**
	 * 
	 */
	OutFlowPort<
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> pOutRestart_Shelf;
	/**
	 * 
	 */
	OutFlowPort<
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> pOutRestart_Convoyer;
	/**
	 * 
	 */
	OutFlowPort<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor> pPrepare;
	/**
	 * 
	 */
	OutFlowPort<
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> pOutRestart_Robotic;
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice4toSendRestartEventGuard();
	/**
	 * 
	 */
	ChassisControlComponent();
	/**
	 * 
	 * @return ret 
	 */
	int wait_key_pad_release();
	/**
	 * 
	 */
	void show_car_configuration();
	/**
	 * 
	 */
	void choose_colors();
	/**
	 * 
	 * @return ret 
	 */
	bool init_bluetooth_communication();
	/**
	 * 
	 */
	void send_stop_to_slave();
	/**
	 * 
	 */
	void choose_back_front_order();
	/**
	 * 
	 * @param sig 
	 */
	void effectFromEmergencyStopStatetoMisplace(
			::CarFactoryLibrary::events::ErrorDetection& /*in*/sig);
	/**
	 * 
	 */
	void choice0toSendRestartEventEffect();
	/**
	 * 
	 */
	void rewind_last_module();
	/**
	 * 
	 */
	void fromChoice2toPrepareConvoyerEffect();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice2toPrepareConveyorGuard();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice1toStopMotorsGuard();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice0toSendRestartEventGuard();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoicetoSendRestartEventGuard();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice13toChooseBackFrontOrderGuard();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice5toSendRestartEventGuard();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Chassis
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisControlComponent class header
 ************************************************************/

#endif
