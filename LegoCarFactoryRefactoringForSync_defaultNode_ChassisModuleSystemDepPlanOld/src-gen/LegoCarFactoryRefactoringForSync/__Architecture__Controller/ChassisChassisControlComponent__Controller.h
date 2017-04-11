// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_H

/************************************************************
 ChassisChassisControlComponent__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "pthread.h"
#include "statemachine/EventPriorityQueue.h"
#include "statemachine/Event_t.h"
#include "statemachine/Pkg_statemachine.h"
#include "statemachine/StructForThread_t.h"

// Include from Include stereotype (header)
#define CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_TIME_EVENT_LOWER_BOUND (0)
#define CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_CHANGE_EVENT_LOWER_BOUND (1)
#define CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_TE_INDEX(id) (id - CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_TIME_EVENT_LOWER_BOUND)
#define CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_CHE_INDEX(id) (id - CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_CHANGE_EVENT_LOWER_BOUND)
#define CHASSISCONTROLCOMPONENT_CHASSISCONTROLSTATEMACHINE_REGION1_DEFAULT (0)
#define CHASSISCONTROLCOMPONENT_EMERGENCYSTOPSTATE_REGION1_DEFAULT (0)
#define CHASSISCONTROLCOMPONENT_CHASSISCONTROLSTATEMACHINE_REGION1 (0)
#define CHASSISCONTROLCOMPONENT_EMERGENCYSTOPSTATE_REGION1 (1)
#include "time.h"
#include "pthread.h"
#include "time.h"
#include "sys/time.h"
//the termination of doActivity is implemented in terms of check points that the developers write
//fine-grained code to explicitly use check points to exit doActivity
//#define CHECKPOINT if (systemState == statemachine::EVENT_PROCESSING || systemState == statemachine::STOPPED) {return;}
#define ChassisChassisControlComponent__Controller_THREAD_CREATE(thThread, str) pthread_create(&thThread, NULL, &ChassisChassisControlComponent__Controller::thread_func_wrapper, &str);
#define CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_GET_CONTROL /*mutex synchronization to protect run-to-completion semantics*/ \
		while (!dispatchFlag) {} \
		pthread_mutex_lock(&runToCompletionMutex); \
		while (systemState != statemachine::IDLE) {\
			pthread_cond_wait(&runToCompletionCond, &runToCompletionMutex);\
		}
#define CHASSISCHASSISCONTROLCOMPONENT__CONTROLLER_RELEASE_CONTROL systemState = statemachine::IDLE; pthread_cond_signal(&runToCompletionCond); \
				pthread_mutex_unlock(&runToCompletionMutex);
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
class IModule;
}
namespace CarFactoryLibrary {
namespace events {
class EndOfModule;
}
}
namespace CarFactoryLibrary {
namespace events {
class ErrorDetection;
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
class ChassisControlComponent;
}
}
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
class ChassisChassisControlComponent__Controller: public IPush<
		LegoCarFactoryRefactoringForSync::signals::StopProcess>, public IPush<
		CarFactoryLibrary::events::ErrorDetection>, public IPush<
		CarFactoryLibrary::events::EndOfModule> {
public:
	/**
	 * 
	 */
	typedef struct State_t {
		bool hasDoActivity;
		//1 is configured as the maximum number of orthogonal regions a composite states can have
		unsigned int actives[1];
		//void (ChassisChassisControlComponent__Controller::*entry)();
		//void (ChassisChassisControlComponent__Controller::*exit)();
		//void (ChassisChassisControlComponent__Controller::*doActivity)();
		State_t() {
			hasDoActivity = false;
			//entry = &ChassisChassisControlComponent__Controller::entry_dft;
			//exit = &ChassisChassisControlComponent__Controller::exit_dft;
			//doActivity = &ChassisChassisControlComponent__Controller::doActivity_dft;
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
		INITIALIZATION_ID,
		/**
		 * 
		 */
		MISPLACE_ID,
		/**
		 * 
		 */
		EMERGENCYSTOPSTATE_ID,
		/**
		 * 
		 */
		CHECKSTATE_ID,
		/**
		 * 
		 */
		STOPMOTORS_ID,
		/**
		 * 
		 */
		EMERGENCYBUTTONPRESSSTATE_ID,
		/**
		 * 
		 */
		EMERGENCYSTOPDISPLAY_ID,
		/**
		 * 
		 */
		SENDRESTARTEVENT_ID,
		/**
		 * 
		 */
		PREPARECONVEYOR_ID,
		/**
		 * 
		 */
		PLACEORDER_ID,
		/**
		 * 
		 */
		SENDSTOPMESSAGE_ID,
		/**
		 * 
		 */
		CHOOSEBACKFRONTORDER_ID,
		/**
		 * 
		 */
		STATE_MAX
	};
	/**
	 * 
	 */
	typedef void (ChassisChassisControlComponent__Controller::*FptPointer)();

	/**
	 * 
	 */
	enum EventId_t {
		/**
		 * 
		 */
		TE_50_MS__ID,
		/**
		 * 
		 */
		STOPPROCESS_ID,
		/**
		 * 
		 */
		ERRORDETECTION_ID,
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
	::statemachine::SystemStateEnum_t systemState;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisControlComponent__Controller::State_t states[12];
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisControlComponent__Controller::StateIDEnum activeStateID;
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
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisControlComponent__Controller::FptPointer timeEventTable[1];
	/**
	 * 
	 */
	pthread_t timeEventThreads[1];
	/**
	 * 
	 */
	bool timeEventFlags[1];
	/**
	 * 
	 */
	pthread_cond_t timeEventConds[1];
	/**
	 * 
	 */
	pthread_mutex_t timeEventMutexes[1];
	/**
	 * 
	 */
	::statemachine::StructForThread_t timeEventThreadStructs[1];
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
	void ChassisControlStateMachine_Region1_Enter(char /*in*/enter_mode);
	/**
	 * 
	 * @param enter_mode 
	 */
	void EmergencyStopState_Region1_Enter(char /*in*/enter_mode);
	/**
	 * 
	 */
	void EmergencyStopState_Region1_Exit();
	/**
	 * 
	 * @param origin 
	 */
	ChassisChassisControlComponent__Controller(
			::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent* /*in*/origin);
	/**
	 * 
	 */
	void startBehavior();
	/**
	 * 
	 */
	~ChassisChassisControlComponent__Controller();
	/**
	 * 
	 */
	void stopBehavior();
	/**
	 * 
	 */
	void processTE_50_ms_();
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
	void processErrorDetection(
			::CarFactoryLibrary::events::ErrorDetection& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::CarFactoryLibrary::events::ErrorDetection& /*in*/sig);
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
	 * @param id 
	 * @param duration 
	 */
	void listenTimeEvent(int /*in*/id, int /*in*/duration);
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* get_pOutStopProcess_Shelf();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* get_pStopProcess_Convoyer();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<CarFactoryLibrary::events::ErrorDetection>* get_pErrDetect();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<CarFactoryLibrary::events::EndOfModule>* get_pEndOfMo();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* get_pLCD();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::CarFactoryLibrary::IModule* get_pModule();
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pOutStopProcess_Shelf(
			IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pOutStopProcess_RoboticArm(
			IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pOutRestart_Shelf(
			IPush<
					LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pOutRestart_Convoyer(
			IPush<
					LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pPrepare(
			IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pOutRestart_Robotic(
			IPush<
					LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref);

private:
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisChassisControlComponent__Controller class header
 ************************************************************/

#endif
