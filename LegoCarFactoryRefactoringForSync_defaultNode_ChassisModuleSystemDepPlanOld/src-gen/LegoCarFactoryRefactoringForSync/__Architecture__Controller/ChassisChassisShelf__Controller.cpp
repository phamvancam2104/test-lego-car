// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_ChassisChassisShelf__Controller_BODY

/************************************************************
 ChassisChassisShelf__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ChassisChassisShelf__Controller.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "EV3PapyrusLibrary/IColorSensor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisShelf.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 */
void ChassisChassisShelf__Controller::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	ChassisShelfStateMachine_Region1_Enter (CHASSISSHELF_CHASSISSHELFSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			CHASSISCHASSISSHELF__CONTROLLER_GET_CONTROL
			switch (currentEvent->eventID) {
			case STOPPROCESS_ID:
				::LegoCarFactoryRefactoringForSync::signals::StopProcess sig_STOPPROCESS_ID;
				memcpy(&sig_STOPPROCESS_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
				processStopProcess(sig_STOPPROCESS_ID);
				break;
			case ENDOFMODULE_ID:
				::CarFactoryLibrary::events::EndOfModule sig_ENDOFMODULE_ID;
				memcpy(&sig_ENDOFMODULE_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::EndOfModule));
				processEndOfModule(sig_ENDOFMODULE_ID);
				break;
			case RESTARTAFTEREMERGENCYSTOP_ID:
				::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop sig_RESTARTAFTEREMERGENCYSTOP_ID;
				memcpy(&sig_RESTARTAFTEREMERGENCYSTOP_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
				processRestartAfterEmergencyStop(
						sig_RESTARTAFTEREMERGENCYSTOP_ID);
				break;
			case CHECKRACK_ID:
				::CarFactoryLibrary::events::CheckRack sig_CHECKRACK_ID;
				memcpy(&sig_CHECKRACK_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::CheckRack));
				processCheckRack(sig_CHECKRACK_ID);
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
			CHASSISCHASSISSHELF__CONTROLLER_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void ChassisChassisShelf__Controller::ChassisShelfStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case CHASSISSHELF_CHASSISSHELFSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = PRINCIPALSTATE_ID;

		PrincipalState_Region1_Enter (CHASSISSHELF_PRINCIPALSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_CHASSISSHELFSTATEMACHINE_REGION1_RESTART:
		activeStateID = RESTART_ID;
		//starting the counters for time events
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void ChassisChassisShelf__Controller::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;

		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_WAIT_END:
		states[PRINCIPALSTATE_ID].actives[0] = WAIT_END_ID;
		//starting the counters for time events
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_EMPTY_RACK:
		states[PRINCIPALSTATE_ID].actives[0] = EMPTY_RACK_ID;
		//starting the counters for time events
		//start activity of Empty_rack by calling setFlag
		setFlag(EMPTY_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_DISPLAY:
		states[PRINCIPALSTATE_ID].actives[0] = DISPLAY_ID;
		//starting the counters for time events
		//start activity of Display by calling setFlag
		setFlag(DISPLAY_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_INITIALIZATION:
		states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;
		//starting the counters for time events
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_FIRST_RACK:
		states[PRINCIPALSTATE_ID].actives[0] = FIRST_RACK_ID;
		//starting the counters for time events
		//start activity of First_rack by calling setFlag
		setFlag(FIRST_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case CHASSISSHELF_PRINCIPALSTATE_REGION1_SECOND_RACK:
		states[PRINCIPALSTATE_ID].actives[0] = SECOND_RACK_ID;
		//starting the counters for time events
		//start activity of Second_rack by calling setFlag
		setFlag(SECOND_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void ChassisChassisShelf__Controller::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (NOT_MASTER_MODULE_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (WAITSLAVEISNOTBUSY_ID
				== states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (WAIT_END_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (EMPTY_RACK_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (DISPLAY_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (INITIALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (FIRST_RACK_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (SECOND_RACK_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		}
		//exit action of sub-state of PrincipalState
		StateExit(states[PRINCIPALSTATE_ID].actives[0]);
		//set active sub-state of PrincipalState to STATE_MAX meaning NULL
		states[PRINCIPALSTATE_ID].actives[0] = STATE_MAX;
	}
}

/**
 * 
 * @param origin 
 */
ChassisChassisShelf__Controller::ChassisChassisShelf__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf* /*in*/origin) :
		eventQueue(50, eventArray), p_origin(origin) {
	//startBehavior();
}

/**
 * 
 */
void ChassisChassisShelf__Controller::startBehavior() {
	systemState = statemachine::IDLE;

	// initialize all threads, the threads wait until the associated flag is set
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL,
					&ChassisChassisShelf__Controller::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	ChassisChassisShelf__Controller_THREAD_CREATE(dispatchThread,
			dispatchStruct)
}

/**
 * 
 */
ChassisChassisShelf__Controller::~ChassisChassisShelf__Controller() {
	stopBehavior();
}

/**
 * 
 */
void ChassisChassisShelf__Controller::stopBehavior() {
	systemState = statemachine::STOPPED;
	//signal and wait for doActivity termination
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			pthread_cond_signal (&conds[i]);
			pthread_join(threads[i], NULL);
		}
	}

	//signal and wait for time event thread termination

	//main thread
	pthread_join(dispatchThread, NULL);

}

/**
 * 
 * @param sig 
 */
void ChassisChassisShelf__Controller::processStopProcess(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case PRINCIPALSTATE_ID:
			//from PrincipalState to Restart
			if (true) {
				PrincipalState_Region1_Exit();
				activeStateID = RESTART_ID;
				//starting the counters for time events
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
 * @param sig 
 */
void ChassisChassisShelf__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 * @param sig 
 */
void ChassisChassisShelf__Controller::processEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == WAIT_END_ID) {
		//from Wait_end to Initialization
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void ChassisChassisShelf__Controller::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void ChassisChassisShelf__Controller::processRestartAfterEmergencyStop(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case RESTART_ID:
			//from Restart to PrincipalState
			if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter (CHASSISSHELF_PRINCIPALSTATE_REGION1_DEFAULT);
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
 * @param sig 
 */
void ChassisChassisShelf__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig,
			RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 * @param sig 
 */
void ChassisChassisShelf__Controller::processCheckRack(
		::CarFactoryLibrary::events::CheckRack& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == INITIALIZATION_ID) {
		//from Initialization to Display
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = DISPLAY_ID;
			//starting the counters for time events
			//start activity of Display by calling setFlag
			setFlag(DISPLAY_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void ChassisChassisShelf__Controller::push(
		::CarFactoryLibrary::events::CheckRack& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, CHECKRACK_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::CheckRack));
}

/**
 * 
 */
void ChassisChassisShelf__Controller::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == EMPTY_RACK_ID
			&& (currentEvent->associatedState == EMPTY_RACK_ID)) {
		//from Empty_rack to Wait_end
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = WAIT_END_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == SECOND_RACK_ID
			&& (currentEvent->associatedState == SECOND_RACK_ID)) {
		//from Second_rack to Wait_end
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = WAIT_END_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == FIRST_RACK_ID
			&& (currentEvent->associatedState == FIRST_RACK_ID)) {
		//from First_rack to Wait_end
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = WAIT_END_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == NOT_MASTER_MODULE_ID
			&& (currentEvent->associatedState == NOT_MASTER_MODULE_ID)) {
		//from Not_Master_Module to WaitSlaveIsNotBusy
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = WAITSLAVEISNOTBUSY_ID;
			//starting the counters for time events
			//start activity of WaitSlaveIsNotBusy by calling setFlag
			setFlag(WAITSLAVEISNOTBUSY_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == WAITSLAVEISNOTBUSY_ID
			&& (currentEvent->associatedState == WAITSLAVEISNOTBUSY_ID)) {
		//from WaitSlaveIsNotBusy to choice
		if (true) {
			if (p_origin->fromChoicetoWait_endGuard()) {
				states[PRINCIPALSTATE_ID].actives[0] = WAIT_END_ID;
				//starting the counters for time events
			} else if (p_origin->fromChoicetoEmpty_rackGuard()) {
				states[PRINCIPALSTATE_ID].actives[0] = EMPTY_RACK_ID;
				//starting the counters for time events
				//start activity of Empty_rack by calling setFlag
				setFlag(EMPTY_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				PrincipalState_Region1_Exit();
				activeStateID = RESTART_ID;
				//starting the counters for time events
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == DISPLAY_ID
			&& (currentEvent->associatedState == DISPLAY_ID)) {
		//from Display to test
		if (true) {
			if (p_origin->fromTesttoNot_Master_ModuleGuard()) {
				states[PRINCIPALSTATE_ID].actives[0] = NOT_MASTER_MODULE_ID;
				//starting the counters for time events
				//start activity of Not_Master_Module by calling setFlag
				setFlag(NOT_MASTER_MODULE_ID, statemachine::TF_DO_ACTIVITY,
						true);
			} else {
				if (p_origin->fromWhich_racktoFirst_rackGuard()) {
					states[PRINCIPALSTATE_ID].actives[0] = FIRST_RACK_ID;
					//starting the counters for time events
					//start activity of First_rack by calling setFlag
					setFlag(FIRST_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
				} else if (p_origin->fromWhich_racktoSecond_rackGuard()) {
					states[PRINCIPALSTATE_ID].actives[0] = SECOND_RACK_ID;
					//starting the counters for time events
					//start activity of Second_rack by calling setFlag
					setFlag(SECOND_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
				} else {
					states[PRINCIPALSTATE_ID].actives[0] = EMPTY_RACK_ID;
					//starting the counters for time events
					//start activity of Empty_rack by calling setFlag
					setFlag(EMPTY_RACK_ID, statemachine::TF_DO_ACTIVITY, true);
				}
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void ChassisChassisShelf__Controller::StateEntry(unsigned int /*in*/id) {
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
void ChassisChassisShelf__Controller::StateExit(unsigned int /*in*/id) {
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
void ChassisChassisShelf__Controller::StateDoActivity(unsigned int /*in*/id) {
	switch (id) {
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
void* ChassisChassisShelf__Controller::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	ChassisChassisShelf__Controller* ptr =
			(ChassisChassisShelf__Controller*) cptr->ptr;
	switch (cptr->func_type) {
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
void ChassisChassisShelf__Controller::doCallActivity(int /*in*/id) {
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
			if (id == NOT_MASTER_MODULE_ID || id == WAITSLAVEISNOTBUSY_ID
					|| id == EMPTY_RACK_ID || id == DISPLAY_ID
					|| id == FIRST_RACK_ID || id == SECOND_RACK_ID) {
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
void ChassisChassisShelf__Controller::setFlag(int /*in*/id,
		char /*in*/func_type, bool /*in*/value) {
	//value = true => start activity
	//value = false => stop activity
	if (func_type == statemachine::TF_DO_ACTIVITY) {
		//push completion event
		if (value) {
			if (id == NOT_MASTER_MODULE_ID || id == WAITSLAVEISNOTBUSY_ID
					|| id == EMPTY_RACK_ID || id == DISPLAY_ID
					|| id == FIRST_RACK_ID || id == SECOND_RACK_ID) {
				eventQueue.push(statemachine::PRIORITY_1, NULL,
						COMPLETIONEVENT_ID, statemachine::COMPLETION_EVENT, id);
			}
			return;
		}
	}
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* ChassisChassisShelf__Controller::get_pInStopProcess() {
	p_origin->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* ChassisChassisShelf__Controller::get_pInRestart() {
	p_origin->pInRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::CheckRack>* ChassisChassisShelf__Controller::get_pCheckRack() {
	p_origin->pCheckRack.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* ChassisChassisShelf__Controller::get_pEndOfMo() {
	p_origin->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* ChassisChassisShelf__Controller::get_sensor1() {
	p_origin->sensor1.providedIntf = &(p_origin->rack_1.color_sensor);
	return p_origin->sensor1.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* ChassisChassisShelf__Controller::get_sensor2() {
	p_origin->sensor2.providedIntf = &(p_origin->rack_1.color_sensor);
	return p_origin->sensor2.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* ChassisChassisShelf__Controller::get_sensor3() {
	p_origin->sensor3.providedIntf = &(p_origin->rack_1.color_sensor);
	return p_origin->sensor3.providedIntf;
}

/**
 * 
 * @param ref 
 */
void ChassisChassisShelf__Controller::connect_pErrDetect(
		IPush<CarFactoryLibrary::events::ErrorDetection>* /*in*/ref) {
	p_origin->pErrDetect.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void ChassisChassisShelf__Controller::connect_pPickPiece(
		IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* /*in*/ref) {
	p_origin->pPickPiece.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void ChassisChassisShelf__Controller::connect_pLCD(
		::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref) {
	p_origin->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void ChassisChassisShelf__Controller::connect_pModule(
		::CarFactoryLibrary::IModule* /*in*/ref) {
	p_origin->pModule.requiredIntf = ref;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisChassisShelf__Controller class body
 ************************************************************/
