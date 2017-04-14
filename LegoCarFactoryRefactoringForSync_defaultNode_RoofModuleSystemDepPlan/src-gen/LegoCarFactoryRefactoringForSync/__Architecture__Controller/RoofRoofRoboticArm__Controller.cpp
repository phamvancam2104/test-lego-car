// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_RoofRoofRoboticArm__Controller_BODY

/************************************************************
 RoofRoofRoboticArm__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/RoofRoofRoboticArm__Controller.h"

// Derived includes directives
#include "CarFactoryLibrary/CommunicationInterfaces/IRoboticArmFloatMotor.h"
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofRoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/signals/GoToPress.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 */
void RoofRoofRoboticArm__Controller::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	RoofRoboticArmStateMachine_Region1_Enter (ROOFROBOTICARM_ROOFROBOTICARMSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			ROOFROOFROBOTICARM__CONTROLLER_GET_CONTROL
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
			case ROBOTICARMPICKPIECE_ID:
				::CarFactoryLibrary::events::RoboticArmPickPiece sig_ROBOTICARMPICKPIECE_ID;
				memcpy(&sig_ROBOTICARMPICKPIECE_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::RoboticArmPickPiece));
				processRoboticArmPickPiece(sig_ROBOTICARMPICKPIECE_ID);
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
			ROOFROOFROBOTICARM__CONTROLLER_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void RoofRoofRoboticArm__Controller::RoofRoboticArmStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case ROOFROBOTICARM_ROOFROBOTICARMSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = PRINCIPALSTATE_ID;

		PrincipalState_Region1_Enter (ROOFROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void RoofRoofRoboticArm__Controller::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case ROOFROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT:
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
void RoofRoofRoboticArm__Controller::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (INITIALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (STARTMOTORS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (PICKROOF_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (DELIVERROOF_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (FINALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
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
RoofRoofRoboticArm__Controller::RoofRoofRoboticArm__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Roof::RoofRoboticArm* /*in*/origin) :
		eventQueue(50, eventArray), p_origin(origin) {
	//startBehavior();
}

/**
 * 
 */
void RoofRoofRoboticArm__Controller::startBehavior() {
	systemState = statemachine::IDLE;

	states[DELIVERROOF_ID].hasDoActivity = true;
	// initialize all threads, the threads wait until the associated flag is set
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL,
					&RoofRoofRoboticArm__Controller::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	RoofRoofRoboticArm__Controller_THREAD_CREATE(dispatchThread, dispatchStruct)
}

/**
 * 
 */
RoofRoofRoboticArm__Controller::~RoofRoofRoboticArm__Controller() {
	stopBehavior();
}

/**
 * 
 */
void RoofRoofRoboticArm__Controller::stopBehavior() {
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
void RoofRoofRoboticArm__Controller::processStopProcess(
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
void RoofRoofRoboticArm__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 * @param sig 
 */
void RoofRoofRoboticArm__Controller::processRestartAfterEmergencyStop(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case RESTART_ID:
			//from Restart to PrincipalState
			if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter (ROOFROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT);
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
void RoofRoofRoboticArm__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig,
			RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 * @param sig 
 */
void RoofRoofRoboticArm__Controller::processEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == FINALIZATION_ID) {
		//from Finalization to Initialization
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
void RoofRoofRoboticArm__Controller::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void RoofRoofRoboticArm__Controller::processRoboticArmPickPiece(
		::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == INITIALIZATION_ID) {
		//from Initialization to StartMotors
		if (true) {
			p_origin->save_rack_number(sig);
			states[PRINCIPALSTATE_ID].actives[0] = STARTMOTORS_ID;
			(this->StateEntry)(STARTMOTORS_ID);
			;
			//starting the counters for time events
			//start activity of StartMotors by calling setFlag
			setFlag(STARTMOTORS_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void RoofRoofRoboticArm__Controller::push(
		::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ROBOTICARMPICKPIECE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::RoboticArmPickPiece));
}

/**
 * 
 */
void RoofRoofRoboticArm__Controller::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == STARTMOTORS_ID
			&& (currentEvent->associatedState == STARTMOTORS_ID)) {
		//from StartMotors to PickRoof
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = PICKROOF_ID;
			(this->StateEntry)(PICKROOF_ID);
			;
			//starting the counters for time events
			//start activity of PickRoof by calling setFlag
			setFlag(PICKROOF_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == PICKROOF_ID
			&& (currentEvent->associatedState == PICKROOF_ID)) {
		//from PickRoof to DeliverRoof
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = DELIVERROOF_ID;
			(this->StateEntry)(DELIVERROOF_ID);
			;
			//starting the counters for time events
			//start activity of DeliverRoof by calling setFlag
			setFlag(DELIVERROOF_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == DELIVERROOF_ID
			&& (currentEvent->associatedState == DELIVERROOF_ID)) {
		//from DeliverRoof to Finalization
		if (true) {
			//signal to exit the doActivity of DeliverRoof
			setFlag(DELIVERROOF_ID, statemachine::TF_DO_ACTIVITY, false);
			states[PRINCIPALSTATE_ID].actives[0] = FINALIZATION_ID;
			(this->StateEntry)(FINALIZATION_ID);
			;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void RoofRoofRoboticArm__Controller::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case INITIALIZATION_ID:
		p_origin->init();
		break;
	case STARTMOTORS_ID:
		p_origin->start_motors();
		break;
	case PICKROOF_ID:
		p_origin->pick_roof();
		break;
	case DELIVERROOF_ID:
		p_origin->deliver_roof();
		break;
	case FINALIZATION_ID:
		p_origin->stop_motors();
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
void RoofRoofRoboticArm__Controller::StateExit(unsigned int /*in*/id) {
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
void RoofRoofRoboticArm__Controller::StateDoActivity(unsigned int /*in*/id) {
	switch (id) {
	case DELIVERROOF_ID:
		p_origin->sendGoToPressEvent();
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
void* RoofRoofRoboticArm__Controller::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	RoofRoofRoboticArm__Controller* ptr =
			(RoofRoofRoboticArm__Controller*) cptr->ptr;
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
void RoofRoofRoboticArm__Controller::doCallActivity(int /*in*/id) {
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
			if (id == STARTMOTORS_ID || id == PICKROOF_ID
					|| id == DELIVERROOF_ID) {
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
void RoofRoofRoboticArm__Controller::setFlag(int /*in*/id, char /*in*/func_type,
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
				if (id == STARTMOTORS_ID || id == PICKROOF_ID
						|| id == DELIVERROOF_ID) {
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
IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* RoofRoofRoboticArm__Controller::get_pInRestart() {
	p_origin->pInRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* RoofRoofRoboticArm__Controller::get_pEndOfMo() {
	p_origin->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* RoofRoofRoboticArm__Controller::get_pPickPiece() {
	p_origin->pPickPiece.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* RoofRoofRoboticArm__Controller::get_pInStopProcess() {
	p_origin->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::CarFactoryLibrary::CommunicationInterfaces::IRoboticArmFloatMotor* RoofRoofRoboticArm__Controller::get_pFloatMotor() {
	p_origin->pFloatMotor.providedIntf = this->p_origin;
	return p_origin->pFloatMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* RoofRoofRoboticArm__Controller::get_upDownMotor() {
	p_origin->upDownMotor.providedIntf = &(p_origin->motor_up_down);
	return p_origin->upDownMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* RoofRoofRoboticArm__Controller::get_frontBackMotor() {
	p_origin->frontBackMotor.providedIntf = &(p_origin->motor_up_down);
	return p_origin->frontBackMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* RoofRoofRoboticArm__Controller::get_rightLeftMotor() {
	p_origin->rightLeftMotor.providedIntf = &(p_origin->motor_up_down);
	return p_origin->rightLeftMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* RoofRoofRoboticArm__Controller::get_plierMotor() {
	p_origin->plierMotor.providedIntf = &(p_origin->motor_up_down);
	return p_origin->plierMotor.providedIntf;
}

/**
 * 
 * @param ref 
 */
void RoofRoofRoboticArm__Controller::connect_pDelivered(
		IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* /*in*/ref) {
	p_origin->pDelivered.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void RoofRoofRoboticArm__Controller::connect_pOutGotoProcess(
		IPush<LegoCarFactoryRefactoringForSync::signals::GoToPress>* /*in*/ref) {
	p_origin->pOutGotoProcess.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void RoofRoofRoboticArm__Controller::connect_pLCD(
		::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref) {
	p_origin->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void RoofRoofRoboticArm__Controller::connect_pModule(
		::CarFactoryLibrary::IModule* /*in*/ref) {
	p_origin->pModule.requiredIntf = ref;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of RoofRoofRoboticArm__Controller class body
 ************************************************************/