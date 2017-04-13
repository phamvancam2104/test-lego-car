// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_BackBackControlComponent__Controller_BODY

/************************************************************
 BackBackControlComponent__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/BackBackControlComponent__Controller.h"

// Derived includes directives
#include "CarFactoryLibrary/CommunicationInterfaces/IRoboticArmFloatMotor.h"
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackControlComponent.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 */
void BackBackControlComponent__Controller::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	BackControlStateMachine_Region1_Enter (BACKCONTROLCOMPONENT_BACKCONTROLSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			BACKBACKCONTROLCOMPONENT__CONTROLLER_GET_CONTROL
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
			BACKBACKCONTROLCOMPONENT__CONTROLLER_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void BackBackControlComponent__Controller::BackControlStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case BACKCONTROLCOMPONENT_BACKCONTROLSTATEMACHINE_REGION1_DEFAULT:
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
void BackBackControlComponent__Controller::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case BACKCONTROLCOMPONENT_PRINCIPALSTATE_REGION1_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[0] = EMNERGENCYSTOPSTATE_ID;

		EmnergencyStopState_Region1_Enter (BACKCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void BackBackControlComponent__Controller::PrincipalState_Region1_Exit() {
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
		} else if (RESTART_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (SHOWSTOPGUI_ID == states[PRINCIPALSTATE_ID].actives[0]) {
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
void BackBackControlComponent__Controller::EmnergencyStopState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case BACKCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT:
		states[EMNERGENCYSTOPSTATE_ID].actives[0] = CHECK_ID;

		//start activity of Check by calling setFlag
		setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case BACKCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_CHECK:
		states[EMNERGENCYSTOPSTATE_ID].actives[0] = CHECK_ID;
		//starting the counters for time events
		//start activity of Check by calling setFlag
		setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void BackBackControlComponent__Controller::EmnergencyStopState_Region1_Exit() {
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
void BackBackControlComponent__Controller::PrincipalState_Region2_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case BACKCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;

		//start activity of CheckMessage by calling setFlag
		setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void BackBackControlComponent__Controller::PrincipalState_Region2_Exit() {
	//exiting region Region2
	if (states[PRINCIPALSTATE_ID].actives[1] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[1],
				statemachine::TF_DO_ACTIVITY, false);
		if (CHECKMESSAGE_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (RESET_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (PING_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (GETSTATUS_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (LOADCAR_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (DELIVER_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (REWIND_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		} else if (ASSEMBLE_ID == states[PRINCIPALSTATE_ID].actives[1]) {
		}
		//exit action of sub-state of PrincipalState
		StateExit(states[PRINCIPALSTATE_ID].actives[1]);
		//set active sub-state of PrincipalState to STATE_MAX meaning NULL
		states[PRINCIPALSTATE_ID].actives[1] = STATE_MAX;
	}
}

/**
 * 
 * @param origin 
 */
BackBackControlComponent__Controller::BackBackControlComponent__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Back::BackControlComponent* /*in*/origin) :
		eventQueue(50, eventArray), p_origin(origin) {
	//startBehavior();
}

/**
 * 
 */
void BackBackControlComponent__Controller::startBehavior() {
	systemState = statemachine::IDLE;

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
					&BackBackControlComponent__Controller::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	timeEventThreadStructs[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
			TE_50_MS__ID)].duration = 50;
	for (int i = BACKBACKCONTROLCOMPONENT__CONTROLLER_TIME_EVENT_LOWER_BOUND;
			i < 1; i++) {
		timeEventThreadStructs[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(i)].id =
				i;
		timeEventThreadStructs[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(i)].ptr =
				this;
		timeEventThreadStructs[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(i)].func_type =
				statemachine::TF_TIME_EVENT;
		timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(i)] =
				PTHREAD_MUTEX_INITIALIZER;
		timeEventConds[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(i)] =
				PTHREAD_COND_INITIALIZER;
		pthread_create(
				&timeEventThreads[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
						i)], NULL,
				&BackBackControlComponent__Controller::thread_func_wrapper,
				&timeEventThreadStructs[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
						i)]);
		while (timeEventFlags[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(i)]) {
		}
	}

	regionTable[BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1] =
			&BackBackControlComponent__Controller::PrincipalState_Region1_Enter;
	regionExitTable[BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1] =
			&BackBackControlComponent__Controller::PrincipalState_Region1_Exit;
	regionTable[BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2] =
			&BackBackControlComponent__Controller::PrincipalState_Region2_Enter;
	regionExitTable[BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2] =
			&BackBackControlComponent__Controller::PrincipalState_Region2_Exit;

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	BackBackControlComponent__Controller_THREAD_CREATE(dispatchThread,
			dispatchStruct)
}

/**
 * 
 */
BackBackControlComponent__Controller::~BackBackControlComponent__Controller() {
	stopBehavior();
}

/**
 * 
 */
void BackBackControlComponent__Controller::stopBehavior() {
	systemState = statemachine::STOPPED;
	//signal and wait for doActivity termination
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			pthread_cond_signal (&conds[i]);
			pthread_join(threads[i], NULL);
		}
	}

	//signal and wait for time event thread termination
	for (int i = BACKBACKCONTROLCOMPONENT__CONTROLLER_TIME_EVENT_LOWER_BOUND;
			i < 1; i++) {
		pthread_cond_signal (&timeEventConds[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
				i)]);
		pthread_join(
				timeEventThreads[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
						i)], NULL);
	}

	//main thread
	pthread_join(dispatchThread, NULL);

}

/**
 * 
 */
void BackBackControlComponent__Controller::processTE_50_ms_() {
	systemState = statemachine::EVENT_PROCESSING;
}

/**
 * 
 * @param sig 
 */
void BackBackControlComponent__Controller::processEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == EMNERGENCYSTOPSTATE_ID) {
		//from EmnergencyStopState to EmnergencyStopState
		if (true) {
			EmnergencyStopState_Region1_Exit();
			states[PRINCIPALSTATE_ID].actives[0] = EMNERGENCYSTOPSTATE_ID;
			//starting the counters for time events
			EmnergencyStopState_Region1_Enter (BACKCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void BackBackControlComponent__Controller::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void BackBackControlComponent__Controller::processErrorDetection(
		::CarFactoryLibrary::events::ErrorDetection& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == EMNERGENCYSTOPSTATE_ID) {
		//from EmnergencyStopState to Misplace
		if (true) {
			EmnergencyStopState_Region1_Exit();
			p_origin->effectFromEmnergencyStopStatetoMisplace(sig);
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
void BackBackControlComponent__Controller::push(
		::CarFactoryLibrary::events::ErrorDetection& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ERRORDETECTION_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::ErrorDetection));
}

/**
 * 
 */
void BackBackControlComponent__Controller::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[EMNERGENCYSTOPSTATE_ID].actives[0] == EMERGENCYBUTTONPRESS_ID
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
	} else if (states[EMNERGENCYSTOPSTATE_ID].actives[0] == CHECK_ID
			&& (currentEvent->associatedState == CHECK_ID)) {
		//from Check to wait
		if (true) {
			//signal to exit the doActivity of Check
			setFlag(CHECK_ID, statemachine::TF_DO_ACTIVITY, false);
			if (p_origin->fromWaittoEmergencyButtonPressGuard()) {
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
	}
	if (states[PRINCIPALSTATE_ID].actives[0] == RESTART_ID
			&& (currentEvent->associatedState == RESTART_ID)) {
		//from Restart to EmnergencyStopState
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = EMNERGENCYSTOPSTATE_ID;
			//starting the counters for time events
			EmnergencyStopState_Region1_Enter (BACKCONTROLCOMPONENT_EMNERGENCYSTOPSTATE_REGION1_DEFAULT);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
	if (states[PRINCIPALSTATE_ID].actives[0] == MISPLACE_ID
			&& (currentEvent->associatedState == MISPLACE_ID)) {
		//from Misplace to choice2
		if (true) {
			if (p_origin->fromChoice2toRestartGuard()) {
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
	if (states[PRINCIPALSTATE_ID].actives[0] == SHOWSTOPGUI_ID
			&& (currentEvent->associatedState == SHOWSTOPGUI_ID)) {
		//from ShowStopGUI to choice1
		if (true) {
			if (p_origin->fromChoice1toRestartGuard()) {
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
	if (states[PRINCIPALSTATE_ID].actives[1] == CHECKMESSAGE_ID
			&& (currentEvent->associatedState == CHECKMESSAGE_ID)) {
		//from CheckMessage to choice
		if (true) {
			//signal to exit the doActivity of CheckMessage
			setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, false);
			if (p_origin->fromChoicetoPingGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = PING_ID;
				(this->StateEntry)(PING_ID);
				;
				//starting the counters for time events
				//start activity of Ping by calling setFlag
				setFlag(PING_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoGetStatusGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = GETSTATUS_ID;
				(this->StateEntry)(GETSTATUS_ID);
				;
				//starting the counters for time events
				//start activity of GetStatus by calling setFlag
				setFlag(GETSTATUS_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoLoadCarGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = LOADCAR_ID;
				(this->StateEntry)(LOADCAR_ID);
				;
				//starting the counters for time events
				//start activity of LoadCar by calling setFlag
				setFlag(LOADCAR_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoDeliverGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = DELIVER_ID;
				(this->StateEntry)(DELIVER_ID);
				;
				//starting the counters for time events
				//start activity of Deliver by calling setFlag
				setFlag(DELIVER_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoRewindGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = REWIND_ID;
				(this->StateEntry)(REWIND_ID);
				;
				//starting the counters for time events
				//start activity of Rewind by calling setFlag
				setFlag(REWIND_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoAssembleGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = ASSEMBLE_ID;
				(this->StateEntry)(ASSEMBLE_ID);
				;
				//starting the counters for time events
				//start activity of Assemble by calling setFlag
				setFlag(ASSEMBLE_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoResetGuard()) {
				states[PRINCIPALSTATE_ID].actives[1] = RESET_ID;
				(this->StateEntry)(RESET_ID);
				;
				//starting the counters for time events
				//start activity of Reset by calling setFlag
				setFlag(RESET_ID, statemachine::TF_DO_ACTIVITY, true);
			} else if (p_origin->fromChoicetoFinalState1Guard()) {
				//exiting concurrent state PrincipalState
				pthread_t PrincipalState_Region1_exit_thread;
				statemachine::StructForThread_t PrincipalState_Region1_exit_thread_struct(
						this,
						BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1,
						0, statemachine::TF_EXIT_REGION, 0);
				BackBackControlComponent__Controller_THREAD_CREATE(
						PrincipalState_Region1_exit_thread,
						PrincipalState_Region1_exit_thread_struct)
				pthread_t PrincipalState_Region2_exit_thread;
				statemachine::StructForThread_t PrincipalState_Region2_exit_thread_struct(
						this,
						BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2,
						0, statemachine::TF_EXIT_REGION, 0);
				BackBackControlComponent__Controller_THREAD_CREATE(
						PrincipalState_Region2_exit_thread,
						PrincipalState_Region2_exit_thread_struct)
				pthread_join(PrincipalState_Region1_exit_thread, NULL);
				pthread_join(PrincipalState_Region2_exit_thread, NULL);
				activeStateID = STATE_MAX;
			} else {
				states[PRINCIPALSTATE_ID].actives[1] = CHECKMESSAGE_ID;
				//starting the counters for time events
				//start activity of CheckMessage by calling setFlag
				setFlag(CHECKMESSAGE_ID, statemachine::TF_DO_ACTIVITY, true);
			}
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
	if (systemState == statemachine::EVENT_PROCESSING
			&& (currentEvent->associatedState == activeStateID)) {
		switch (activeStateID) {
		case INITIALIZATION_ID:
			//from Initialization to PrincipalState
			if (p_origin->fromInitializationtoPrincipalStateGuard()) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				//PrincipalState_Region1_Enter(BACKCONTROLCOMPONENT_PRINCIPALSTATE_REGION1_DEFAULT);
				pthread_t PrincipalState_Region1_enter_thread;
				statemachine::StructForThread_t PrincipalState_Region1_enter_thread_struct(
						this,
						BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION1,
						BACKCONTROLCOMPONENT_PRINCIPALSTATE_REGION1_DEFAULT,
						statemachine::TF_ENTER_REGION, 0);
				BackBackControlComponent__Controller_THREAD_CREATE(
						PrincipalState_Region1_enter_thread,
						PrincipalState_Region1_enter_thread_struct)
				//PrincipalState_Region2_Enter(BACKCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_DEFAULT);
				pthread_t PrincipalState_Region2_enter_thread;
				statemachine::StructForThread_t PrincipalState_Region2_enter_thread_struct(
						this,
						BACKCONTROLCOMPONENT_REGION_ID_PRINCIPALSTATE_REGION2,
						BACKCONTROLCOMPONENT_PRINCIPALSTATE_REGION2_DEFAULT,
						statemachine::TF_ENTER_REGION, 0);
				BackBackControlComponent__Controller_THREAD_CREATE(
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
void BackBackControlComponent__Controller::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case INITIALIZATION_ID:
		p_origin->init();
		break;
	case EMERGENCYBUTTONPRESS_ID:
		p_origin->sendStopProcessEvent();
		break;
	case MISPLACE_ID:
		p_origin->sendStopProcess();
		break;
	case RESTART_ID:
		p_origin->send_restart_event();
		break;
	case SHOWSTOPGUI_ID:
		p_origin->show_stop_GUI();
		break;
	case RESET_ID:
		p_origin->reset();
		break;
	case PING_ID:
		p_origin->ping_response();
		break;
	case GETSTATUS_ID:
		p_origin->get_status_response();
		break;
	case LOADCAR_ID:
		p_origin->sendPrepareConveyorEvent();
		break;
	case DELIVER_ID:
		p_origin->deliver();
		break;
	case REWIND_ID:
		p_origin->rewind();
		break;
	case ASSEMBLE_ID:
		p_origin->send_check_racks_event();
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
void BackBackControlComponent__Controller::StateExit(unsigned int /*in*/id) {
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
void BackBackControlComponent__Controller::StateDoActivity(
		unsigned int /*in*/id) {
	switch (id) {
	case CHECK_ID:
		p_origin->doActivityCheck();
		break;
	case CHECKMESSAGE_ID:
		p_origin->read();
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
void* BackBackControlComponent__Controller::thread_func_wrapper(
		void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	BackBackControlComponent__Controller* ptr =
			(BackBackControlComponent__Controller*) cptr->ptr;
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
void BackBackControlComponent__Controller::doCallActivity(int /*in*/id) {
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
					|| id == RESTART_ID || id == SHOWSTOPGUI_ID
					|| id == CHECKMESSAGE_ID || id == RESET_ID || id == PING_ID
					|| id == GETSTATUS_ID || id == LOADCAR_ID
					|| id == DELIVER_ID || id == REWIND_ID
					|| id == ASSEMBLE_ID) {
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
void BackBackControlComponent__Controller::setFlag(int /*in*/id,
		char /*in*/func_type, bool /*in*/value) {
	//value = true => start activity
	//value = false => stop activity
	if (func_type == statemachine::TF_TIME_EVENT) {
		pthread_mutex_lock (&timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
				id)]);
		timeEventFlags[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(id)] =
				value;
		pthread_cond_signal (&timeEventConds[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
				id)]);
		pthread_mutex_unlock(
				&timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
						id)]);
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
						|| id == RESTART_ID || id == SHOWSTOPGUI_ID
						|| id == CHECKMESSAGE_ID || id == RESET_ID
						|| id == PING_ID || id == GETSTATUS_ID
						|| id == LOADCAR_ID || id == DELIVER_ID
						|| id == REWIND_ID || id == ASSEMBLE_ID) {
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
void BackBackControlComponent__Controller::listenTimeEvent(int /*in*/id,
		int /*in*/duration) {
	struct timeval tv;
	struct timespec ts;
	int timedWaitResult = 0;
	while (systemState != statemachine::STOPPED) {
		pthread_mutex_lock (&timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
				id)]);
		while (!timeEventFlags[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(id)]
				&& systemState != statemachine::STOPPED) {
			pthread_cond_wait(
					&timeEventConds[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
							id)],
					&timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
							id)]);
		}

		gettimeofday(&tv, NULL);
		ts.tv_sec = time(NULL) + duration / 1000;
		ts.tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (duration % 1000);
		ts.tv_sec += ts.tv_nsec / (1000 * 1000 * 1000);
		ts.tv_nsec %= (1000 * 1000 * 1000);
		if (systemState != statemachine::STOPPED) {
			timedWaitResult =
					pthread_cond_timedwait(
							&timeEventConds[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
									id)],
							&timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
									id)], &ts);
		}
		bool commitEvent = false;
		if (timedWaitResult != 0) {
			//timeout
			commitEvent = true;
		}
		timeEventFlags[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(id)] =
				false;
		pthread_cond_signal (&timeEventConds[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
				id)]);
		pthread_mutex_unlock(
				&timeEventMutexes[BACKBACKCONTROLCOMPONENT__CONTROLLER_TE_INDEX(
						id)]);
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
void BackBackControlComponent__Controller::regionCall(int /*in*/id,
		char /*in*/enter_mode) {
	(this->*regionTable[id])(enter_mode);
}

/**
 * 
 * @param id 
 */
void BackBackControlComponent__Controller::exitRegionCall(int /*in*/id) {
	(this->*regionExitTable[id])();
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::ErrorDetection>* BackBackControlComponent__Controller::get_pErrDetect() {
	p_origin->pErrDetect.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* BackBackControlComponent__Controller::get_pEndOfMo() {
	p_origin->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* BackBackControlComponent__Controller::get_pLCD() {
	p_origin->pLCD.providedIntf = &(p_origin->ev3Brick.lcdScreen);
	return p_origin->pLCD.providedIntf;
}

/**
 * 
 * @return ret 
 */
::CarFactoryLibrary::IModule* BackBackControlComponent__Controller::get_pModule() {
	p_origin->pModule.providedIntf = this->p_origin;
	return p_origin->pModule.providedIntf;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutStopProcess_Shelf(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	p_origin->pOutStopProcess_Shelf.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutStopProcess_RoboticArm(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	p_origin->pOutStopProcess_RoboticArm.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pStopProcess_Convoyer(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	p_origin->pStopProcess_Convoyer.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutRestart_Shelf(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	p_origin->pOutRestart_Shelf.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutRestart_Convoyer(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	p_origin->pOutRestart_Convoyer.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutRestart_Robotic(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	p_origin->pOutRestart_Robotic.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pPrepare(
		IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>* /*in*/ref) {
	p_origin->pPrepare.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pFloatMotor(
		::CarFactoryLibrary::CommunicationInterfaces::IRoboticArmFloatMotor* /*in*/ref) {
	p_origin->pFloatMotor.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pLargeMotorConvoyer(
		::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* /*in*/ref) {
	p_origin->pLargeMotorConvoyer.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pLargeMotorPress(
		::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* /*in*/ref) {
	p_origin->pLargeMotorPress.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutStopProcess_Press(
		IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* /*in*/ref) {
	p_origin->pOutStopProcess_Press.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutRestart_Press(
		IPush<
				LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* /*in*/ref) {
	p_origin->pOutRestart_Press.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutDelivered(
		IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* /*in*/ref) {
	p_origin->pOutDelivered.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackBackControlComponent__Controller::connect_pOutCheckRack(
		IPush<CarFactoryLibrary::events::CheckRack>* /*in*/ref) {
	p_origin->pOutCheckRack.outIntf = ref;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of BackBackControlComponent__Controller class body
 ************************************************************/
