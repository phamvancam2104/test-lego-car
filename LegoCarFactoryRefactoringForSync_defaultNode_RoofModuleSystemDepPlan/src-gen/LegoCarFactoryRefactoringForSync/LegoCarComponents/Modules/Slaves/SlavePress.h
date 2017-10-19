// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_SLAVES_SLAVEPRESS_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_SLAVES_SLAVEPRESS_H

/************************************************************
 SlavePress class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/Pkg_Slaves.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/Press.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Slaves/SlavePress__Delegatee.h"

// Include from Include stereotype (header)
using namespace CarFactoryLibrary;
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class StopProcess;
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
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class RestartAfterEmergencyStop;
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

// End of Include stereotype (header)

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Slaves {

/************************************************************/
/**
 * 
 */
class SlavePress: public ::CarFactoryLibrary::Press {
public:
	/**
	 * 
	 */
	int counter;
	DECLARE_DELEGATEE_COMPONENT (SlavePress)

	StateMachine SlavePressStateMachine {
		InitialState PrincipalState {
			State SetStatusIsReady {
				StateEntry SetStatusIsReady();
			};
			State LiftUp {
				StateEntry lift_up();
			};
			PseudoChoice choice {};
			State GoTopPress {
				StateEntry go_top();
			};
			State Press {
				StateDoActivity assemble ();
			};
			InitialState Initialization {
				StateEntry init();
			};
		};
		State Restart {
		};
		SignalEvent(CarFactoryLibrary::events::EndOfModule) EndOfModule;
		SignalEvent(CarFactoryLibrary::events::PressAssemble) PressAssemble;
		SignalEvent(LegoCarFactoryRefactoringForSync::signals::StopProcess) StopProcess;
		SignalEvent(LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop) RestartAfterEmergencyStop;
		TransitionTable {
			//using namespace for vertices
			//For external transtition: ExT(name, source, target, guard, event, effect)
			//For local transtition: LoT(name, source, target, guard, event, effect)
			//For internal transtition: ExT(name, source, guard, event, effect)
			ExT(fromPrincipalStatetoRestart, PrincipalState, Restart, NULL, StopProcess, NULL);
			ExT(fromSetStatusIsReadytoInitialization, SetStatusIsReady, Initialization, NULL, EndOfModule, NULL);
			ExT(fromLiftUptoChoice, LiftUp, choice, NULL, void, NULL);
			ExT(fromGoTopPresstoSetStatusIsReady, GoTopPress, SetStatusIsReady, NULL, void, NULL);
			ExT(fromPresstoLiftUp, Press, LiftUp, NULL, void, NULL);
			ExT(fromInitializationtoPress, Initialization, Press, NULL, PressAssemble, NULL);
			ExT(fromRestarttoPrincipalState, Restart, PrincipalState, NULL, RestartAfterEmergencyStop, NULL);
			ExT(fromChoicetoGoTopPress, choice, GoTopPress, fromChoicetoGoTopPressGuard, void, NULL);
			ExT(fromChoicetoPress, choice, Press, NULL, void, effectFromChoicetoPress);
		};
	};
	/**
	 * 
	 */
	InFlowPort<LegoCarFactoryRefactoringForSync::signals::StopProcess> pInStopProcess;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::EndOfModule> pEndOfMo;
	/**
	 * 
	 */
	InFlowPort<CarFactoryLibrary::events::PressAssemble> pPressAssemble;
	/**
	 * 
	 */
	InFlowPort<
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop> pInRestart;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor> pILargeMotor;
	/**
	 * 
	 */
	void init();
	/**
	 * 
	 */
	void effectFromChoicetoPress();
	/**
	 * 
	 * @return ret 
	 */
	bool ();
	/**
	 * 
	 */
	void SetStatusIsReady();
	/**
	 * 
	 */
	void lift_up();
	/**
	 * 
	 */
	void go_top();
	/**
	 * 
	 */
	void assemble();
	/**
	 * 
	 */
	SlavePress();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Slaves
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SlavePress class header
 ************************************************************/

#endif
