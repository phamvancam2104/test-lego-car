// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_SlavesSlavePress__Controller_BODY

/************************************************************
 SlavesSlavePress__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/SlavesSlavePress__Controller.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/PressAssemble.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/SlavePress.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 */
void SlavesSlavePress__Controller::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	SlavePressStateMachine_Region1_Enter (SLAVEPRESS_SLAVEPRESSSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			SLAVESSLAVEPRESS__CONTROLLER_GET_CONTROL
			switch (currentEvent->eventID) {
			case PRESSASSEMBLE_ID:
				::CarFactoryLibrary::events::PressAssemble sig_PRESSASSEMBLE_ID;
				memcpy(&sig_PRESSASSEMBLE_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::PressAssemble));
				processPressAssemble(sig_PRESSASSEMBLE_ID);
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
			case STOPPROCESS_ID:
				::LegoCarFactoryRefactoringForSync::signals::StopProcess sig_STOPPROCESS_ID;
				memcpy(&sig_STOPPROCESS_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
				processStopProcess(sig_STOPPROCESS_ID);
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
			SLAVESSLAVEPRESS__CONTROLLER_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void SlavesSlavePress__Controller::SlavePressStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case SLAVEPRESS_SLAVEPRESSSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = PRINCIPALSTATE_ID;

		PrincipalState_Region1_Enter (SLAVEPRESS_PRINCIPALSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void SlavesSlavePress__Controller::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case SLAVEPRESS_PRINCIPALSTATE_REGION1_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;

		(this->StateEntry)(INITIALIZATION_ID);
		;
		//starting the counters for time events

		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVEPRESS_PRINCIPALSTATE_REGION1_SETSTATUSISREADY:
		states[PRINCIPALSTATE_ID].actives[0] = SETSTATUSISREADY_ID;
		(this->StateEntry)(SETSTATUSISREADY_ID);
		;
		//starting the counters for time events
		//start activity of SetStatusIsReady by calling setFlag
		setFlag(SETSTATUSISREADY_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVEPRESS_PRINCIPALSTATE_REGION1_LIFTUP:
		states[PRINCIPALSTATE_ID].actives[0] = LIFTUP_ID;
		(this->StateEntry)(LIFTUP_ID);
		;
		//starting the counters for time events
		//start activity of LiftUp by calling setFlag
		setFlag(LIFTUP_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVEPRESS_PRINCIPALSTATE_REGION1_PRESS:
		states[PRINCIPALSTATE_ID].actives[0] = PRESS_ID;
		//starting the counters for time events
		//start activity of Press by calling setFlag
		setFlag(PRESS_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case SLAVEPRESS_PRINCIPALSTATE_REGION1_INITIALIZATION:
		states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;
		(this->StateEntry)(INITIALIZATION_ID);
		;
		//starting the counters for time events
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void SlavesSlavePress__Controller::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (SETSTATUSISREADY_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (LIFTUP_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (GOTOPPRESS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (PRESS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (INITIALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
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
SlavesSlavePress__Controller::SlavesSlavePress__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Slaves::SlavePress* /*in*/origin) :
		eventQueue(50, eventArray), p_origin(origin) {
	//startBehavior();
}

/**
 * 
 */
void SlavesSlavePress__Controller::startBehavior() {
	systemState = statemachine::IDLE;

	states[PRESS_ID].hasDoActivity = true;
	// initialize all threads, the threads wait until the associated flag is set
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL,
					&SlavesSlavePress__Controller::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	SlavesSlavePress__Controller_THREAD_CREATE(dispatchThread, dispatchStruct)
}

/**
 * 
 */
SlavesSlavePress__Controller::~SlavesSlavePress__Controller() {
	stopBehavior();
}

/**
 * 
 */
void SlavesSlavePress__Controller::stopBehavior() {
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
void SlavesSlavePress__Controller::processPressAssemble(
		::CarFactoryLibrary::events::PressAssemble& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == INITIALIZATION_ID) {
		//from Initialization to Press
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = PRESS_ID;
			//starting the counters for time events
			//start activity of Press by calling setFlag
			setFlag(PRESS_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void SlavesSlavePress__Controller::push(
		::CarFactoryLibrary::events::PressAssemble& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, PRESSASSEMBLE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::PressAssemble));
}

/**
 * 
 * @param sig 
 */
void SlavesSlavePress__Controller::processEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == SETSTATUSISREADY_ID) {
		//from SetStatusIsReady to Initialization
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;
			(this->StateEntry)(INITIALIZATION_ID);
			;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void SlavesSlavePress__Controller::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void SlavesSlavePress__Controller::processRestartAfterEmergencyStop(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case RESTART_ID:
			//from Restart to PrincipalState
			if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter (SLAVEPRESS_PRINCIPALSTATE_REGION1_DEFAULT);
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
void SlavesSlavePress__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig,
			RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 * @param sig 
 */
void SlavesSlavePress__Controller::processStopProcess(
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
void SlavesSlavePress__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 */
void SlavesSlavePress__Controller::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == GOTOPPRESS_ID
			&& (currentEvent->associatedState == GOTOPPRESS_ID)) {
		//from GoTopPress to SetStatusIsReady
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = SETSTATUSISREADY_ID;
			(this->StateEntry)(SETSTATUSISREADY_ID);
			;
			//starting the counters for time events
			//start activity of SetStatusIsReady by calling setFlag
			setFlag(SETSTATUSISREADY_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == PRESS_ID
			&& (currentEvent->associatedState == PRESS_ID)) {
		//from Press to LiftUp
		if (true) {
			//signal to exit the doActivity of Press
			setFlag(PRESS_ID, statemachine::TF_DO_ACTIVITY, false);
			states[PRINCIPALSTATE_ID].actives[0] = LIFTUP_ID;
			(this->StateEntry)(LIFTUP_ID);
			;
			//starting the counters for time events
			//start activity of LiftUp by calling setFlag
			setFlag(LIFTUP_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == LIFTUP_ID
			&& (currentEvent->associatedState == LIFTUP_ID)) {
		//from LiftUp to choice
		if (true) {
			if (p_origin->fromChoicetoGoTopPressGuard()) {
				states[PRINCIPALSTATE_ID].actives[0] = GOTOPPRESS_ID;
				(this->StateEntry)(GOTOPPRESS_ID);
				;
				//starting the counters for time events
				//start activity of GoTopPress by calling setFlag
				setFlag(GOTOPPRESS_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				p_origin->effectFromChoicetoPress();
				states[PRINCIPALSTATE_ID].actives[0] = PRESS_ID;
				//starting the counters for time events
				//start activity of Press by calling setFlag
				setFlag(PRESS_ID, statemachine::TF_DO_ACTIVITY, true);
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void SlavesSlavePress__Controller::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case SETSTATUSISREADY_ID:
		p_origin->SetStatusIsReady();
		break;
	case LIFTUP_ID:
		p_origin->lift_up();
		break;
	case GOTOPPRESS_ID:
		p_origin->go_top();
		break;
	case INITIALIZATION_ID:
		p_origin->init();
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
void SlavesSlavePress__Controller::StateExit(unsigned int /*in*/id) {
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
void SlavesSlavePress__Controller::StateDoActivity(unsigned int /*in*/id) {
	switch (id) {
	case PRESS_ID:
		p_origin->assemble();
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
void* SlavesSlavePress__Controller::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	SlavesSlavePress__Controller* ptr =
			(SlavesSlavePress__Controller*) cptr->ptr;
	switch (cptr->func_type) {
	case statemachine::TF_DO_ACTIVITY:
		ptr->doCallActivity(cptr->id);
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
void SlavesSlavePress__Controller::doCallActivity(int /*in*/id) {
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
			if (id == SETSTATUSISREADY_ID || id == LIFTUP_ID
					|| id == GOTOPPRESS_ID || id == PRESS_ID) {
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
void SlavesSlavePress__Controller::setFlag(int /*in*/id, char /*in*/func_type,
		bool /*in*/value) {
	//value = true => start activity
	//value = false => stop activity
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
				if (id == SETSTATUSISREADY_ID || id == LIFTUP_ID
						|| id == GOTOPPRESS_ID || id == PRESS_ID) {
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
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* SlavesSlavePress__Controller::get_pInStopProcess() {
	p_origin->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* SlavesSlavePress__Controller::get_pEndOfMo() {
	p_origin->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::PressAssemble>* SlavesSlavePress__Controller::get_pPressAssemble() {
	p_origin->pPressAssemble.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* SlavesSlavePress__Controller::get_pInRestart() {
	p_origin->pInRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* SlavesSlavePress__Controller::get_pILargeMotor() {
	p_origin->pILargeMotor.providedIntf = &(p_origin->motor);
	return p_origin->pILargeMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* SlavesSlavePress__Controller::get_motor_port() {
	p_origin->motor_port.providedIntf = &(p_origin->motor);
	return p_origin->motor_port.providedIntf;
}

/**
 * 
 * @param ref 
 */
void SlavesSlavePress__Controller::connect_pLCD(
		::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref) {
	p_origin->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void SlavesSlavePress__Controller::connect_pModule(
		::CarFactoryLibrary::IModule* /*in*/ref) {
	p_origin->pModule.requiredIntf = ref;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SlavesSlavePress__Controller class body
 ************************************************************/
