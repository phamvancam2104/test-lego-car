// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_FRONT_FRONTROBOTICARM_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_FRONT_FRONTROBOTICARM_H

/************************************************************
 FrontRoboticArm class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/Pkg_Front.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/RoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/FrontFrontRoboticArm__Controller.h"

// Include from Include stereotype (header)
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
namespace CarFactoryLibrary {
namespace CommunicationInterfaces {
class IRoboticArmFloatMotor;
}
}
#include "CarFactoryLibrary/CommunicationInterfaces/IRoboticArmFloatMotor.h"
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
namespace Front {

/************************************************************/
/**
 * 
 */
class FrontRoboticArm: public ::CarFactoryLibrary::RoboticArm {
public:
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::FrontFrontRoboticArm__Controller frontroboticarmController;

	StateMachine FrontRoboticArmStateMachine {
		InitialState PrincipalState {
			InitialState Initialization {
				StateEntry init;
			};
			State StartMotors {
				StateEntry start_motors;
			};
			State PickFrontPart {
				StateEntry pick_front_part;
			};
			State DeliverFrontPart {
				StateEntry deliver_front_part;
			};
			State ReplaceFrontPart {
				StateEntry replace_front_part;
				StateDoActivity sendGoToPressEvent;
			};
			State Finalization {
				StateEntry stop_motors;
			};
		};
		State Restart;
		SignalEvent<CarFactoryLibrary::events::EndOfModule> EndOfModule;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::StopProcess> StopProcess;
		SignalEvent<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> RestartAfterEmergencyStop;
		SignalEvent<CarFactoryLibrary::events::RoboticArmPickPiece> RoboticArmPickPiece;
		TransitionTable {
			//For external transtition: ExT(name, source, target, guard, event, effect)
			//For local transtition: LoT(name, source, target, guard, event, effect)
			//For internal transtition: ExT(name, source, guard, event, effect)
			ExT(fromPrincipalStatetoRestart , PrincipalState , Restart , NULL , StopProcess , NULL );
			ExT(fromInitializationtoStartMotors , Initialization , StartMotors , NULL , RoboticArmPickPiece , save_rack_number );
			ExT(fromStartMotorstoPickFrontPart , StartMotors , PickFrontPart , NULL , NULL , NULL );
			ExT(fromPickFrontParttoDeliverFrontPart , PickFrontPart , DeliverFrontPart , NULL , NULL , NULL );
			ExT(fromDeliverFrontParttoReplaceFrontPart , DeliverFrontPart , ReplaceFrontPart , NULL , NULL , NULL );
			ExT(fromReplaceFrontParttoFinalization , ReplaceFrontPart , Finalization , NULL , NULL , NULL );
			ExT(fromFinalizationtoInitialization , Finalization , Initialization , NULL , EndOfModule , NULL );
			ExT(fromRestarttoPrincipalState , Restart , PrincipalState , NULL , RestartAfterEmergencyStop , NULL );
		}
	};
	/**
	 * 
	 */
	InOutFlowPort<LegoCarFactoryRefactoringForSync::signals::StopProcess> pStopProcess;
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
	ProvidedPort<
			CarFactoryLibrary::CommunicationInterfaces::IRoboticArmFloatMotor> pIFloatMotor;
	/**
	 * 
	 */
	OutFlowPort<CarFactoryLibrary::events::DeliveredCarConveyor> pDelivered;
	/**
	 * 
	 */
	void stop_motors();
	/**
	 * pick the front part on the rack numer "rack_number"
	 * @param rack_number 
	 */
	void pick_front_part(int /*in*/rack_number);
	/**
	 * put the front part on the chassis
	 */
	void deliver_front_part();
	/**
	 * replace the front part on the chassis
	 */
	void replace_front_part();
	/**
	 * 
	 * @param sig 
	 */
	void save_rack_number(
			::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig);
	/**
	 * 
	 */
	void init();
	/**
	 * 
	 */
	void start_motors();
	/**
	 * 
	 */
	void pick_front_part();
	/**
	 * 
	 */
	void deliver_front_part();
	/**
	 * 
	 */
	void replace_front_part();
	/**
	 * 
	 */
	void sendGoToPressEvent();
	/**
	 * 
	 */
	FrontRoboticArm();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Front
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of FrontRoboticArm class header
 ************************************************************/

#endif
