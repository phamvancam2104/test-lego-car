// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_Back_BackRoboticArm__Delegatee_BODY

/************************************************************
 BackRoboticArm__Delegatee class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Back/BackRoboticArm__Delegatee.h"

// Derived includes directives
#include "CarFactoryLibrary/CommunicationInterfaces/IRoboticArmFloatMotor.h"
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackRoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/signals/GoToPress.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Back {

// static attributes (if any)

/**
 * 
 */
void BackRoboticArm__Delegatee::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	BackRoboticArmStateMachine_Region1_Enter (BACKROBOTICARM_BACKROBOTICARMSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			BACKROBOTICARM__DELEGATEE_GET_CONTROL
			switch (currentEvent->eventID) {
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
			BACKROBOTICARM__DELEGATEE_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void BackRoboticArm__Delegatee::BackRoboticArmStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case BACKROBOTICARM_BACKROBOTICARMSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = PRINCIPALSTATE_ID;

		PrincipalState_Region1_Enter (BACKROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void BackRoboticArm__Delegatee::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case BACKROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT:
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
void BackRoboticArm__Delegatee::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (INITIALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (STARTMOTORS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (PICKBACKPART_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (RETAKEBACKPART_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (DELIVERBACKPART_ID == states[PRINCIPALSTATE_ID].actives[0]) {
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
 */
BackRoboticArm__Delegatee::BackRoboticArm__Delegatee() :
		systemState(statemachine::IDLE) {
	//startBehavior();
}

/**
 * 
 */
void BackRoboticArm__Delegatee::startBehavior() {
	states[DELIVERBACKPART_ID].hasDoActivity = true;
	// initialize all threads, the threads wait until the associated flag is set
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL,
					&BackRoboticArm__Delegatee::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	BackRoboticArm__Delegatee_THREAD_CREATE(dispatchThread, dispatchStruct)
}

/**
 * 
 */
BackRoboticArm__Delegatee::~BackRoboticArm__Delegatee() {
	stopBehavior();
}

/**
 * 
 */
void BackRoboticArm__Delegatee::stopBehavior() {
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
void BackRoboticArm__Delegatee::processRestartAfterEmergencyStop(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case RESTART_ID:
			//from Restart to PrincipalState
			if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter (BACKROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT);
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
void BackRoboticArm__Delegatee::push(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig,
			RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 * @param sig 
 */
void BackRoboticArm__Delegatee::processEndOfModule(
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
void BackRoboticArm__Delegatee::push(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void BackRoboticArm__Delegatee::processRoboticArmPickPiece(
		::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == INITIALIZATION_ID) {
		//from Initialization to StartMotors
		if (true) {
			component->save_rack_number(sig);
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
void BackRoboticArm__Delegatee::push(
		::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ROBOTICARMPICKPIECE_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::RoboticArmPickPiece));
}

/**
 * 
 * @param sig 
 */
void BackRoboticArm__Delegatee::processStopProcess(
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
void BackRoboticArm__Delegatee::push(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 */
void BackRoboticArm__Delegatee::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == STARTMOTORS_ID
			&& (currentEvent->associatedState == STARTMOTORS_ID)) {
		//from StartMotors to PickBackPart
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = PICKBACKPART_ID;
			(this->StateEntry)(PICKBACKPART_ID);
			;
			//starting the counters for time events
			//start activity of PickBackPart by calling setFlag
			setFlag(PICKBACKPART_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == PICKBACKPART_ID
			&& (currentEvent->associatedState == PICKBACKPART_ID)) {
		//from PickBackPart to RetakeBackPart
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = RETAKEBACKPART_ID;
			(this->StateEntry)(RETAKEBACKPART_ID);
			;
			//starting the counters for time events
			//start activity of RetakeBackPart by calling setFlag
			setFlag(RETAKEBACKPART_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == DELIVERBACKPART_ID
			&& (currentEvent->associatedState == DELIVERBACKPART_ID)) {
		//from DeliverBackPart to Finalization
		if (true) {
			//signal to exit the doActivity of DeliverBackPart
			setFlag(DELIVERBACKPART_ID, statemachine::TF_DO_ACTIVITY, false);
			states[PRINCIPALSTATE_ID].actives[0] = FINALIZATION_ID;
			(this->StateEntry)(FINALIZATION_ID);
			;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == RETAKEBACKPART_ID
			&& (currentEvent->associatedState == RETAKEBACKPART_ID)) {
		//from RetakeBackPart to DeliverBackPart
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = DELIVERBACKPART_ID;
			(this->StateEntry)(DELIVERBACKPART_ID);
			;
			//starting the counters for time events
			//start activity of DeliverBackPart by calling setFlag
			setFlag(DELIVERBACKPART_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void BackRoboticArm__Delegatee::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case INITIALIZATION_ID:
		component->init();
		break;
	case STARTMOTORS_ID:
		component->start_motors();
		break;
	case PICKBACKPART_ID:
		component->pick_back_part();
		break;
	case RETAKEBACKPART_ID:
		component->retake_back_part();
		break;
	case DELIVERBACKPART_ID:
		component->deliver_back_part();
		break;
	case FINALIZATION_ID:
		component->stop_motors();
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
void BackRoboticArm__Delegatee::StateExit(unsigned int /*in*/id) {
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
void BackRoboticArm__Delegatee::StateDoActivity(unsigned int /*in*/id) {
	switch (id) {
	case DELIVERBACKPART_ID:
		component->sendGoToPressEvent();
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
void* BackRoboticArm__Delegatee::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	BackRoboticArm__Delegatee* ptr = (BackRoboticArm__Delegatee*) cptr->ptr;
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
void BackRoboticArm__Delegatee::doCallActivity(int /*in*/id) {
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
			if (id == STARTMOTORS_ID || id == PICKBACKPART_ID
					|| id == RETAKEBACKPART_ID || id == DELIVERBACKPART_ID) {
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
void BackRoboticArm__Delegatee::setFlag(int /*in*/id, char /*in*/func_type,
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
				if (id == STARTMOTORS_ID || id == PICKBACKPART_ID
						|| id == RETAKEBACKPART_ID
						|| id == DELIVERBACKPART_ID) {
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
 * @param comp 
 */
void BackRoboticArm__Delegatee::setComponent(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Back::BackRoboticArm* /*in*/comp) {
	this->component = comp;
	this->get_pFloatMotor();
	this->get_upDownMotor();
	this->get_frontBackMotor();
	this->get_rightLeftMotor();
	this->get_plierMotor();
	this->get_pInRestart();
	this->get_pEndOfMo();
	this->get_pPickPiece();
	this->get_pInStopProcess();
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* BackRoboticArm__Delegatee::get_pInRestart() {
	component->pInRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::EndOfModule>* BackRoboticArm__Delegatee::get_pEndOfMo() {
	component->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* BackRoboticArm__Delegatee::get_pPickPiece() {
	component->pPickPiece.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* BackRoboticArm__Delegatee::get_pInStopProcess() {
	component->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::CarFactoryLibrary::CommunicationInterfaces::IRoboticArmFloatMotor* BackRoboticArm__Delegatee::get_pFloatMotor() {
	component->pFloatMotor.providedIntf = component;
	return component->pFloatMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* BackRoboticArm__Delegatee::get_upDownMotor() {
	component->upDownMotor.providedIntf = &(component->motor_up_down);
	return component->upDownMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* BackRoboticArm__Delegatee::get_frontBackMotor() {
	component->frontBackMotor.providedIntf = &(component->motor_up_down);
	return component->frontBackMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* BackRoboticArm__Delegatee::get_rightLeftMotor() {
	component->rightLeftMotor.providedIntf = &(component->motor_up_down);
	return component->rightLeftMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* BackRoboticArm__Delegatee::get_plierMotor() {
	component->plierMotor.providedIntf = &(component->motor_up_down);
	return component->plierMotor.providedIntf;
}

/**
 * 
 * @param ref 
 */
void BackRoboticArm__Delegatee::connect_pDelivered(
		IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* /*in*/ref) {
	component->pDelivered.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackRoboticArm__Delegatee::connect_pOutGotoProcess(
		IPush<LegoCarFactoryRefactoringForSync::signals::GoToPress>* /*in*/ref) {
	component->pOutGotoProcess.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackRoboticArm__Delegatee::connect_pLCD(
		::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref) {
	component->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void BackRoboticArm__Delegatee::connect_pModule(
		::CarFactoryLibrary::IModule* /*in*/ref) {
	component->pModule.requiredIntf = ref;
}

} // of namespace Back
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of BackRoboticArm__Delegatee class body
 ************************************************************/
