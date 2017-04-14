// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_SlavesSlaveShelf__Controller_BODY

/************************************************************
 SlavesSlaveShelf__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/SlavesSlaveShelf__Controller.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "EV3PapyrusLibrary/IColorSensor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/SlaveShelf.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 */
void SlavesSlaveShelf__Controller::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	SlaveShelfStateMachine_Region1_Enter (SLAVESHELF_SLAVESHELFSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			SLAVESSLAVESHELF__CONTROLLER_GET_CONTROL
			switch (currentEvent->eventID) {
			case STOPPROCESS_ID:
				::LegoCarFactoryRefactoringForSync::signals::StopProcess sig_STOPPROCESS_ID;
				memcpy(&sig_STOPPROCESS_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
				processStopProcess(sig_STOPPROCESS_ID);
				break;
			case RESTARTAFTEREMERGENCYSTOP_ID:
				::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop sig_RESTARTAFTEREMERGENCYSTOP_ID;
				memcpy(&sig_RESTARTAFTEREMERGENCYSTOP_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
				processRestartAfterEmergencyStop(
						sig_RESTARTAFTEREMERGENCYSTOP_ID);
				break;
			case ENDOFMODULE_ID:
				::CarFactoryLibrary::events::EndOfModule sig_ENDOFMODULE_ID;
				memcpy(&sig_ENDOFMODULE_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::EndOfModule));
				processEndOfModule(sig_ENDOFMODULE_ID);
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
			SLAVESSLAVESHELF__CONTROLLER_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void SlavesSlaveShelf__Controller::SlaveShelfStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case SLAVESHELF_SLAVESHELFSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = PRINCIPALSTATE_ID;

		PrincipalState_Region1_Enter (SLAVESHELF_PRINCIPALSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void SlavesSlaveShelf__Controller::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case SLAVESHELF_PRINCIPALSTATE_REGION1_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;

		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVESHELF_PRINCIPALSTATE_REGION1_WHICH_RACK:
		if (p_origin->fromWhich_racktoNoEmptyRackGuard()) {
			states[PRINCIPALSTATE_ID].actives[0] = NOEMPTYRACK_ID;
			(this->StateEntry)(NOEMPTYRACK_ID);
			;
			//starting the counters for time events
			//start activity of NoEmptyRack by calling setFlag
			setFlag(NOEMPTYRACK_ID, statemachine::TF_DO_ACTIVITY, true);
		} else {
			states[PRINCIPALSTATE_ID].actives[0] = EMPTYRACK_ID;
			(this->StateEntry)(EMPTYRACK_ID);
			;
			//starting the counters for time events
			//start activity of EmptyRack by calling setFlag
			setFlag(EMPTYRACK_ID, statemachine::TF_DO_ACTIVITY, true);
		}
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVESHELF_PRINCIPALSTATE_REGION1_INITIALIZATION:
		states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;
		//starting the counters for time events
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVESHELF_PRINCIPALSTATE_REGION1_EMPTYRACK:
		states[PRINCIPALSTATE_ID].actives[0] = EMPTYRACK_ID;
		(this->StateEntry)(EMPTYRACK_ID);
		;
		//starting the counters for time events
		//start activity of EmptyRack by calling setFlag
		setFlag(EMPTYRACK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVESHELF_PRINCIPALSTATE_REGION1_NOEMPTYRACK:
		states[PRINCIPALSTATE_ID].actives[0] = NOEMPTYRACK_ID;
		(this->StateEntry)(NOEMPTYRACK_ID);
		;
		//starting the counters for time events
		//start activity of NoEmptyRack by calling setFlag
		setFlag(NOEMPTYRACK_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVESHELF_PRINCIPALSTATE_REGION1_WAITEND:
		states[PRINCIPALSTATE_ID].actives[0] = WAITEND_ID;
		//starting the counters for time events
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void SlavesSlaveShelf__Controller::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (INITIALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (EMPTYRACK_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (NOEMPTYRACK_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (WAITEND_ID == states[PRINCIPALSTATE_ID].actives[0]) {
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
SlavesSlaveShelf__Controller::SlavesSlaveShelf__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Slaves::SlaveShelf* /*in*/origin) :
		eventQueue(50, eventArray), p_origin(origin) {
	//startBehavior();
}

/**
 * 
 */
void SlavesSlaveShelf__Controller::startBehavior() {
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
					&SlavesSlaveShelf__Controller::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	SlavesSlaveShelf__Controller_THREAD_CREATE(dispatchThread, dispatchStruct)
}

/**
 * 
 */
SlavesSlaveShelf__Controller::~SlavesSlaveShelf__Controller() {
	stopBehavior();
}

/**
 * 
 */
void SlavesSlaveShelf__Controller::stopBehavior() {
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
void SlavesSlaveShelf__Controller::processStopProcess(
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
void SlavesSlaveShelf__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 * @param sig 
 */
void SlavesSlaveShelf__Controller::processRestartAfterEmergencyStop(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case RESTART_ID:
			//from Restart to PrincipalState
			if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter (SLAVESHELF_PRINCIPALSTATE_REGION1_DEFAULT);
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
void SlavesSlaveShelf__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig,
			RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 * @param sig 
 */
void SlavesSlaveShelf__Controller::processEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == WAITEND_ID) {
		//from WaitEnd to Initialization
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
void SlavesSlaveShelf__Controller::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void SlavesSlaveShelf__Controller::processCheckRack(
		::CarFactoryLibrary::events::CheckRack& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == INITIALIZATION_ID) {
		//from Initialization to Which_rack
		if (true) {
			p_origin->save_which_rack(sig);
			if (p_origin->fromWhich_racktoNoEmptyRackGuard()) {
				states[PRINCIPALSTATE_ID].actives[0] = NOEMPTYRACK_ID;
				(this->StateEntry)(NOEMPTYRACK_ID);
				;
				//starting the counters for time events
				//start activity of NoEmptyRack by calling setFlag
				setFlag(NOEMPTYRACK_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				states[PRINCIPALSTATE_ID].actives[0] = EMPTYRACK_ID;
				(this->StateEntry)(EMPTYRACK_ID);
				;
				//starting the counters for time events
				//start activity of EmptyRack by calling setFlag
				setFlag(EMPTYRACK_ID, statemachine::TF_DO_ACTIVITY, true);
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void SlavesSlaveShelf__Controller::push(
		::CarFactoryLibrary::events::CheckRack& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, CHECKRACK_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::CheckRack));
}

/**
 * 
 */
void SlavesSlaveShelf__Controller::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == EMPTYRACK_ID
			&& (currentEvent->associatedState == EMPTYRACK_ID)) {
		//from EmptyRack to WaitEnd
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = WAITEND_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == NOEMPTYRACK_ID
			&& (currentEvent->associatedState == NOEMPTYRACK_ID)) {
		//from NoEmptyRack to WaitEnd
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = WAITEND_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void SlavesSlaveShelf__Controller::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case EMPTYRACK_ID:
		p_origin->sendErrorDetectionEvent();
		break;
	case NOEMPTYRACK_ID:
		p_origin->sendRoboticArmPickPieceEvent();
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
void SlavesSlaveShelf__Controller::StateExit(unsigned int /*in*/id) {
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
void SlavesSlaveShelf__Controller::StateDoActivity(unsigned int /*in*/id) {
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
void* SlavesSlaveShelf__Controller::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	SlavesSlaveShelf__Controller* ptr =
			(SlavesSlaveShelf__Controller*) cptr->ptr;
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
void SlavesSlaveShelf__Controller::doCallActivity(int /*in*/id) {
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
			if (id == EMPTYRACK_ID || id == NOEMPTYRACK_ID) {
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
void SlavesSlaveShelf__Controller::setFlag(int /*in*/id, char /*in*/func_type,
		bool /*in*/value) {
	//value = true => start activity
	//value = false => stop activity
	if (func_type == statemachine::TF_DO_ACTIVITY) {
		//push completion event
		if (value) {
			if (id == EMPTYRACK_ID || id == NOEMPTYRACK_ID) {
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
IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* SlavesSlaveShelf__Controller::get_pInStopProcess() {
	p_origin->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* SlavesSlaveShelf__Controller::get_pInRestart() {
	p_origin->pInRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::CheckRack>* SlavesSlaveShelf__Controller::get_pCheckRack() {
	p_origin->pCheckRack.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* SlavesSlaveShelf__Controller::get_pEndOfMo() {
	p_origin->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* SlavesSlaveShelf__Controller::get_sensor1() {
	p_origin->sensor1.providedIntf = &(p_origin->rack_1.color_sensor);
	return p_origin->sensor1.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* SlavesSlaveShelf__Controller::get_sensor2() {
	p_origin->sensor2.providedIntf = &(p_origin->rack_1.color_sensor);
	return p_origin->sensor2.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* SlavesSlaveShelf__Controller::get_sensor3() {
	p_origin->sensor3.providedIntf = &(p_origin->rack_1.color_sensor);
	return p_origin->sensor3.providedIntf;
}

/**
 * 
 * @param ref 
 */
void SlavesSlaveShelf__Controller::connect_pErrDetect(
		IPush<CarFactoryLibrary::events::ErrorDetection>* /*in*/ref) {
	p_origin->pErrDetect.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void SlavesSlaveShelf__Controller::connect_pPickPiece(
		IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* /*in*/ref) {
	p_origin->pPickPiece.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void SlavesSlaveShelf__Controller::connect_pLCD(
		::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref) {
	p_origin->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void SlavesSlaveShelf__Controller::connect_pModule(
		::CarFactoryLibrary::IModule* /*in*/ref) {
	p_origin->pModule.requiredIntf = ref;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SlavesSlaveShelf__Controller class body
 ************************************************************/
