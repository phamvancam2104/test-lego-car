// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_ROOF_ROOFCONVOYER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_ROOF_ROOFCONVOYER_H

/************************************************************
 RoofConvoyer class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/Pkg_Roof.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/Conveyor.h"
#include "CarFactoryLibrary/Pkg_CarFactoryLibrary.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/RoofRoofConvoyer__Controller.h"

// Include from Include stereotype (header)
using namespace CarFactoryLibrary;
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class StopProcess;
}
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
namespace CarFactoryLibrary {
namespace events {
class DeliveredCarConveyor;
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Actuators {
class ILargeMotor;
}
}
}
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class GoToPress;
}
}
namespace EV3PapyrusLibrary {
class IColorSensor;
}
namespace CarFactoryLibrary {
namespace events {
class CheckRack;
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
namespace CarFactoryLibrary {
namespace events {
class PressAssemble;
}
}

// End of Include stereotype (header)

namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class GoToPress;
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class PrepareConveyor;
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class StopProcess;
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Roof {

/************************************************************/
/**
 * 
 */
class RoofConvoyer: public ::CarFactoryLibrary::Conveyor {
public:
	/**
	 * the command to send to the motor to go from the stop position to wait car position (from the other module)
	 */
	static int wait_car_offset;
	/**
	 * the command to send to the motor to go from the stop position to wait car position (from the other module)
	 */
	static int take_car_offset;
	/**
	 * 
	 */
	static ::CarFactoryLibrary::Colors color;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::RoofRoofConvoyer__Controller roofconvoyerController;

	StateMachine RoofConveyorStateMachine {
		InitialState PrincipalState {
			InitialState GoInitialPosition {
				StateDoActivity go_initial_position;
			};
			State MoveForward {
				StateEntry move_forward;
			};
			State GoWaitPosition {
				StateEntry go_wait_position;
			};
			PseudoChoice Choice1;
			State Replace {
				StateEntry replace;
			};
			State DeliverCar {
				StateEntry deliver;
			};
			State SendEndOfModuleEvent {
				StateDoActivity sendEndOfModuleEvent;
			};
			State SendPressAssembleEvent {
				StateEntry sendPressAssembleEvent;
			};
			State GoCheckPresencePosition {
				StateEntry goCheckPresencePosition;
			};
			State SendReady {
				StateEntry send_ready;
			};
			PseudoChoice choice;
			State Misplace {
				StateEntry sendErrorDetectionEvent;
			};
		};
		State Restart;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::StopProcess> StopProcess;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> RestartAfterEmergencyStop;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor> PrepareConveyor;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::GoToPress> GoToPress;
		SignalEvent<CarFactoryLibrary::events::DeliveredCarConveyor> DeliveredCarConveyor;
		TransitionTable {
			//For external transtition: ExT(name, source, target, guard, event, effect)
			//For local transtition: LoT(name, source, target, guard, event, effect)
			//For internal transtition: ExT(name, source, guard, event, effect)
			ExT(fromPrincipalStatetoRestart , PrincipalState , Restart , NULL , StopProcess , effectFromPrincipalStatetoRestart );
			ExT(fromGoInitialPositiontoMoveForward , GoInitialPosition , MoveForward , NULL , PrepareConveyor , save_color );
			ExT(fromMoveForwardtoReplace , MoveForward , Replace , NULL , NULL , NULL );
			ExT(fromGoWaitPositiontoChoice1 , GoWaitPosition , Choice1 , NULL , GoToPress , save_color );
			ExT(fromReplacetoGoWaitPosition , Replace , GoWaitPosition , NULL , NULL , NULL );
			ExT(fromDeliverCartoSendEndOfModuleEvent , DeliverCar , SendEndOfModuleEvent , NULL , NULL , NULL );
			ExT(fromSendEndOfModuleEventtoGoInitialPosition , SendEndOfModuleEvent , GoInitialPosition , NULL , NULL , NULL );
			ExT(fromSendPressAssembleEventtoDeliverCar , SendPressAssembleEvent , DeliverCar , NULL , DeliveredCarConveyor , NULL );
			ExT(fromGoCheckPresencePositiontoChoice , GoCheckPresencePosition , choice , NULL , NULL , NULL );
			ExT(fromSendReadytoDeliverCar , SendReady , DeliverCar , NULL , DeliveredCarConveyor , NULL );
			ExT(fromMisplacetoRestart , Misplace , Restart , NULL , NULL , NULL );
			ExT(fromRestarttoPrincipalState , Restart , PrincipalState , NULL , RestartAfterEmergencyStop , NULL );
			ExT(fromChoice1toGoCheckPresencePosition , Choice1 , GoCheckPresencePosition , NULL , NULL , NULL );
			ExT(fromChoice1toSendReady , Choice1 , SendReady , fromChoice1toSendReadyGuard , NULL , NULL );
			ExT(fromChoicetoMisplace , choice , Misplace , fromChoicetoMisplaceGuard , NULL , NULL );
			ExT(fromChoicetoSendPressAssembleEvent , choice , SendPressAssembleEvent , NULL , NULL , NULL );
		}
	};
	/**
	 * 
	 */
	InFlowPort<LegoCarFactoryRefactoringForSync::signals::StopProcess> pInStopProcess;
	/**
	 * 
	 */
	InFlowPort<
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> pRestart;
	/**
	 * 
	 */
	InFlowPort<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor> pPrepare;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::DeliveredCarConveyor> pDelivered;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor> pLargeMotor;
	/**
	 * 
	 */
	InFlowPort<LegoCarFactoryRefactoringForSync::signals::GoToPress> pGotoProcess;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::CheckRack> pCheckRack;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::ErrorDetection> pErrDetect;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo_Control;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo_Shelf;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo_Robotic;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo_Press;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::PressAssemble> pPressAssemble;
	/**
	 * 
	 */
	void sendErrorDetectionEvent();
	/**
	 * 
	 */
	void take_car();
	/**
	 * 
	 */
	void go_wait_car();
	/**
	 * 
	 */
	RoofConvoyer();
	/**
	 * 
	 * @param sig 
	 */
	void effectFromPrincipalStatetoRestart(
			::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void save_color(
			::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void save_color(
			::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/sig);
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoice1toSendReadyGuard();
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoicetoMisplaceGuard();
	/**
	 * 
	 */
	void go_initial_position();
	/**
	 * 
	 */
	void move_forward();
	/**
	 * 
	 */
	void replace();
	/**
	 * 
	 */
	void deliver();
	/**
	 * 
	 */
	void sendEndOfModuleEvent();
	/**
	 * 
	 */
	void sendPressAssembleEvent();
	/**
	 * 
	 */
	void goCheckPresencePosition();
	/**
	 * 
	 */
	void send_ready();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Roof
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of RoofConvoyer class header
 ************************************************************/

#endif
