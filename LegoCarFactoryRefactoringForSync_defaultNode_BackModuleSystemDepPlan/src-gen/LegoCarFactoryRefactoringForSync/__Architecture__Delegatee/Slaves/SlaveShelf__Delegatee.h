// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_SLAVES_SLAVESHELF__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_SLAVES_SLAVESHELF__DELEGATEE_H

/************************************************************
 SlaveShelf__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Slaves/Pkg_Slaves.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "pthread.h"
#include "statemachine/EventQueueAllocationConfiguration.h"
#include "statemachine/Pkg_statemachine.h"
#include "statemachine/StructForThread_t.h"

// Include from Include stereotype (header)
#define SLAVESHELF__DELEGATEE_TIME_EVENT_LOWER_BOUND (0)
#define SLAVESHELF__DELEGATEE_CHANGE_EVENT_LOWER_BOUND (0)
#define SLAVESHELF__DELEGATEE_TE_INDEX(id) (id - SLAVESHELF__DELEGATEE_TIME_EVENT_LOWER_BOUND)
#define SLAVESHELF__DELEGATEE_CHE_INDEX(id) (id - SLAVESHELF__DELEGATEE_CHANGE_EVENT_LOWER_BOUND)
#define SLAVESHELF_SLAVESHELFSTATEMACHINE_REGION1_DEFAULT (0)
#define SLAVESHELF_PRINCIPALSTATE_REGION1_DEFAULT (0)
#define SLAVESHELF_PRINCIPALSTATE_REGION1_WHICH_RACK (1)
#define SLAVESHELF_PRINCIPALSTATE_REGION1_INITIALIZATION (2)
#define SLAVESHELF_PRINCIPALSTATE_REGION1_EMPTYRACK (3)
#define SLAVESHELF_PRINCIPALSTATE_REGION1_NOEMPTYRACK (4)
#define SLAVESHELF_PRINCIPALSTATE_REGION1_WAITEND (5)
#define SLAVESHELF_SLAVESHELFSTATEMACHINE_REGION1 (0)
#define SLAVESHELF_PRINCIPALSTATE_REGION1 (1)
#include "time.h"
#include "pthread.h"
//the termination of doActivity is implemented in terms of check points that the developers write
//fine-grained code to explicitly use check points to exit doActivity
#ifdef CHECKPOINT 
#undef CHECKPOINT
#endif
#define CHECKPOINT if (slaveshelfController.systemState == statemachine::EVENT_PROCESSING || slaveshelfController.systemState == statemachine::STOPPED) {return;}
#define SlaveShelf__Delegatee_THREAD_CREATE(thThread, str) pthread_create(&thThread, NULL, &SlaveShelf__Delegatee::thread_func_wrapper, &str);
#define SLAVESHELF__DELEGATEE_GET_CONTROL /*mutex synchronization to protect run-to-completion semantics*/ \
		while (!dispatchFlag) {} \
		pthread_mutex_lock(&runToCompletionMutex); \
		while (systemState != statemachine::IDLE || eventQueue.getCompletionSize() > 0) {\
			pthread_cond_wait(&runToCompletionCond, &runToCompletionMutex);\
		}
#define SLAVESHELF__DELEGATEE_RELEASE_CONTROL systemState = statemachine::IDLE; pthread_cond_signal(&runToCompletionCond); \
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
class CheckRack;
}
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
namespace CarFactoryLibrary {
namespace events {
class RoboticArmPickPiece;
}
}
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Slaves;

// End of Include stereotype (header)

namespace CarFactoryLibrary {
class IModule;
}
namespace CarFactoryLibrary {
namespace events {
class CheckRack;
}
}
namespace CarFactoryLibrary {
namespace events {
class EndOfModule;
}
}
namespace EV3PapyrusLibrary {
class IColorSensor;
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
namespace Slaves {
class SlaveShelf;
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
namespace __Architecture__Delegatee {
namespace Slaves {

/************************************************************/
/**
 * 
 */
class SlaveShelf__Delegatee: public IPush<CarFactoryLibrary::events::CheckRack>,
		public IPush<CarFactoryLibrary::events::EndOfModule>,
		public IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>,
		public IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>,
		public ::statemachine::EventQueueAllocationConfiguration {
public:
	/**
	 * 
	 */
	typedef struct State_t {
		bool hasDoActivity;
		//1 is configured as the maximum number of orthogonal regions a composite states can have
		unsigned int actives[1];
		//void (SlaveShelf__Delegatee::*entry)();
		//void (SlaveShelf__Delegatee::*exit)();
		//void (SlaveShelf__Delegatee::*doActivity)();
		State_t() {
			hasDoActivity = false;
			//entry = &SlaveShelf__Delegatee::entry_dft;
			//exit = &SlaveShelf__Delegatee::exit_dft;
			//doActivity = &SlaveShelf__Delegatee::doActivity_dft;
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
		EMPTYRACK_ID,
		/**
		 * 
		 */
		NOEMPTYRACK_ID,
		/**
		 * 
		 */
		WAITEND_ID,
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
		CHECKRACK_ID,
		/**
		 * 
		 */
		ENDOFMODULE_ID,
		/**
		 * 
		 */
		RESTARTAFTEREMERGENCYSTOP_ID,
		/**
		 * 
		 */
		STOPPROCESS_ID,
		/**
		 * 
		 */
		COMPLETIONEVENT_ID
	};
	/**
	 * 
	 */
	typedef void (SlaveShelf__Delegatee::*FptPointer)();

	/**
	 * 
	 */
	::statemachine::SystemStateEnum_t systemState;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Slaves::SlaveShelf__Delegatee::State_t states[6];
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Slaves::SlaveShelf__Delegatee::StateIDEnum activeStateID;
	/**
	 * 
	 */
	int Which_rack_CompletionEvent;
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
	void SlaveShelfStateMachine_Region1_Enter(char /*in*/enter_mode);
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
	 */
	SlaveShelf__Delegatee();
	/**
	 * 
	 */
	void startBehavior();
	/**
	 * 
	 */
	~SlaveShelf__Delegatee();
	/**
	 * 
	 */
	void stopBehavior();
	/**
	 * 
	 * @param sig 
	 */
	void processCheckRack(::CarFactoryLibrary::events::CheckRack& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::CarFactoryLibrary::events::CheckRack& /*in*/sig);
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
	 * @param comp 
	 */
	void setComponent(
			::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Slaves::SlaveShelf* /*in*/comp);
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
	virtual IPush<CarFactoryLibrary::events::CheckRack>* get_pCheckRack();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<CarFactoryLibrary::events::EndOfModule>* get_pEndOfMo();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor1();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor2();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor3();
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pErrDetect(
			IPush<CarFactoryLibrary::events::ErrorDetection>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pPickPiece(
			IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* /*in*/ref);
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
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Slaves::SlaveShelf* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Slaves
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SlaveShelf__Delegatee class header
 ************************************************************/

#endif