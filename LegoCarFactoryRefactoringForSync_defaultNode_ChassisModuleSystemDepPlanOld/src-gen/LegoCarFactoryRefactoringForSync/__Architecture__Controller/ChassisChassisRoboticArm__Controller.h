// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CHASSISCHASSISROBOTICARM__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CHASSISCHASSISROBOTICARM__CONTROLLER_H

/************************************************************
 ChassisChassisRoboticArm__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "pthread.h"
#include "statemachine/EventPriorityQueue.h"
#include "statemachine/Event_t.h"
#include "statemachine/Pkg_statemachine.h"
#include "statemachine/StructForThread_t.h"

// Include from Include stereotype (header)
#define CHASSISCHASSISROBOTICARM__CONTROLLER_TIME_EVENT_LOWER_BOUND (0)
#define CHASSISCHASSISROBOTICARM__CONTROLLER_CHANGE_EVENT_LOWER_BOUND (0)
#define CHASSISCHASSISROBOTICARM__CONTROLLER_TE_INDEX(id) (id - CHASSISCHASSISROBOTICARM__CONTROLLER_TIME_EVENT_LOWER_BOUND)
#define CHASSISCHASSISROBOTICARM__CONTROLLER_CHE_INDEX(id) (id - CHASSISCHASSISROBOTICARM__CONTROLLER_CHANGE_EVENT_LOWER_BOUND)
#define CHASSISROBOTICARM_CHASSISROBOTICARMSTATEMACHINE_REGION1_DEFAULT (0)
#define CHASSISROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT (0)
#define CHASSISROBOTICARM_PRINCIPALSTATE_REGION1_INITIALIZATION (1)
#define CHASSISROBOTICARM_CHASSISROBOTICARMSTATEMACHINE_REGION1 (0)
#define CHASSISROBOTICARM_PRINCIPALSTATE_REGION1 (1)
#include "time.h"
#include "pthread.h"
//the termination of doActivity is implemented in terms of check points that the developers write
//fine-grained code to explicitly use check points to exit doActivity
//#define CHECKPOINT if (systemState == statemachine::EVENT_PROCESSING || systemState == statemachine::STOPPED) {return;}
#define ChassisChassisRoboticArm__Controller_THREAD_CREATE(thThread, str) pthread_create(&thThread, NULL, &ChassisChassisRoboticArm__Controller::thread_func_wrapper, &str);
#define CHASSISCHASSISROBOTICARM__CONTROLLER_GET_CONTROL /*mutex synchronization to protect run-to-completion semantics*/ \
		while (!dispatchFlag) {} \
		pthread_mutex_lock(&runToCompletionMutex); \
		while (systemState != statemachine::IDLE) {\
			pthread_cond_wait(&runToCompletionCond, &runToCompletionMutex);\
		}
#define CHASSISCHASSISROBOTICARM__CONTROLLER_RELEASE_CONTROL systemState = statemachine::IDLE; pthread_cond_signal(&runToCompletionCond); \
				pthread_mutex_unlock(&runToCompletionMutex);
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
namespace events {
class DeliveredCarConveyor;
}
}

// End of Include stereotype (header)

namespace CarFactoryLibrary {
class IModule;
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
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILcd;
}
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Chassis {
class ChassisRoboticArm;
}
}
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class RestartAfterEmergencyStop;
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class StopProcess;
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class ChassisChassisRoboticArm__Controller: public IPush<
		LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>,
		public IPush<CarFactoryLibrary::events::RoboticArmPickPiece>,
		public IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>,
		public IPush<CarFactoryLibrary::events::EndOfModule> {
public:
	/**
	 * 
	 */
	typedef struct State_t {
		bool hasDoActivity;
		//1 is configured as the maximum number of orthogonal regions a composite states can have
		unsigned int actives[1];
		//void (ChassisChassisRoboticArm__Controller::*entry)();
		//void (ChassisChassisRoboticArm__Controller::*exit)();
		//void (ChassisChassisRoboticArm__Controller::*doActivity)();
		State_t() {
			hasDoActivity = false;
			//entry = &ChassisChassisRoboticArm__Controller::entry_dft;
			//exit = &ChassisChassisRoboticArm__Controller::exit_dft;
			//doActivity = &ChassisChassisRoboticArm__Controller::doActivity_dft;
			for (int i = 0; i < 1; i++) {

				actives[i] = STATE_MAX;
			}
		}
	} State_t;

	/**
	 * 
	 */
	enum StateIDEnum {
		/**
		 * 
		 */
		PRINCIPALSTATE_ID,
		/**
		 * 
		 */
		INITIALIZATION_ID,
		/**
		 * 
		 */
		START_MOTORS_ID,
		/**
		 * 
		 */
		TIP_UP_CHASSIS_ID,
		/**
		 * 
		 */
		PICK_CHASSIS_ID,
		/**
		 * 
		 */
		DELIVER_CHASSIS_ID,
		/**
		 * 
		 */
		SENDDELIVEREDCARCONVEYOREVENT_ID,
		/**
		 * 
		 */
		FINALIZATION_ID,
		/**
		 * 
		 */
		RESTART_ID,
		/**
		 * 
		 */
		STATE_MAX
	};
	/**
	 * 
	 */
	enum EventId_t {
		/**
		 * 
		 */
		RESTARTAFTEREMERGENCYSTOP_ID,
		/**
		 * 
		 */
		ROBOTICARMPICKPIECE_ID,
		/**
		 * 
		 */
		STOPPROCESS_ID,
		/**
		 * 
		 */
		ENDOFMODULE_ID,
		/**
		 * 
		 */
		COMPLETIONEVENT_ID
	};
	/**
	 * 
	 */
	typedef void (ChassisChassisRoboticArm__Controller::*FptPointer)();

	/**
	 * 
	 */
	::statemachine::SystemStateEnum_t systemState;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisRoboticArm__Controller::State_t states[9];
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisRoboticArm__Controller::StateIDEnum activeStateID;
	/**
	 * 
	 */
	::statemachine::EventPriorityQueue eventQueue;
	/**
	 * 
	 */
	::statemachine::Event_t* currentEvent;
	/**
	 * 
	 */
	::statemachine::Event_t eventArray[50];
	/**
	 * 
	 */
	bool dispatchFlag;
	/**
	 * 
	 */
	pthread_t threads[STATE_MAX];
	/**
	 * 
	 */
	bool flags[STATE_MAX];
	/**
	 * 
	 */
	pthread_cond_t conds[STATE_MAX];
	/**
	 * 
	 */
	pthread_mutex_t mutexes[STATE_MAX];
	/**
	 * 
	 */
	::statemachine::StructForThread_t threadStructs[STATE_MAX];
	/**
	 * 
	 */
	pthread_t dispatchThread;
	/**
	 * 
	 */
	::statemachine::StructForThread_t dispatchStruct;
	/**
	 * 
	 */
	pthread_mutex_t runToCompletionMutex;
	/**
	 * 
	 */
	pthread_cond_t runToCompletionCond;
	/**
	 * 
	 */
	void dispatchEvent();
	/**
	 * 
	 * @param enter_mode 
	 */
	void ChassisRoboticArmStateMachine_Region1_Enter(char /*in*/enter_mode);
	/**
	 * 
	 * @param enter_mode 
	 */
	void PrincipalState_Region1_Enter(char /*in*/enter_mode);
	/**
	 * 
	 */
	void PrincipalState_Region1_Exit();
	/**
	 * 
	 * @param origin 
	 */
	ChassisChassisRoboticArm__Controller(
			::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm* /*in*/origin);
	/**
	 * 
	 */
	void startBehavior();
	/**
	 * 
	 */
	~ChassisChassisRoboticArm__Controller();
	/**
	 * 
	 */
	void stopBehavior();
	/**
	 * 
	 * @param sig 
	 */
	void processRestartAfterEmergencyStop(
			::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(
			::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void processRoboticArmPickPiece(
			::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void processStopProcess(
			::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(
			::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void processEndOfModule(
			::CarFactoryLibrary::events::EndOfModule& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::CarFactoryLibrary::events::EndOfModule& /*in*/sig);
	/**
	 * 
	 */
	void processCompletionEvent();
	/**
	 * 
	 * @param id 
	 */
	void StateEntry(unsigned int /*in*/id);
	/**
	 * 
	 * @param id 
	 */
	void StateExit(unsigned int /*in*/id);
	/**
	 * 
	 * @param id 
	 */
	void StateDoActivity(unsigned int /*in*/id);
	/**
	 * 
	 * @param data 
	 * @return ret 
	 */
	static void* thread_func_wrapper(void* /*in*/data);
	/**
	 * 
	 * @param id 
	 */
	void doCallActivity(int /*in*/id);
	/**
	 * 
	 * @param id 
	 * @param func_type 
	 * @param value 
	 */
	void setFlag(int /*in*/id, char /*in*/func_type, bool /*in*/value);
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* get_pInStopProcess();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* get_pInRestart();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<CarFactoryLibrary::events::EndOfModule>* get_pEndOfMo();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* get_pPickPiece();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* get_upDownMotor();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* get_frontBackMotor();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* get_rightLeftMotor();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* get_plierMotor();
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pDelivered(
			IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	void connect_pLCD(
			::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	void connect_pModule(::CarFactoryLibrary::IModule* /*in*/ref);

private:
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisChassisRoboticArm__Controller class header
 ************************************************************/

#endif
