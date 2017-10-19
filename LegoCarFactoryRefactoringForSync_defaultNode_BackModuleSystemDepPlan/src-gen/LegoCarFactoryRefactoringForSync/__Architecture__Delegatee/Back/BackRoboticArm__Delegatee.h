// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_BACK_BACKROBOTICARM__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_BACK_BACKROBOTICARM__DELEGATEE_H

/************************************************************
 BackRoboticArm__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Back/Pkg_Back.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "pthread.h"
#include "statemachine/EventQueueAllocationConfiguration.h"
#include "statemachine/Pkg_statemachine.h"
#include "statemachine/StructForThread_t.h"

// Include from Include stereotype (header)
#define BACKROBOTICARM__DELEGATEE_TIME_EVENT_LOWER_BOUND (0)
#define BACKROBOTICARM__DELEGATEE_CHANGE_EVENT_LOWER_BOUND (0)
#define BACKROBOTICARM__DELEGATEE_TE_INDEX(id) (id - BACKROBOTICARM__DELEGATEE_TIME_EVENT_LOWER_BOUND)
#define BACKROBOTICARM__DELEGATEE_CHE_INDEX(id) (id - BACKROBOTICARM__DELEGATEE_CHANGE_EVENT_LOWER_BOUND)
#define BACKROBOTICARM_BACKROBOTICARMSTATEMACHINE_REGION1_DEFAULT (0)
#define BACKROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT (0)
#define BACKROBOTICARM_BACKROBOTICARMSTATEMACHINE_REGION1 (0)
#define BACKROBOTICARM_PRINCIPALSTATE_REGION1 (1)
#include "time.h"
#include "pthread.h"
//the termination of doActivity is implemented in terms of check points that the developers write
//fine-grained code to explicitly use check points to exit doActivity
#ifdef CHECKPOINT 
#undef CHECKPOINT
#endif
#define CHECKPOINT if (backroboticarmController.systemState == statemachine::EVENT_PROCESSING || backroboticarmController.systemState == statemachine::STOPPED) {return;}
#define BackRoboticArm__Delegatee_THREAD_CREATE(thThread, str) pthread_create(&thThread, NULL, &BackRoboticArm__Delegatee::thread_func_wrapper, &str);
#define BACKROBOTICARM__DELEGATEE_GET_CONTROL /*mutex synchronization to protect run-to-completion semantics*/ \
		while (!dispatchFlag) {} \
		pthread_mutex_lock(&runToCompletionMutex); \
		while (systemState != statemachine::IDLE || eventQueue.getCompletionSize() > 0) {\
			pthread_cond_wait(&runToCompletionCond, &runToCompletionMutex);\
		}
#define BACKROBOTICARM__DELEGATEE_RELEASE_CONTROL systemState = statemachine::IDLE; pthread_cond_signal(&runToCompletionCond); \
				pthread_mutex_unlock(&runToCompletionMutex);
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
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class StopProcess;
}
}
namespace CarFactoryLibrary {
namespace events {
class DeliveredCarConveyor;
}
}
namespace LegoCarFactoryRefactoringForSync {
namespace signals {
class GoToPress;
}
}
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Back;

// End of Include stereotype (header)

namespace CarFactoryLibrary {
class IModule;
}
namespace CarFactoryLibrary {
namespace CommunicationInterfaces {
class IRoboticArmFloatMotor;
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
namespace Back {
class BackRoboticArm;
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
namespace Back {

/************************************************************/
/**
 * 
 */
class BackRoboticArm__Delegatee: public IPush<
		LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>,
		public IPush<CarFactoryLibrary::events::EndOfModule>,
		public IPush<CarFactoryLibrary::events::RoboticArmPickPiece>,
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
		//void (BackRoboticArm__Delegatee::*entry)();
		//void (BackRoboticArm__Delegatee::*exit)();
		//void (BackRoboticArm__Delegatee::*doActivity)();
		State_t() {
			hasDoActivity = false;
			//entry = &BackRoboticArm__Delegatee::entry_dft;
			//exit = &BackRoboticArm__Delegatee::exit_dft;
			//doActivity = &BackRoboticArm__Delegatee::doActivity_dft;
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
		STARTMOTORS_ID,
		/**
		 * 
		 */
		PICKBACKPART_ID,
		/**
		 * 
		 */
		RETAKEBACKPART_ID,
		/**
		 * 
		 */
		DELIVERBACKPART_ID,
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
		ENDOFMODULE_ID,
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
		COMPLETIONEVENT_ID
	};
	/**
	 * 
	 */
	typedef void (BackRoboticArm__Delegatee::*FptPointer)();

	/**
	 * 
	 */
	::statemachine::SystemStateEnum_t systemState;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Back::BackRoboticArm__Delegatee::State_t states[8];
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Back::BackRoboticArm__Delegatee::StateIDEnum activeStateID;
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
	void BackRoboticArmStateMachine_Region1_Enter(char /*in*/enter_mode);
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
	BackRoboticArm__Delegatee();
	/**
	 * 
	 */
	void startBehavior();
	/**
	 * 
	 */
	~BackRoboticArm__Delegatee();
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
			::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Back::BackRoboticArm* /*in*/comp);
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
	virtual IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* get_pInStopProcess();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::CarFactoryLibrary::CommunicationInterfaces::IRoboticArmFloatMotor* get_pFloatMotor();
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
	virtual void connect_pOutGotoProcess(
			IPush<LegoCarFactoryRefactoringForSync::signals::GoToPress>* /*in*/ref);
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
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Back::BackRoboticArm* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Back
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of BackRoboticArm__Delegatee class header
 ************************************************************/

#endif