// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_FrontFrontConvoyer__Controller_BODY

/************************************************************
 FrontFrontConvoyer__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/FrontFrontConvoyer__Controller.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "CarFactoryLibrary/events/PressAssemble.h"
#include "EV3PapyrusLibrary/IColorSensor.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/FrontConvoyer.h"
#include "LegoCarFactoryRefactoringForSync/signals/GoToPress.h"
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
void FrontFrontConvoyer__Controller::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;

	//initialze root active state
	//execute initial effect
	FrontConveyorStateMachine_Region1_Enter (FRONTCONVOYER_FRONTCONVEYORSTATEMACHINE_REGION1_DEFAULT);

	while (systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			FRONTFRONTCONVOYER__CONTROLLER_GET_CONTROL
			switch (currentEvent->eventID) {
			case PREPARECONVEYOR_ID:
				::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor sig_PREPARECONVEYOR_ID;
				memcpy(&sig_PREPARECONVEYOR_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor));
				processPrepareConveyor(sig_PREPARECONVEYOR_ID);
				break;
			case DELIVEREDCARCONVEYOR_ID:
				::CarFactoryLibrary::events::DeliveredCarConveyor sig_DELIVEREDCARCONVEYOR_ID;
				memcpy(&sig_DELIVEREDCARCONVEYOR_ID, currentEvent->data,
						sizeof(::CarFactoryLibrary::events::DeliveredCarConveyor));
				processDeliveredCarConveyor(sig_DELIVEREDCARCONVEYOR_ID);
				break;
			case GOTOPRESS_ID:
				::LegoCarFactoryRefactoringForSync::signals::GoToPress sig_GOTOPRESS_ID;
				memcpy(&sig_GOTOPRESS_ID, currentEvent->data,
						sizeof(::LegoCarFactoryRefactoringForSync::signals::GoToPress));
				processGoToPress(sig_GOTOPRESS_ID);
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
			FRONTFRONTCONVOYER__CONTROLLER_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void FrontFrontConvoyer__Controller::FrontConveyorStateMachine_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case FRONTCONVOYER_FRONTCONVEYORSTATEMACHINE_REGION1_DEFAULT:
		activeStateID = PRINCIPALSTATE_ID;

		PrincipalState_Region1_Enter (FRONTCONVOYER_PRINCIPALSTATE_REGION1_DEFAULT);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void FrontFrontConvoyer__Controller::PrincipalState_Region1_Enter(
		char /*in*/enter_mode) {
	switch (enter_mode) {
	case FRONTCONVOYER_PRINCIPALSTATE_REGION1_DEFAULT:
		states[PRINCIPALSTATE_ID].actives[0] = GOINITIALPOSITION_ID;

		//start activity of GoInitialPosition by calling setFlag
		setFlag(GOINITIALPOSITION_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	case FRONTCONVOYER_PRINCIPALSTATE_REGION1_GOINITIALPOSITION:
		states[PRINCIPALSTATE_ID].actives[0] = GOINITIALPOSITION_ID;
		//starting the counters for time events
		//start activity of GoInitialPosition by calling setFlag
		setFlag(GOINITIALPOSITION_ID, statemachine::TF_DO_ACTIVITY, true);
		//TODO: set systemState to EVENT_CONSUMED
		break;
	}
}

/**
 * 
 */
void FrontFrontConvoyer__Controller::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0],
				statemachine::TF_DO_ACTIVITY, false);
		if (GOINITIALPOSITION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (GOWAITPOSITION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (REPLACE_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (GOCHECKPRESENCEPOSITION_ID
				== states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (MISPLACE_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (SENDPRESSASSEMBLEEVENT_ID
				== states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (DELIVERCAR_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else if (SENDENDOFMODULEEVENT_ID
				== states[PRINCIPALSTATE_ID].actives[0]) {
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
FrontFrontConvoyer__Controller::FrontFrontConvoyer__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Front::FrontConvoyer* /*in*/origin) :
		eventQueue(50, eventArray), p_origin(origin) {
	//startBehavior();
}

/**
 * 
 */
void FrontFrontConvoyer__Controller::startBehavior() {
	systemState = statemachine::IDLE;

	states[GOINITIALPOSITION_ID].hasDoActivity = true;
	states[SENDENDOFMODULEEVENT_ID].hasDoActivity = true;
	// initialize all threads, the threads wait until the associated flag is set
	for (int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL,
					&FrontFrontConvoyer__Controller::thread_func_wrapper,
					&threadStructs[i]);
		}
	}

	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;

	dispatchStruct = statemachine::StructForThread_t(this, 0, 0,
			statemachine::TF_STATE_MACHINE_TYPE, 0);
	FrontFrontConvoyer__Controller_THREAD_CREATE(dispatchThread, dispatchStruct)
}

/**
 * 
 */
FrontFrontConvoyer__Controller::~FrontFrontConvoyer__Controller() {
	stopBehavior();
}

/**
 * 
 */
void FrontFrontConvoyer__Controller::stopBehavior() {
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
void FrontFrontConvoyer__Controller::processPrepareConveyor(
		::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == GOINITIALPOSITION_ID) {
		//from GoInitialPosition to GoWaitPosition
		if (true) {
			//signal to exit the doActivity of GoInitialPosition
			setFlag(GOINITIALPOSITION_ID, statemachine::TF_DO_ACTIVITY, false);
			p_origin->save_color(sig);
			states[PRINCIPALSTATE_ID].actives[0] = GOWAITPOSITION_ID;
			(this->StateEntry)(GOWAITPOSITION_ID);
			;
			//starting the counters for time events
			//start activity of GoWaitPosition by calling setFlag
			setFlag(GOWAITPOSITION_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, PREPARECONVEYOR_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor));
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::processDeliveredCarConveyor(
		::CarFactoryLibrary::events::DeliveredCarConveyor& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == SENDPRESSASSEMBLEEVENT_ID) {
		//from SendPressAssembleEvent to DeliverCar
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = DELIVERCAR_ID;
			(this->StateEntry)(DELIVERCAR_ID);
			;
			//starting the counters for time events
			//start activity of DeliverCar by calling setFlag
			setFlag(DELIVERCAR_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::push(
		::CarFactoryLibrary::events::DeliveredCarConveyor& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, DELIVEREDCARCONVEYOR_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::CarFactoryLibrary::events::DeliveredCarConveyor));
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::processGoToPress(
		::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == REPLACE_ID) {
		//from Replace to GoCheckPresencePosition
		if (true) {
			p_origin->save_color(sig);
			states[PRINCIPALSTATE_ID].actives[0] = GOCHECKPRESENCEPOSITION_ID;
			(this->StateEntry)(GOCHECKPRESENCEPOSITION_ID);
			;
			//starting the counters for time events
			//start activity of GoCheckPresencePosition by calling setFlag
			setFlag(GOCHECKPRESENCEPOSITION_ID, statemachine::TF_DO_ACTIVITY,
					true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, GOTOPRESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::GoToPress));
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::processRestartAfterEmergencyStop(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case RESTART_ID:
			//from Restart to PrincipalState
			if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter (FRONTCONVOYER_PRINCIPALSTATE_REGION1_DEFAULT);
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
void FrontFrontConvoyer__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig,
			RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 * @param sig 
 */
void FrontFrontConvoyer__Controller::processStopProcess(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch (activeStateID) {
		case PRINCIPALSTATE_ID:
			//from PrincipalState to Restart
			if (true) {
				PrincipalState_Region1_Exit();
				p_origin->effectFromPrincipalStatetoRestart(sig);
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
void FrontFrontConvoyer__Controller::push(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID,
			statemachine::SIGNAL_EVENT, 0,
			sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 */
void FrontFrontConvoyer__Controller::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == MISPLACE_ID
			&& (currentEvent->associatedState == MISPLACE_ID)) {
		//from Misplace to Restart
		if (true) {
			PrincipalState_Region1_Exit();
			activeStateID = RESTART_ID;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == SENDENDOFMODULEEVENT_ID
			&& (currentEvent->associatedState == SENDENDOFMODULEEVENT_ID)) {
		//from SendEndOfModuleEvent to GoInitialPosition
		if (true) {
			//signal to exit the doActivity of SendEndOfModuleEvent
			setFlag(SENDENDOFMODULEEVENT_ID, statemachine::TF_DO_ACTIVITY,
					false);
			states[PRINCIPALSTATE_ID].actives[0] = GOINITIALPOSITION_ID;
			//starting the counters for time events
			//start activity of GoInitialPosition by calling setFlag
			setFlag(GOINITIALPOSITION_ID, statemachine::TF_DO_ACTIVITY, true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == GOWAITPOSITION_ID
			&& (currentEvent->associatedState == GOWAITPOSITION_ID)) {
		//from GoWaitPosition to Replace
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = REPLACE_ID;
			(this->StateEntry)(REPLACE_ID);
			;
			//starting the counters for time events
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0]
			== GOCHECKPRESENCEPOSITION_ID
			&& (currentEvent->associatedState == GOCHECKPRESENCEPOSITION_ID)) {
		//from GoCheckPresencePosition to choice
		if (true) {
			if (p_origin->fromChoicetoMisplaceGuard()) {
				states[PRINCIPALSTATE_ID].actives[0] = MISPLACE_ID;
				(this->StateEntry)(MISPLACE_ID);
				;
				//starting the counters for time events
				//start activity of Misplace by calling setFlag
				setFlag(MISPLACE_ID, statemachine::TF_DO_ACTIVITY, true);
			} else {
				states[PRINCIPALSTATE_ID].actives[0] =
						SENDPRESSASSEMBLEEVENT_ID;
				(this->StateEntry)(SENDPRESSASSEMBLEEVENT_ID);
				;
				//starting the counters for time events
			}
			systemState = statemachine::EVENT_CONSUMED;
		}
	} else if (states[PRINCIPALSTATE_ID].actives[0] == DELIVERCAR_ID
			&& (currentEvent->associatedState == DELIVERCAR_ID)) {
		//from DeliverCar to SendEndOfModuleEvent
		if (true) {
			states[PRINCIPALSTATE_ID].actives[0] = SENDENDOFMODULEEVENT_ID;
			//starting the counters for time events
			//start activity of SendEndOfModuleEvent by calling setFlag
			setFlag(SENDENDOFMODULEEVENT_ID, statemachine::TF_DO_ACTIVITY,
					true);
			systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void FrontFrontConvoyer__Controller::StateEntry(unsigned int /*in*/id) {
	switch (id) {
	case GOWAITPOSITION_ID:
		p_origin->go_wait_position();
		break;
	case REPLACE_ID:
		p_origin->replace();
		break;
	case GOCHECKPRESENCEPOSITION_ID:
		p_origin->goCheckPresencePosition();
		break;
	case MISPLACE_ID:
		p_origin->sendErrorDetectionEvent();
		break;
	case SENDPRESSASSEMBLEEVENT_ID:
		p_origin->sendPressAssembleEvent();
		break;
	case DELIVERCAR_ID:
		p_origin->deliver();
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
void FrontFrontConvoyer__Controller::StateExit(unsigned int /*in*/id) {
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
void FrontFrontConvoyer__Controller::StateDoActivity(unsigned int /*in*/id) {
	switch (id) {
	case GOINITIALPOSITION_ID:
		p_origin->go_initial_position();
		break;
	case SENDENDOFMODULEEVENT_ID:
		p_origin->sendEndOfModuleEvent();
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
void* FrontFrontConvoyer__Controller::thread_func_wrapper(void* /*in*/data) {
	statemachine::StructForThread_t* cptr =
			(statemachine::StructForThread_t*) data;
	FrontFrontConvoyer__Controller* ptr =
			(FrontFrontConvoyer__Controller*) cptr->ptr;
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
void FrontFrontConvoyer__Controller::doCallActivity(int /*in*/id) {
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
			if (id == GOWAITPOSITION_ID || id == GOCHECKPRESENCEPOSITION_ID
					|| id == MISPLACE_ID || id == DELIVERCAR_ID
					|| id == SENDENDOFMODULEEVENT_ID) {
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
void FrontFrontConvoyer__Controller::setFlag(int /*in*/id, char /*in*/func_type,
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
				if (id == GOWAITPOSITION_ID || id == GOCHECKPRESENCEPOSITION_ID
						|| id == MISPLACE_ID || id == DELIVERCAR_ID
						|| id == SENDENDOFMODULEEVENT_ID) {
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
IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* FrontFrontConvoyer__Controller::get_pInStopProcess() {
	p_origin->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* FrontFrontConvoyer__Controller::get_pRestart() {
	p_origin->pRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::PrepareConveyor>* FrontFrontConvoyer__Controller::get_pPrepare() {
	p_origin->pPrepare.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* FrontFrontConvoyer__Controller::get_pDelivered() {
	p_origin->pDelivered.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* FrontFrontConvoyer__Controller::get_pILargeMotor() {
	p_origin->pILargeMotor.providedIntf = &(p_origin->motor);
	return p_origin->pILargeMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
IPush<LegoCarFactoryRefactoringForSync::signals::GoToPress>* FrontFrontConvoyer__Controller::get_pGotoProcess() {
	p_origin->pGotoProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* FrontFrontConvoyer__Controller::get_sensor() {
	p_origin->sensor.providedIntf = &(p_origin->color_sensor);
	return p_origin->sensor.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor* FrontFrontConvoyer__Controller::get_pMotor() {
	p_origin->pMotor.providedIntf = &(p_origin->motor);
	return p_origin->pMotor.providedIntf;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pCheckRack(
		IPush<CarFactoryLibrary::events::CheckRack>* /*in*/ref) {
	p_origin->pCheckRack.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pErrDetect(
		IPush<CarFactoryLibrary::events::ErrorDetection>* /*in*/ref) {
	p_origin->pErrDetect.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pEndOfMo_Control(
		IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref) {
	p_origin->pEndOfMo_Control.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pEndOfMo_Shelf(
		IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref) {
	p_origin->pEndOfMo_Shelf.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pEndOfMo_Robotic(
		IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref) {
	p_origin->pEndOfMo_Robotic.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pEndOfMo_Press(
		IPush<CarFactoryLibrary::events::EndOfModule>* /*in*/ref) {
	p_origin->pEndOfMo_Press.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pOutAssemble(
		IPush<CarFactoryLibrary::events::PressAssemble>* /*in*/ref) {
	p_origin->pOutAssemble.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pLCD(
		::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref) {
	p_origin->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void FrontFrontConvoyer__Controller::connect_pModule(
		::CarFactoryLibrary::IModule* /*in*/ref) {
	p_origin->pModule.requiredIntf = ref;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of FrontFrontConvoyer__Controller class body
 ************************************************************/
