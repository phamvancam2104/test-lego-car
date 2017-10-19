// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_CHASSIS_CHASSISCONVOYER__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_CHASSIS_CHASSISCONVOYER__DELEGATEE_H

/************************************************************
              ChassisConvoyer__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Chassis/Pkg_Chassis.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "pthread.h"
#include "statemachine/EventQueueAllocationConfiguration.h"
#include "statemachine/Pkg_statemachine.h"
#include "statemachine/StructForThread_t.h"

// Include from Include stereotype (header)
#define CHASSISCONVOYER__DELEGATEE_TIME_EVENT_LOWER_BOUND (0)
#define CHASSISCONVOYER__DELEGATEE_CHANGE_EVENT_LOWER_BOUND (0)
#define CHASSISCONVOYER__DELEGATEE_TE_INDEX(id) (id - CHASSISCONVOYER__DELEGATEE_TIME_EVENT_LOWER_BOUND)
#define CHASSISCONVOYER__DELEGATEE_CHE_INDEX(id) (id - CHASSISCONVOYER__DELEGATEE_CHANGE_EVENT_LOWER_BOUND)
#define CHASSISCONVOYER_CHASSISCONVEYORSTATEMACHINE_REGION1_DEFAULT (0)
#define CHASSISCONVOYER_PRINCIPALSTATE_REGION1_DEFAULT (0)
#define CHASSISCONVOYER_CHASSISCONVEYORSTATEMACHINE_REGION1 (0)
#define CHASSISCONVOYER_PRINCIPALSTATE_REGION1 (1)
#include "time.h"
#include "pthread.h"
//the termination of doActivity is implemented in terms of check points that the developers write
//fine-grained code to explicitly use check points to exit doActivity
#ifdef CHECKPOINT 
#undef CHECKPOINT
#endif
#define CHECKPOINT if (chassisconvoyerController.systemState == statemachine::EVENT_PROCESSING || chassisconvoyerController.systemState == statemachine::STOPPED) {return;}
#define ChassisConvoyer__Delegatee_THREAD_CREATE(thThread, str) pthread_create(&thThread, NULL, &ChassisConvoyer__Delegatee::thread_func_wrapper, &str);
#define CHASSISCONVOYER__DELEGATEE_GET_CONTROL /*mutex synchronization to protect run-to-completion semantics*/ \
		while (!dispatchFlag) {} \
		pthread_mutex_lock(&runToCompletionMutex); \
		while (systemState != statemachine::IDLE || eventQueue.getCompletionSize() > 0) {\
			pthread_cond_wait(&runToCompletionCond, &runToCompletionMutex);\
		}
#define CHASSISCONVOYER__DELEGATEE_RELEASE_CONTROL systemState = statemachine::IDLE; pthread_cond_signal(&runToCompletionCond); \
				pthread_mutex_unlock(&runToCompletionMutex);
namespace LegoCarFactoryRefactoringForSync {namespace signals {class StopProcess;}}
namespace LegoCarFactoryRefactoringForSync {namespace signals {class RestartAfterEmergencyStop;}}
namespace LegoCarFactoryRefactoringForSync {namespace signals {class PrepareConveyor;}}
namespace CarFactoryLibrary {namespace events {class DeliveredCarConveyor;}}
namespace CarFactoryLibrary {namespace events {class CheckRack;}}
namespace CarFactoryLibrary {namespace events {class ErrorDetection;}}
namespace CarFactoryLibrary {namespace events {class EndOfModule;}}
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Chassis;

// End of Include stereotype (header)

namespace CarFactoryLibrary {class IModule;}
namespace CarFactoryLibrary {namespace events {class DeliveredCarConveyor;}}
namespace EV3PapyrusLibrary {class IColorSensor;}
namespace EV3PapyrusLibrary {namespace Interfaces {namespace Actuators {class ILargeMotor;}}}
namespace EV3PapyrusLibrary {namespace Interfaces {namespace EV3Brick {class ILcd;}}}
namespace LegoCarFactoryRefactoringForSync {namespace LegoCarComponents {namespace Modules {namespace Chassis {class ChassisConvoyer;}}}}
namespace LegoCarFactoryRefactoringForSync {namespace signals {class PrepareConveyor;}}
namespace LegoCarFactoryRefactoringForSync {namespace signals {class RestartAfterEmergencyStop;}}
namespace LegoCarFactoryRefactoringForSync {namespace signals {class StopProcess;}}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Chassis {

/************************************************************/
/**
 * 
 */
class ChassisConvoyer__Delegatee : 
public IPush<CarFactoryLibrary::events::DeliveredCarConveyor>, 
public IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>, 
public IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>, 
public IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>, 
public ::statemachine::EventQueueAllocationConfiguration	
 {
    public:
    /**
     * 
     */
    typedef struct State_t {
    	bool hasDoActivity;
    	//1 is configured as the maximum number of orthogonal regions a composite states can have
    	unsigned int actives[1];
    	//void (ChassisConvoyer__Delegatee::*entry)();
    	//void (ChassisConvoyer__Delegatee::*exit)();
    	//void (ChassisConvoyer__Delegatee::*doActivity)();
    	State_t() {
    		hasDoActivity = false;
    		//entry = &ChassisConvoyer__Delegatee::entry_dft;
    		//exit = &ChassisConvoyer__Delegatee::exit_dft;
    		//doActivity = &ChassisConvoyer__Delegatee::doActivity_dft;
    		for(int i = 0; i < 1; i++) {
    			
    			actives[i] = STATE_MAX;
    		}
    	}
    } 
    	State_t;
    	
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
    	GO_STOP_POSITION_ID,
    	/**
    	 * 
    	 */
    	REPLACE_ID,
    	/**
    	 * 
    	 */
    	GO_CHECK_PRESENCE_POSITION_ID,
    	/**
    	 * 
    	 */
    	DELIVER_CAR_ID,
    	/**
    	 * 
    	 */
    	SENDENDOFMODULEEVENT_ID,
    	/**
    	 * 
    	 */
    	SENDLOADCARCOMMAND_ID,
    	/**
    	 * 
    	 */
    	WAITSLAVEISNOTBUSY_ID,
    	/**
    	 * 
    	 */
    	GO_WAIT_POSITION_ID,
    	/**
    	 * 
    	 */
    	REWIND_ID,
    	/**
    	 * 
    	 */
    	SENDDELIVERCOMMAND_ID,
    	/**
    	 * 
    	 */
    	WAITSLAVEISNOTBUSY2_ID,
    	/**
    	 * 
    	 */
    	MISPLACE_ID,
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
    	DELIVEREDCARCONVEYOR_ID,
    	/**
    	 * 
    	 */
    	STOPPROCESS_ID,
    	/**
    	 * 
    	 */
    	RESTARTAFTEREMERGENCYSTOP_ID,
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
    typedef void (ChassisConvoyer__Delegatee::*FptPointer)()
    	;
    	
	/**
	 * 
	 */
	 ::statemachine::SystemStateEnum_t systemState;
	/**
	 * 
	 */
	 ::LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Chassis::ChassisConvoyer__Delegatee::State_t states[14];
	/**
	 * 
	 */
	 ::LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Chassis::ChassisConvoyer__Delegatee::StateIDEnum activeStateID;
	/**
	 * 
	 */
	 bool dispatchFlag;
	/**
	 * 
	 */
	 int choice1_CompletionEvent;
	/**
	 * 
	 */
	 int choice0_CompletionEvent;
	/**
	 * 
	 */
	 int choice2_CompletionEvent;
	/**
	 * 
	 */
	 int choice3_CompletionEvent;
	/**
	 * 
	 */
	 int choice_CompletionEvent;
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
	void ChassisConveyorStateMachine_Region1_Enter(char /*in*/ enter_mode);
	/**
	 * 
	 * @param enter_mode 
	 */
	void PrincipalState_Region1_Enter(char /*in*/ enter_mode);
	/**
	 * 
	 */
	void PrincipalState_Region1_Exit();
	/**
	 * 
	 */
	ChassisConvoyer__Delegatee();
	/**
	 * 
	 */
	void startBehavior();
	/**
	 * 
	 */
	~ChassisConvoyer__Delegatee();
	/**
	 * 
	 */
	void stopBehavior();
	/**
	 * 
	 * @param sig 
	 */
	void processDeliveredCarConveyor(::CarFactoryLibrary::events::DeliveredCarConveyor& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::CarFactoryLibrary::events::DeliveredCarConveyor& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void processStopProcess(::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void processRestartAfterEmergencyStop(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void processPrepareConveyor(::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/ sig);
	/**
	 * 
	 * @param sig 
	 */
	void push(::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/ sig);
	/**
	 * 
	 */
	void processCompletionEvent();
	/**
	 * 
	 * @param id 
	 */
	void StateEntry(unsigned int /*in*/ id);
	/**
	 * 
	 * @param id 
	 */
	void StateExit(unsigned int /*in*/ id);
	/**
	 * 
	 * @param id 
	 */
	void StateDoActivity(unsigned int /*in*/ id);
	/**
	 * 
	 * @param data 
	 * @return ret 
	 */
	static  void* thread_func_wrapper(void* /*in*/ data);
	/**
	 * 
	 * @param id 
	 */
	void doCallActivity(int /*in*/ id);
	/**
	 * 
	 * @param id 
	 * @param func_type 
	 * @param value 
	 */
	void setFlag(int /*in*/ id, char /*in*/ func_type, bool /*in*/ value);
	/**
	 * 
	 * @param comp 
	 */
	void setComponent(::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer* /*in*/ comp);
	/**
	 * 
	 * @return ret 
	 */
	virtual  IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* get_pStopProcess();
	/**
	 * 
	 * @return ret 
	 */
	virtual  IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* get_pRestart();
	/**
	 * 
	 * @return ret 
	 */
	virtual  IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>* get_pPrepare();
	/**
	 * 
	 * @return ret 
	 */
	virtual  IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* get_pDelivered();
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::IColorSensor* get_sensor();
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* get_pMotor();
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pStopProcess(IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pCheckRack(IPush<CarFactoryLibrary::events::CheckRack>* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pErrDetect(IPush<CarFactoryLibrary::events::ErrorDetection>* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pEndOfMo_Control(IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pEndOfMo_Shelf(IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	virtual void connect_pEndOfMo_Robotic(IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	void connect_pLCD(::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ ref);
	/**
	 * 
	 * @param ref 
	 */
	void connect_pModule(::CarFactoryLibrary::IModule* /*in*/ ref);


	private:
	/**
	 * 
	 */
	 ::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace Chassis
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of ChassisConvoyer__Delegatee class header
 ************************************************************/

#endif
