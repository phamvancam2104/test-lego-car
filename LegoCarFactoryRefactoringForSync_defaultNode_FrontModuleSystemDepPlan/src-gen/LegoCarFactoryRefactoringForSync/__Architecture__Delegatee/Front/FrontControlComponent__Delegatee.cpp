// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_Front_FrontControlComponent__Delegatee_BODY

/************************************************************
 FrontControlComponent__Delegatee class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Front/FrontControlComponent__Delegatee.h"

// Derived includes directives
#include "CarFactoryLibrary/CommunicationInterfaces/IRoboticArmFloatMotor.h"
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/FrontControlComponent.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Front {

// static attributes (if any)

/**
 * 
 */
void FrontControlComponent__Delegatee::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	FrontControlStateMachine_Region1_Enter (FRONTCONTROLCOMPONENT_FRONTCONTROLSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			FRONTCONTROLCOMPONENT__DELEGATEE_GET_CONTROL
			switch (currentEvent->eventID) {
			case TE_50_MS__ID:
				processTE_50_ms_();
				break;
			case ENDOFMODULE_ID:
				::CarFactoryLibrary::events::EndOfModule sig_ENDOFMODULE_ID;
				memcpy(&sig_ENDOFMODULE_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::EndOfModule));
				processEndOfModule(sig_ENDOFMODULE_ID);
				break;
			case ERRORDETECTION_ID:
				::CarFactoryLibrary::events::ErrorDetection sig_ERRORDETECTION_ID;
				memcpy(&sig_ERRORDETECTION_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::ErrorDetection));
				processErrorDetection(sig_ERRORDETECTION_ID);
				break;
			case COMPLETIONEVENT_ID:
				processCompletionEvent();
				break;
			}
			if (systemState == statemachine::EVENT_DEFERRED) {
				eventQueue.saveDeferred(*currentEvent);
			}
			popDeferred = (systemState != statemachine::EVENT_DEFERRED);
			systemState = statemachine::IDLE;
			FRONTCONTROLCOMPONENT__DELEGATEE_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void FrontControlComponent__Delegatee::FrontControlStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case FRONTCONTROLCOMPONENT_FRONTCONTROLSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = INITIALIZATION_ID;

		(this->StateEntry)(INITIALIZATION_ID);
		;
		//starting the counters for time events

		//start activity of Initialization by calling setFlag
		setFlag(INITIALIZATION_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void FrontControlComponent__Delegatee::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION1_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[0] = EMNERGENCYSTOPSTATE_ID;

		EmnergencyStopState_Region1_Enter (FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void FrontControlComponent__Delegatee::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] == EMNERGENCYSTOPSTATE_ID) {
		EmnergencyStopState_Region1_Exit();
	}
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (EMNERGENCYSTOPSTATE_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (MISPLACE_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (SHOWSTOPGUI_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (RESTART_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		}
		//exit action of sub-state of PrincipalState
		StateExit(states[PRINCIPALSTATE_ID].actives[0]);
		//set active sub-state of PrincipalState to STATE_MAX meaning NULL
		states[PRINCIPALSTATE_ID].actives[0] = STATE_MAX;
	}
}

/**
 * 
 * @param enter_mode 
 */
void FrontControlComponent__Delegatee::EmnergencyStopState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT:
		states[EMNERGENCYSTOPSTATE_ID].actives[0] = CHECK_ID;

		//start activity of Check by calling setFlag
		setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_CHECK:
		states[EMNERGENCYSTOPSTATE_ID].actives[0] = CHECK_ID;
		//starting the counters for time events
		//start activity of Check by calling setFlag
		setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_WAIT:
		if (component->()) {
			states[EMNERGENCYSTOPSTATE_ID].actives[0] = EMERGENCYBUTTONPRESS_ID;
			(this->StateEntry)(EMERGENCYBUTTONPRESS_ID);
			;
			//starting the counters for time events
			//start activity of EmergencyButtonPress by calling setFlag
			setFlag(EMERGENCYBUTTONPRESS_ID, statemachine::TF_DO_ACTIVITY,
					true);
		} else {
			states[EMNERGENCYSTOPSTATE_ID].actives[0] = CHECK_ID;
			//starting the counters for time events
			//start activity of Check by calling setFlag
			setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, true);
		}
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_EMERGENCYBUTTONPRESS:
		states[EMNERGENCYSTOPSTATE_ID].actives[0] = EMERGENCYBUTTONPRESS_ID;
		(this->StateEntry)(EMERGENCYBUTTONPRESS_ID);
		;
		//starting the counters for time events
		//start activity of EmergencyButtonPress by calling setFlag
		setFlag(EMERGENCYBUTTONPRESS_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void FrontControlComponent__Delegatee::EmnergencyStopState_Region1_Exit() {
	//exiting region Region1
	if (states[EMNERGENCYSTOPSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of EmnergencyStopState
		setFlag(states[EMNERGENCYSTOPSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (CHECK_ID == states[EMNERGENCYSTOPSTATE_ID].actives[0]) {
		} else if (EMERGENCYBUTTONPRESS_ID
				== states[EMNERGENCYSTOPSTATE_ID].actives[0]) {
		}
		//exit action of sub-state of EmnergencyStopState
		StateExit(states[EMNERGENCYSTOPSTATE_ID].actives[0]);
		//set active sub-state of EmnergencyStopState to STATE_MAX meaning NULL
		states[EMNERGENCYSTOPSTATE_ID].actives[0] = STATE_MAX;
	}
}

/**
 * 
 * @param enter_mode 
 */
void FrontControlComponent__Delegatee::PrincipalState_Region2_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;

		//start activity of CheckMessage by calling setFlag
		setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_CHECKMESSAGE:
		states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
		//starting the counters for time events
		//start activity of CheckMessage by calling setFlag
		setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void FrontControlComponent__Delegatee::PrincipalState_Region2_Exit() {
	//exiting region Region2
	if (states[PRINCIPALSTATE_ID].actives[1] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[1],
				statemachine::TF_DO_ACTIVITY, false);
		if (CHECKMESSAGE_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (PING_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (GETSTATUS_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (LOADCAR_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (ASSEMBLE_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (REWIND_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (DELIVER_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (RESET_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		}
		//exit action of sub-state of PrincipalState
		StateExit(states[PRINCIPALSTATE_ID].actives[1]);
		//set active sub-state of PrincipalState to STATE_MAX meaning NULL
		states[PRINCIPALSTATE_ID].actives[1] = STATE_MAX;
	}
}

/**
 * 
 */
FrontControlComponent__Delegatee::FrontControlComponent__Delegatee() :
		systemState(statemachine::IDLE) {
	//startBehavior();
}

/**
 * 
 */
void FrontControlComponent__Delegatee::startBehavior() {
	states[CHECK_ID].hasDoActivity = true;
	states[CHECKMESSAGE_ID].hasDoActivity = true;
	// initialize all threads, the threads wait until the associated flag is set
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL,
					&FrontControlComponent__Delegatee::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	timeEventThreadStructs[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
			TE_50_MS__ID)].duration = 50;
	for (int i = FRONTCONTROLCOMPONENT__DELEGATEE_TIME_EVENT_LOWER_BOUND; i < 1;
			i++) {
		timeEventThreadStructs[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)].id =
				i;
		timeEventThreadStructs[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)].ptr =
				this;
		timeEventThreadStructs[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)].func_type =
				statemachine::TF_TIME_EVENT;
		timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)] =
				PTHREAD_MUTEX_INITIALIZER;
		timeEventConds[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)] =
				PTHREAD_COND_INITIALIZER;
		pthread_create(
				&timeEventThreads[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)],
				NULL, &FrontControlComponent__Delegatee::thread_func_wrapper,
				&timeEventThreadStructs[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
						i)]);
		while (timeEventFlags[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)]) {
		}
	}

	regionTable[FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1] =
			&FrontControlComponent__Delegatee::PrincipalState_Region1_Enter;
	regionExitTable[FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1] =
			&FrontControlComponent__Delegatee::PrincipalState_Region1_Exit;
	regionTable[FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2] =
			&FrontControlComponent__Delegatee::PrincipalState_Region2_Enter;
	regionExitTable[FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2] =
			&FrontControlComponent__Delegatee::PrincipalState_Region2_Exit;

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	FrontControlComponent__Delegatee_THREAD_CREATE(dispatchThread,
			dispatchStruct)
}

/**
 * 
 */
FrontControlComponent__Delegatee::~FrontControlComponent__Delegatee() {
	stopBehavior();
}

/**
 * 
 */
void FrontControlComponent__Delegatee::stopBehavior() {
	systemState = statemachine::STOPPED;
	//signal and wait for doActivity termination
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			pthread_cond_signal (&conds[i]);
			pthread_join(threads[i], NULL);
		}
	}

	//signal and wait for time event thread termination
	for (int i = FRONTCONTROLCOMPONENT__DELEGATEE_TIME_EVENT_LOWER_BOUND; i < 1;
			i++) {
		pthread_cond_signal (&timeEventConds[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
				i)]);
		pthread_join(
				timeEventThreads[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(i)],
				NULL);
	}

	//main thread
	pthread_join(dispatchThread, NULL);
}

/**
 * 
 */
void FrontControlComponent__Delegatee::processTE_50_ms_() {
	systemState = statemachine::EVENT_PROCESSING;
}

/**
 * 
 * @param sig 
 */
void FrontControlComponent__Delegatee::processEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == EMNERGENCYSTOPSTATE_ID) {
		//from EmnergencyStopState to EmnergencyStopState
		if (true) {
			EmnergencyStopState_Region1_Exit();
			states[PRINCIPALSTATE_ID].actives[0] = EMNERGENCYSTOPSTATE_ID;
			//starting the counters for time events
			EmnergencyStopState_Region1_Enter (FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void FrontControlComponent__Delegatee::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void FrontControlComponent__Delegatee::processErrorDetection(
		::CarFactoryLibrary::events::ErrorDetection& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == EMNERGENCYSTOPSTATE_ID) {
		//from EmnergencyStopState to Misplace
		if (true) {
			EmnergencyStopState_Region1_Exit();
			component->effectFromEmnergencyStopStatetoMisplace(sig);
			states[PRINCIPALSTATE_ID].actives[0] = MISPLACE_ID;
			(this->StateEntry)(MISPLACE_ID);
			;
			//starting the counters for time events
			//start activity of Misplace by calling setFlag
			setFlag(MISPLACE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void FrontControlComponent__Delegatee::push(
		::CarFactoryLibrary::events::ErrorDetection& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ERRORDETECTION_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::ErrorDetection));
}

/**
 * 
 */
void FrontControlComponent__Delegatee::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[EMNERGENCYSTOPSTATE_ID].actives[0] == CHECK_ID
			&& (currentEvent->associatedState == CHECK_ID)) {
		//from Check to wait
		if (true) {
			//signal to exit the doActivity of Check
			setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, false);
			if (component->()) {
				states[EMNERGENCYSTOPSTATE_ID].actives[0] =
						EMERGENCYBUTTONPRESS_ID;
				(this->StateEntry)(EMERGENCYBUTTONPRESS_ID);
				;
				//starting the counters for time events
				//start activity of EmergencyButtonPress by calling setFlag
				setFlag(EMERGENCYBUTTONPRESS_ID, statemachine::TF_DO_ACTIVITY,
						true);
			} else {
				states[EMNERGENCYSTOPSTATE_ID].actives[0] = CHECK_ID;
				//starting the counters for time events
				//start activity of Check by calling setFlag
				setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, true);
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[EMNERGENCYSTOPSTATE_ID].actives[0]
			== EMERGENCYBUTTONPRESS_ID
			&& (currentEvent->associatedState == EMERGENCYBUTTONPRESS_ID)) {
		//from EmergencyButtonPress to ShowStopGUI
		if (true) {
			EmnergencyStopState_Region1_Exit();
			states[PRINCIPALSTATE_ID].actives[0] = SHOWSTOPGUI_ID;
			(this->StateEntry)(SHOWSTOPGUI_ID);
			;
			//starting the counters for time events
			//start activity of ShowStopGUI by calling setFlag
			setFlag(SHOWSTOPGUI_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == LOADCAR_ID
			&& (currentEvent->associatedState == LOADCAR_ID)) {
		//from LoadCar to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[0] == SHOWSTOPGUI_ID
			&& (currentEvent->associatedState == SHOWSTOPGUI_ID)) {
		//from ShowStopGUI to choice1
		if (true) {
			if (choice1_CompletionEvent == 0) {
				states[PRINCIPALSTATE_ID].actives[0] = RESTART_ID;
				(this->StateEntry)(RESTART_ID);
				;
				//starting the counters for time events
				//start activity of Restart by calling setFlag
				setFlag(RESTART_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				states[PRINCIPALSTATE_ID].actives[0] = SHOWSTOPGUI_ID;
				(this->StateEntry)(SHOWSTOPGUI_ID);
				;
				//starting the counters for time events
				//start activity of ShowStopGUI by calling setFlag
				setFlag(SHOWSTOPGUI_ID, statemachine::TF_DO_ACTIVITY, true);
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[0] == RESTART_ID
			&& (currentEvent->associatedState == RESTART_ID)) {
		//from Restart to EmnergencyStopState
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = EMNERGENCYSTOPSTATE_ID;
			//starting the counters for time events
			EmnergencyStopState_Region1_Enter (FRONTCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[0] == MISPLACE_ID
			&& (currentEvent->associatedState == MISPLACE_ID)) {
		//from Misplace to choice2
		if (true) {
			if (choice2_CompletionEvent == 1) {
				states[PRINCIPALSTATE_ID].actives[0] = RESTART_ID;
				(this->StateEntry)(RESTART_ID);
				;
				//starting the counters for time events
				//start activity of Restart by calling setFlag
				setFlag(RESTART_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				states[PRINCIPALSTATE_ID].actives[0] = MISPLACE_ID;
				(this->StateEntry)(MISPLACE_ID);
				;
				//starting the counters for time events
				//start activity of Misplace by calling setFlag
				setFlag(MISPLACE_ID, statemachine::TF_DO_ACTIVITY, true);
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == CHECKMESSAGE_ID
			&& (currentEvent->associatedState == CHECKMESSAGE_ID)) {
		//from CheckMessage to choice
		if (true) {
			//signal to exit the doActivity of CheckMessage
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, false);
			if (choice_CompletionEvent == 0) {
				states[PRINCIPALSTATE_ID].actives[1] = PING_ID;
				(this->StateEntry)(PING_ID);
				;
				//starting the counters for time events
				//start activity of Ping by calling setFlag
				setFlag(PING_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (choice_CompletionEvent == 1) {
				states[PRINCIPALSTATE_ID].actives[1] = GETSTATUS_ID;
				(this->StateEntry)(GETSTATUS_ID);
				;
				//starting the counters for time events
				//start activity of GetStatus by calling setFlag
				setFlag(GETSTATUS_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (choice_CompletionEvent == 2) {
				states[PRINCIPALSTATE_ID].actives[1] = LOADCAR_ID;
				(this->StateEntry)(LOADCAR_ID);
				;
				//starting the counters for time events
				//start activity of LoadCar by calling setFlag
				setFlag(LOADCAR_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (choice_CompletionEvent == 4) {
				states[PRINCIPALSTATE_ID].actives[1] = DELIVER_ID;
				(this->StateEntry)(DELIVER_ID);
				;
				//starting the counters for time events
				//start activity of Deliver by calling setFlag
				setFlag(DELIVER_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (choice_CompletionEvent == 5) {
				states[PRINCIPALSTATE_ID].actives[1] = REWIND_ID;
				(this->StateEntry)(REWIND_ID);
				;
				//starting the counters for time events
				//start activity of Rewind by calling setFlag
				setFlag(REWIND_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (choice_CompletionEvent == 6) {
				states[PRINCIPALSTATE_ID].actives[1] = ASSEMBLE_ID;
				(this->StateEntry)(ASSEMBLE_ID);
				;
				//starting the counters for time events
				//start activity of Assemble by calling setFlag
				setFlag(ASSEMBLE_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (choice_CompletionEvent == 7) {
				//exiting concurrent state PrincipalState
				pthread_t PrincipalState_Region1_exit_thread;
				statemachine::StructForThread_t PrincipalState_Region1_exit_thread_struct(
						this,
						FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1,
						0, statemachine::TF_EXIT_REGION, 0);
				FrontControlComponent__Delegatee_THREAD_CREATE(
						PrincipalState_Region1_exit_thread,
						PrincipalState_Region1_exit_thread_struct)
				pthread_t PrincipalState_Region2_exit_thread;
				statemachine::StructForThread_t PrincipalState_Region2_exit_thread_struct(
						this,
						FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2,
						0, statemachine::TF_EXIT_REGION, 0);
				FrontControlComponent__Delegatee_THREAD_CREATE(
						PrincipalState_Region2_exit_thread,
						PrincipalState_Region2_exit_thread_struct)
				pthread_join(PrincipalState_Region1_exit_thread, NULL);
				pthread_join(PrincipalState_Region2_exit_thread, NULL);
				activeStateID = STATE_MAX;
			} else if (choice_CompletionEvent == 8) {
				states[PRINCIPALSTATE_ID].actives[1] = RESET_ID;
				(this->StateEntry)(RESET_ID);
				;
				//starting the counters for time events
				//start activity of Reset by calling setFlag
				setFlag(RESET_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
				//starting the counters for time events
				//start activity of CheckMessage by calling setFlag
				setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == GETSTATUS_ID
			&& (currentEvent->associatedState == GETSTATUS_ID)) {
		//from GetStatus to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == PING_ID
			&& (currentEvent->associatedState == PING_ID)) {
		//from Ping to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == ASSEMBLE_ID
			&& (currentEvent->associatedState == ASSEMBLE_ID)) {
		//from Assemble to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == REWIND_ID
			&& (currentEvent->associatedState == REWIND_ID)) {
		//from Rewind to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == DELIVER_ID
			&& (currentEvent->associatedState == DELIVER_ID)) {
		//from Deliver to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[1] == RESET_ID
			&& (currentEvent->associatedState == RESET_ID)) {
		//from Reset to CheckMessage
		if (true) {
			states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
			//starting the counters for time events
			//start activity of CheckMessage by calling setFlag
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (systemState == statemachine::EVENT_PROCESSING
			&& (currentEvent->associatedState == activeStateID)) {
		switch (activeStateID) {
		case INITIALIZATION_ID:
			//from Initialization to PrincipalState
			if (component->()) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				//PrincipalState_Region1_Enter(FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION1_DEFAULT);
				pthread_t PrincipalState_Region1_enter_thread;
				statemachine::StructForThread_t PrincipalState_Region1_enter_thread_struct(
						this,
						FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1,
						FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION1_DEFAULT,
						statemachine::TF_ENTER_REGION, 0);
				FrontControlComponent__Delegatee_THREAD_CREATE(
						PrincipalState_Region1_enter_thread,
						PrincipalState_Region1_enter_thread_struct)
				//PrincipalState_Region2_Enter(FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_DEFAULT);
				pthread_t PrincipalState_Region2_enter_thread;
				statemachine::StructForThread_t PrincipalState_Region2_enter_thread_struct(
						this,
						FRONTCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2,
						FRONTCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_DEFAULT,
						statemachine::TF_ENTER_REGION, 0);
				FrontControlComponent__Delegatee_THREAD_CREATE(
						PrincipalState_Region2_enter_thread,
						PrincipalState_Region2_enter_thread_struct)
				pthread_join(PrincipalState_Region1_enter_thread, NULL);
				pthread_join(PrincipalState_Region2_enter_thread, NULL);
				systemState = statemachine::EVENT_CONSUMED;
			}
			break;
		default:
			//do nothing
			break;
		}
	}
}

/**
 * 
 * @param id 
 */
void FrontControlComponent__Delegatee::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case INITIALIZATION_ID:
		component->init();
		break;
	case EMERGENCYBUTTONPRESS_ID:
		component->sendStopProcessEvent();
		break;
	case MISPLACE_ID:
		component->sendStopProcess();
		break;
	case SHOWSTOPGUI_ID:
		component->show_stop_GUI();
		break;
	case RESTART_ID:
		component->send_restart_event();
		break;
	case PING_ID:
		component->ping_response();
		break;
	case GETSTATUS_ID:
		component->get_status_response();
		break;
	case LOADCAR_ID:
		component->sendPrepareConveyorEvent();
		break;
	case ASSEMBLE_ID:
		component->send_check_racks_event();
		break;
	case REWIND_ID:
		component->rewind();
		break;
	case DELIVER_ID:
		component->deliver();
		break;
	case RESET_ID:
		component->reset();
		break;
	default:
		//do nothing
		break;
	}
}

/**
 * 
 * @param id 
 */
void FrontControlComponent__Delegatee::StateExit(unsigned int /*in*/id) {
	switch (id) {
	default:
		//do nothing
		break;
	}
}

/**
 * 
 * @param id 
 */
void FrontControlComponent__Delegatee::StateDoActivity(unsigned int /*in*/id) {
	switch (id) {
	case CHECK_ID:
		component->doActivityCheck();
		break;
	case CHECKMESSAGE_ID:
		component->read();
		break;
	default:
		//do nothing
		break;
	}
}

/**
 * 
 * @param data 
 * @return ret 
 */
void* FrontControlComponent__Delegatee::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	FrontControlComponent__Delegatee* ptr =
			(FrontControlComponent__Delegatee*) cptr->ptr;
	switch (cptr->func_type) {
	case statemachine::TF_DO_ACTIVITY:
		ptr->doCallActivity(cptr->id);
		break;
	case statemachine::TF_TIME_EVENT:
		ptr->listenTimeEvent(cptr->id, cptr->duration);
		break;
	case statemachine::TF_ENTER_REGION:
		ptr->regionCall(cptr->id, cptr->enter_mode);
		break;
	case statemachine::TF_EXIT_REGION:
		ptr->exitRegionCall(cptr->id);
		break;
	case statemachine::TF_STATE_MACHINE_TYPE:
		ptr->dispatchEvent();
		break;
	}
	return NULL;
}

/**
 * 
 * @param id 
 */
void FrontControlComponent__Delegatee::doCallActivity(int /*in*/id) {
	flags[id] = false;
	while (systemState != statemachine::STOPPED) {
		pthread_mutex_lock (&mutexes[id]);
		while (!flags[id] && systemState != statemachine::STOPPED) {
			pthread_cond_wait(&conds[id], &mutexes[id]);
		}
		if (systemState != statemachine::STOPPED) {
			StateDoActivity(id);
		}
		bool commitEvent = false;
		if (flags[id]) {
			commitEvent = true;
			flags[id] = false;
		}
		pthread_cond_signal (&conds[id]);
		pthread_mutex_unlock(&mutexes[id]);
		if (commitEvent && systemState != statemachine::STOPPED) {
			if (id == INITIALIZATION_ID || id == CHECK_ID
					|| id == EMERGENCYBUTTONPRESS_ID || id == MISPLACE_ID
					|| id == SHOWSTOPGUI_ID || id == RESTART_ID
					|| id == CHECKMESSAGE_ID || id == PING_ID
					|| id == GETSTATUS_ID || id == LOADCAR_ID
					|| id == ASSEMBLE_ID || id == REWIND_ID || id == DELIVER_ID
					|| id == RESET_ID) {
				//processCompletionEvent();
				eventQueue.push(statemachine::PRIORITY_1, NULL,
						COMPLETIONEVENT_ID, statemachine::COMPLETION_EVENT, id);
			}
		}
	}
}

/**
 * 
 * @param id 
 * @param func_type 
 * @param value 
 */
void FrontControlComponent__Delegatee::setFlag(int /*in*/id,
		char /*in*/func_type, bool /*in*/value) {
	//value = true => start activity
	//value = false => stop activity
	if (func_type == statemachine::TF_TIME_EVENT) {
		pthread_mutex_lock (&timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
				id)]);
		timeEventFlags[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(id)] = value;
		pthread_cond_signal (&timeEventConds[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
				id)]);
		pthread_mutex_unlock(
				&timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(id)]);
		return;
	}
	if (func_type == statemachine::TF_DO_ACTIVITY) {
		if (states[id].hasDoActivity) {
			//state has doActivity => if value = true => should
			pthread_mutex_lock (&mutexes[id]);
			if (value) {
				flags[id] = true;
			} else {
				//wait until doActivity exit
				while (flags[id]) {
					pthread_cond_wait(&conds[id], &mutexes[id]);
				}
			}
			pthread_cond_signal (&conds[id]);
			pthread_mutex_unlock(&mutexes[id]);
		} else {
			//push completion event
			if (value) {
				if (id == INITIALIZATION_ID || id == CHECK_ID
						|| id == EMERGENCYBUTTONPRESS_ID || id == MISPLACE_ID
						|| id == SHOWSTOPGUI_ID || id == RESTART_ID
						|| id == CHECKMESSAGE_ID || id == PING_ID
						|| id == GETSTATUS_ID || id == LOADCAR_ID
						|| id == ASSEMBLE_ID || id == REWIND_ID
						|| id == DELIVER_ID || id == RESET_ID) {
					eventQueue.push(statemachine::PRIORITY_1, NULL,
							COMPLETIONEVENT_ID, statemachine::COMPLETION_EVENT,
							id);
				}
			}
		}
		return;
	}
}

/**
 * 
 * @param id 
 * @param duration 
 */
void FrontControlComponent__Delegatee::listenTimeEvent(int /*in*/id,
		int /*in*/duration) {
	struct timeval tv;
	struct timespec ts;
	int timedWaitResult = 0;
	while (systemState != statemachine::STOPPED) {
		pthread_mutex_lock (&timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
				id)]);
		while (!timeEventFlags[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(id)]
				&& systemState != statemachine::STOPPED) {
			pthread_cond_wait(
					&timeEventConds[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
							id)],
					&timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
							id)]);
		}

		gettimeofday(&tv, NULL);
		ts.tv_sec = time(NULL) + duration / 1000;
		ts.tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (duration % 1000);
		ts.tv_sec += ts.tv_nsec / (1000 * 1000 * 1000);
		ts.tv_nsec %= (1000 * 1000 * 1000);
		if (systemState != statemachine::STOPPED) {
			timedWaitResult = pthread_cond_timedwait(
					&timeEventConds[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
							id)],
					&timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
							id)], &ts);
		}
		bool commitEvent = false;
		if (timedWaitResult != 0) {
			//timeout
			commitEvent = true;
		}
		timeEventFlags[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(id)] = false;
		pthread_cond_signal (&timeEventConds[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(
				id)]);
		pthread_mutex_unlock(
				&timeEventMutexes[FRONTCONTROLCOMPONENT__DELEGATEE_TE_INDEX(id)]);
		if (commitEvent && systemState != statemachine::STOPPED) {
			//the state does not change, push time event to the queue
			eventQueue.push(statemachine::PRIORITY_2, NULL, id,
					statemachine::TIME_EVENT, id);
		}
	}
}

/**
 * 
 * @param id 
 * @param enter_mode 
 */
void FrontControlComponent__Delegatee::regionCall(int /*in*/id,
		char /*in*/enter_mode) {
	(this->*regionTable[id])(enter_mode);
}

/**
 * 
 * @param id 
 */
void FrontControlComponent__Delegatee::exitRegionCall(int /*in*/id) {
	(this->*regionExitTable[id])();
}

/**
 * 
 * @param comp 
 */
void FrontControlComponent__Delegatee::setComponent(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Front::FrontControlComponent* /*in*/comp) {
	this->component = comp;
	this->get_pLCD();
	this->get_pModule();
	this->get_pErrDetect();
	this->get_pEndOfMo();
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::ErrorDetection>* FrontControlComponent__Delegatee::get_pErrDetect() {
	component->pErrDetect.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* FrontControlComponent__Delegatee::get_pEndOfMo() {
	component->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* FrontControlComponent__Delegatee::get_pLCD() {
	component->pLCD.providedIntf = &(component->ev3Brick.lcdScreen);
	return component->pLCD.providedIntf;
}

/**
 * 
 * @return ret 
 */
::CarFactoryLibrary::IModule* FrontControlComponent__Delegatee::get_pModule() {
	component->pModule.providedIntf = component;
	return component->pModule.providedIntf;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutStopProcess_Shelf(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	component->pOutStopProcess_Shelf.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutStopProcess_RoboticArm(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	component->pOutStopProcess_RoboticArm.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pStopProcess_Convoyer(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	component->pStopProcess_Convoyer.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutRestart_Shelf(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	component->pOutRestart_Shelf.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutRestart_Convoyer(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	component->pOutRestart_Convoyer.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutRestart_Robotic(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	component->pOutRestart_Robotic.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pPrepare(
		IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>* /*in*/ref) {
	component->pPrepare.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutStopProcess_Press(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	component->pOutStopProcess_Press.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pOutRestart_Press(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	component->pOutRestart_Press.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pCheckRack(
		IPush<CarFactoryLibrary::events::CheckRack>* /*in*/ref) {
	component->pCheckRack.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pDelivered(
		IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* /*in*/ref) {
	component->pDelivered.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pIFloatMotor(
		::CarFactoryLibrary::CommunicationInterfaces::IRoboticArmFloatMotor* /*in*/ref) {
	component->pIFloatMotor.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pILargeMotor(
		::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* /*in*/ref) {
	component->pILargeMotor.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontControlComponent__Delegatee::connect_pPressILargeMotor(
		::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* /*in*/ref) {
	component->pPressILargeMotor.requiredIntf = ref;
}

} // of namespace Front
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of FrontControlComponent__Delegatee class body
 ************************************************************/