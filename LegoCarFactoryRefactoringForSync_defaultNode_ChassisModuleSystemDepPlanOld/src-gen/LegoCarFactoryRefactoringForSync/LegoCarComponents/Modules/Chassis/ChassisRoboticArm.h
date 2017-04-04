// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_CHASSIS_CHASSISROBOTICARM_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_CHASSIS_CHASSISROBOTICARM_H

/************************************************************
 ChassisRoboticArm class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/Pkg_Chassis.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/RoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ChassisChassisRoboticArm__Controller.h"

// Include from Include stereotype (header)

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/Pkg_Chassis.h"
#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/RoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ChassisChassisRoboticArm__Controller.h"
#include "unistd.h"
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
namespace CarFactoryLibrary {
namespace events {
class EndOfModule;
}
}
namespace CarFactoryLibrary {
namespace events {
class RoboticArmPickPiece;
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Actuators {
class IServoMotor;
}
}
}
namespace CarFactoryLibrary {
namespace events {
class DeliveredCarConveyor;
}
}

// End of Include stereotype (header)

namespace CarFactoryLibrary {
namespace events {
class RoboticArmPickPiece;
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
class ChassisRoboticArm: public ::CarFactoryLibrary::RoboticArm {
public:
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisRoboticArm__Controller chassisroboticarmController;

	StateMachine ChassisRoboticArmStateMachine {
		InitialState PrincipalState {
			State start_motors;
			State tip_up_chassis;
			State pick_chassis;
			State deliver_chassis;
			State SendDeliveredCarConveyorEvent;
			InitialState Initialization;
			State Finalization;
			PseudoChoice choice;
		};
		State Restart;
		FinalState FinalState1;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::StopProcess> StopProcess;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> RestartAfterEmergencyStop;
		SignalEvent<CarFactoryLibrary::events::RoboticArmPickPiece> RoboticArmPickPiece;
		SignalEvent<CarFactoryLibrary::events::EndOfModule> EndOfModule;
		TransitionTable {
			//For external transtition: ExT(name, source, target, guard, event, effect)
			//For local transtition: LoT(name, source, target, guard, event, effect)
			//For internal transtition: ExT(name, source, guard, event, effect)
			ExT(fromPrincipalStatetoRestart , PrincipalState , Restart , NULL , StopProcess , NULL );
			ExT(fromPrincipalStatetoFinalState1 , PrincipalState , FinalState1 , NULL , NULL , NULL );
			ExT(fromStart_motorstoTip_up_chassis , start_motors , tip_up_chassis , NULL , NULL , NULL );
			ExT(fromTip_up_chassistoPick_chassis , tip_up_chassis , pick_chassis , NULL , NULL , NULL );
			ExT(fromPick_chassistoDeliver_chassis , pick_chassis , deliver_chassis , NULL , NULL , NULL );
			ExT(fromDeliver_chassistoSendDeliveredCarConveyorEvent, deliver_chassis , SendDeliveredCarConveyorEvent , NULL , NULL , NULL );
			ExT(fromSendDeliveredCarConveyorEventtoFinalization , SendDeliveredCarConveyorEvent , Finalization , NULL , NULL , NULL );
			ExT(fromInitializationtoChoice , Initialization , choice , NULL , RoboticArmPickPiece , save_rack_number );
			ExT(fromFinalizationtoInitialization , Finalization , Initialization , NULL , EndOfModule , NULL );
			ExT(fromRestarttoPrincipalState , Restart , PrincipalState , NULL , RestartAfterEmergencyStop , NULL );
			ExT(fromChoicetoStart_motors , choice , start_motors , NULL , NULL , NULL );
			ExT(fromChoicetoSendDeliveredCarConveyorEvent , choice , SendDeliveredCarConveyorEvent , fromChoicetoSendDeliveredCarConveyorEventGuard , NULL , NULL );
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
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> pInRestart;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::RoboticArmPickPiece> pPickPiece;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::DeliveredCarConveyor> pDelivered;
	/**
	 * 
	 * @return ret 
	 */
	bool fromChoicetoSendDeliveredCarConveyorEventGuard();
	/**
	 * tip up the basket to drop the chassis
	 * @param rack_number 
	 */
	void tip_up_chassis(int /*in*/rack_number);
	/**
	 * pick the chassis on the basket
	 * @param rack_number 
	 */
	void pick_chassis(int /*in*/rack_number);
	/**
	 * delivered the chassis on the conveyor
	 */
	void deliver_chassis();
	/**
	 * 
	 */
	ChassisRoboticArm();
	/**
	 * 
	 * @param sig 
	 */
	void save_rack_number(
			::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig);

private:
	/**
	 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
	 * @return ret 
	 */
	int get_current_module();
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
 End of ChassisRoboticArm class header
 ************************************************************/

#endif
