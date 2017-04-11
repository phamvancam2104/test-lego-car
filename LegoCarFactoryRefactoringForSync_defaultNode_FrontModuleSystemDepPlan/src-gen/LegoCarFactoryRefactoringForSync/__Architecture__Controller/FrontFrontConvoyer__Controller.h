// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_FRONTFRONTCONVOYER__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_FRONTFRONTCONVOYER__CONTROLLER_H

/************************************************************
 FrontFrontConvoyer__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "pthread.h"
#include "statemachine/EventPriorityQueue.h"
#include "statemachine/Event_t.h"
#include "statemachine/Pkg_statemachine.h"
#include "statemachine/StructForThread_t.h"

// Include from Include stereotype (header)
#define FRONTFRONTCONVOYER__CONTROLLER_TIME_EVENT_LOWER_BOUND (0)
#define FRONTFRONTCONVOYER__CONTROLLER_CHANGE_EVENT_LOWER_BOUND (0)
#define FRONTFRONTCONVOYER__CONTROLLER_TE_INDEX(id) (id - FRONTFRONTCONVOYER__CONTROLLER_TIME_EVENT_LOWER_BOUND)
#define FRONTFRONTCONVOYER__CONTROLLER_CHE_INDEX(id) (id - FRONTFRONTCONVOYER__CONTROLLER_CHANGE_EVENT_LOWER_BOUND)
#define FRONTCONVOYER_FRONTCONVEYORSTATEMACHINE_REGION1_DEFAULT (0)
#define FRONTCONVOYER_PRINCIPALSTATE_REGION1_DEFAULT (0)
#define FRONTCONVOYER_PRINCIPALSTATE_REGION1_GOINITIALPOSITION (1)
#define FRONTCONVOYER_FRONTCONVEYORSTATEMACHINE_REGION1 (0)
#define FRONTCONVOYER_PRINCIPALSTATE_REGION1 (1)
#include "time.h"
#include "pthread.h"
//the termination of doActivity is implemented in terms of check points that the developers write
//fine-grained code to explicitly use check points to exit doActivity
//#define CHECKPOINT if (systemState == statemachine::EVENT_PROCESSING || systemState == statemachine::STOPPED) {return;}
#define FrontFrontConvoyer__Controller_THREAD_CREATE(thThread, str) pthread_create(&thThread, NULL, &FrontFrontConvoyer__Controller::thread_func_wrapper, &str);
#define FRONTFRONTCONVOYER__CONTROLLER_GET_CONTROL /*mutex synchronization to protect run-to-completion semantics*/ \
		while (!dispatchFlag) {} \
		pthread_mutex_lock(&runToCompletionMutex); \
		while (systemState != statemachine::IDLE) {\
			pthread_cond_wait(&runToCompletionCond, &runToCompletionMutex);\
		}
#define FRONTFRONTCONVOYER__CONTROLLER_RELEASE_CONTROL systemState = statemachine::IDLE; pthread_cond_signal(&runToCompletionCond); \
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

namespace CarFactoryLibrary {
class IModule;
}
namespace CarFactoryLibrary {
namespace events {
class DeliveredCarConveyor;
}
}
namespace EV3PapyrusLibrary {
class IColorSensor;
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Actuators {
class ILargeMotor;
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
namespace Front {
class FrontConvoyer;
}
}
}
}
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
class FrontFrontConvoyer__Controller: public IPush<
		LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>,
		public IPush<CarFactoryLibrary::events::DeliveredCarConveyor>,
		public IPush<LegoCarFactoryRefactoringForSync::signals::GoToPress>,
		public IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>,
		public IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor> {
public:
	/**
	 * 
	 */
	typedef struct State_t {
		bool hasDoActivity;
		//1 is configured as the maximum number of orthogonal regions a composite states can have
		unsigned int actives[1];
		//void (FrontFrontConvoyer__Controller::*entry)();
		//void (FrontFrontConvoyer__Controller::*exit)();
		//void (FrontFrontConvoyer__Controller::*doActivity)();
		State_t() {
			hasDoActivity = false;
			//entry = &FrontFrontConvoyer__Controller::entry_dft;
			//exit = &FrontFrontConvoyer__Controller::exit_dft;
			//doActivity = &FrontFrontConvoyer__Controller::doActivity_dft;
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
		GOINITIALPOSITION_ID,
		/**
		 * 
		 */
		GOWAITPOSITION_ID,
		/**
		 * 
		 */
		REPLACE_ID,
		/**
		 * 
		 */
		GOCHECKPRESENCEPOSITION_ID,
		/**
		 * 
		 */
		MISPLACE_ID,
		/**
		 * 
		 */
		SENDPRESSASSEMBLEEVENT_ID,
		/**
		 * 
		 */
		DELIVERCAR_ID,
		/**
		 * 
		 */
		SENDENDOFMODULEEVENT_ID,
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
		DELIVEREDCARCONVEYOR_ID,
		/**
		 * 
		 */
		GOTOPRESS_ID,
		/**
		 * 
		 */
		STOPPROCESS_ID,
		/**
		 * 
		 */
		PREPARECONVEYOR_ID,
		/**
		 * 
		 */
		COMPLETIONEVENT_ID
	};
	/**
	 * 
	 */
	typedef void (FrontFrontConvoyer__Controller::*FptPointer)();

	/**
	 * 
	 */
	::statemachine::SystemStateEnum_t systemState;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::FrontFrontConvoyer__Controller::State_t states[10];
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::FrontFrontConvoyer__Controller::StateIDEnum activeStateID;
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
	void FrontConveyorStateMachine_Region1_Enter(char /*in*/enter_mode);
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
	FrontFrontConvoyer__Controller(
			::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Front::FrontConvoyer* /*in*/origin);
	/**
	 * 
	 */
	void startBehavior();
	/**
	 * 
	 */
	~FrontFrontConvoyer__Controller();
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
	void processDeliveredCarConveyor(
			::CarFactoryLibrary::events::DeliveredCarConveyor& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::CarFactoryLibrary::events::DeliveredCarConveyor& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void processGoToPress(
			::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(
			::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/sig);
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
	void processPrepareConveyor(
			::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(
			::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/sig);
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
			LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* get_pRestart();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>* get_pPrepare();
	/**
	 * 
	 * @return ret 
	 */
	virtual IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* get_pDelivered();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* get_pILargeMotor();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* get_pMotor();
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pCheckRack(
			IPush<CarFactoryLibrary::events::CheckRack>* /*in*/ref);
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
	virtual void connect_pEndOfMo_Control(
			IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pEndOfMo_Shelf(
			IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pEndOfMo_Robotic(
			IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pEndOfMo_Press(
			IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pOutAssemble(
			IPush<CarFactoryLibrary::events::PressAssemble>* /*in*/ref);
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
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Front::FrontConvoyer* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of FrontFrontConvoyer__Controller class header
 ************************************************************/

#endif
