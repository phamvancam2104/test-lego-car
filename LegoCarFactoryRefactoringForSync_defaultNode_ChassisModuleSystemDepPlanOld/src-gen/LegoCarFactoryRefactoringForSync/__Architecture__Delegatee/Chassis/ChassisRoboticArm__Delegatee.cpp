// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_Chassis_ChassisRoboticArm__Delegatee_BODY

/************************************************************
              ChassisRoboticArm__Delegatee class body
 ************************************************************/


// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Chassis/ChassisRoboticArm__Delegatee.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisRoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "statemachine/Pkg_statemachine.h"


namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Chassis {

// static attributes (if any)

/**
 * 
 */
void ChassisRoboticArm__Delegatee::dispatchEvent() {
	bool popDeferred = false;
	dispatchFlag = true;
	
	//initialze root active state
	//execute initial effect
	ChassisRoboticArmStateMachine_Region1_Enter(CHASSISROBOTICARM_CHASSISROBOTICARMSTATEMACHINE_REGION1_DEFAULT);
	
	while(systemState != statemachine::STOPPED) {
		//run-to-completion: need to have a mutex here
		currentEvent = eventQueue.pop(popDeferred);
		if (currentEvent != NULL) {
			CHASSISROBOTICARM__DELEGATEE_GET_CONTROL
			switch(currentEvent->eventID) {
				case ENDOFMODULE_ID:
					::CarFactoryLibrary::events::EndOfModule sig_ENDOFMODULE_ID;
					memcpy(&sig_ENDOFMODULE_ID, currentEvent->data, sizeof(::CarFactoryLibrary::events::EndOfModule));
					processEndOfModule(sig_ENDOFMODULE_ID);
					break;
				case ROBOTICARMPICKPIECE_ID:
					::CarFactoryLibrary::events::RoboticArmPickPiece sig_ROBOTICARMPICKPIECE_ID;
					memcpy(&sig_ROBOTICARMPICKPIECE_ID, currentEvent->data, sizeof(::CarFactoryLibrary::events::RoboticArmPickPiece));
					processRoboticArmPickPiece(sig_ROBOTICARMPICKPIECE_ID);
					break;
				case STOPPROCESS_ID:
					::LegoCarFactoryRefactoringForSync::signals::StopProcess sig_STOPPROCESS_ID;
					memcpy(&sig_STOPPROCESS_ID, currentEvent->data, sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
					processStopProcess(sig_STOPPROCESS_ID);
					break;
				case RESTARTAFTEREMERGENCYSTOP_ID:
					::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop sig_RESTARTAFTEREMERGENCYSTOP_ID;
					memcpy(&sig_RESTARTAFTEREMERGENCYSTOP_ID, currentEvent->data, sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
					processRestartAfterEmergencyStop(sig_RESTARTAFTEREMERGENCYSTOP_ID);
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
			CHASSISROBOTICARM__DELEGATEE_RELEASE_CONTROL
		}
	}
}

/**
 * 
 * @param enter_mode 
 */
void ChassisRoboticArm__Delegatee::ChassisRoboticArmStateMachine_Region1_Enter(char /*in*/ enter_mode) {
	switch(enter_mode) {
		case CHASSISROBOTICARM_CHASSISROBOTICARMSTATEMACHINE_REGION1_DEFAULT:
			activeStateID = PRINCIPALSTATE_ID;
			
			
			PrincipalState_Region1_Enter(CHASSISROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT);
			//TODO: set systemState to EVENT_CONSUMED
			break;
	}
}

/**
 * 
 * @param enter_mode 
 */
void ChassisRoboticArm__Delegatee::PrincipalState_Region1_Enter(char /*in*/ enter_mode) {
	switch(enter_mode) {
		case CHASSISROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT:
			states[PRINCIPALSTATE_ID].actives[0] = INITIALIZATION_ID;
			
			
			//TODO: set systemState to EVENT_CONSUMED
			break;
	}
}

/**
 * 
 */
void ChassisRoboticArm__Delegatee::PrincipalState_Region1_Exit() {
	//exiting region Region1
	if (states[PRINCIPALSTATE_ID].actives[0] != STATE_MAX) {
		//signal to exit the doActivity of sub-state of PrincipalState
		setFlag(states[PRINCIPALSTATE_ID].actives[0], statemachine::TF_DO_ACTIVITY, false);
		if (START_MOTORS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else 
		if (TIP_UP_CHASSIS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else 
		if (PICK_CHASSIS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else 
		if (DELIVER_CHASSIS_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else 
		if (SENDDELIVEREDCARCONVEYOREVENT_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else 
		if (INITIALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
		} else 
		if (FINALIZATION_ID == states[PRINCIPALSTATE_ID].actives[0]) {
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
ChassisRoboticArm__Delegatee::ChassisRoboticArm__Delegatee(): systemState(statemachine::IDLE) {
	//startBehavior();
}

/**
 * 
 */
void ChassisRoboticArm__Delegatee::startBehavior() {
	// initialize all threads, the threads wait until the associated flag is set
	for(int i = 0; i < (int) STATE_MAX; i++) {
		if (states[i].hasDoActivity) {
			threadStructs[i].id = i;
			threadStructs[i].ptr = this;
			threadStructs[i].func_type = statemachine::TF_DO_ACTIVITY;
			mutexes[i] = PTHREAD_MUTEX_INITIALIZER;
			conds[i] = PTHREAD_COND_INITIALIZER;
			pthread_create(&threads[i], NULL, &ChassisRoboticArm__Delegatee::thread_func_wrapper, &threadStructs[i]);
		}
	}
		
			
			
	
	runToCompletionMutex = PTHREAD_MUTEX_INITIALIZER;
	runToCompletionCond = PTHREAD_COND_INITIALIZER;
	
	dispatchStruct = statemachine::StructForThread_t(this, 0, 0, statemachine::TF_STATE_MACHINE_TYPE, 0);
	ChassisRoboticArm__Delegatee_THREAD_CREATE(dispatchThread, dispatchStruct)
}

/**
 * 
 */
ChassisRoboticArm__Delegatee::~ChassisRoboticArm__Delegatee() {
	stopBehavior();
}

/**
 * 
 */
void ChassisRoboticArm__Delegatee::stopBehavior() {
	systemState = statemachine::STOPPED;
		//signal and wait for doActivity termination
		for(int i = 0; i < (int) STATE_MAX; i++) {
			if (states[i].hasDoActivity) {
				pthread_cond_signal(&conds[i]);
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
void ChassisRoboticArm__Delegatee::processEndOfModule(::CarFactoryLibrary::events::EndOfModule& /*in*/ sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == FINALIZATION_ID) {
		//from Finalization to Initialization
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
void ChassisRoboticArm__Delegatee::push(::CarFactoryLibrary::events::EndOfModule& /*in*/ sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ENDOFMODULE_ID, statemachine::SIGNAL_EVENT, 0, sizeof(::CarFactoryLibrary::events::EndOfModule));
}

/**
 * 
 * @param sig 
 */
void ChassisRoboticArm__Delegatee::processRoboticArmPickPiece(::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/ sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == INITIALIZATION_ID) {
		//from Initialization to choice
		if (true) {
			component->save_rack_number(sig);
			if (choice_CompletionEvent == 1) {
				states[PRINCIPALSTATE_ID].actives[0] = SENDDELIVEREDCARCONVEYOREVENT_ID;
				//starting the counters for time events
				//start activity of SendDeliveredCarConveyorEvent by calling setFlag
				setFlag(SENDDELIVEREDCARCONVEYOREVENT_ID, statemachine::TF_DO_ACTIVITY, true);
			} else { 
				states[PRINCIPALSTATE_ID].actives[0] = START_MOTORS_ID;
				//starting the counters for time events
				//start activity of start_motors by calling setFlag
				setFlag(START_MOTORS_ID, statemachine::TF_DO_ACTIVITY, true);
			}
		systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param sig 
 */
void ChassisRoboticArm__Delegatee::push(::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/ sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, ROBOTICARMPICKPIECE_ID, statemachine::SIGNAL_EVENT, 0, sizeof(::CarFactoryLibrary::events::RoboticArmPickPiece));
}

/**
 * 
 * @param sig 
 */
void ChassisRoboticArm__Delegatee::processStopProcess(::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/ sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch(activeStateID) {
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
void ChassisRoboticArm__Delegatee::push(::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/ sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, STOPPROCESS_ID, statemachine::SIGNAL_EVENT, 0, sizeof(::LegoCarFactoryRefactoringForSync::signals::StopProcess));
}

/**
 * 
 * @param sig 
 */
void ChassisRoboticArm__Delegatee::processRestartAfterEmergencyStop(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/ sig) {
	systemState = statemachine::EVENT_PROCESSING;
	if (systemState == statemachine::EVENT_PROCESSING) {
		switch(activeStateID) {
			case RESTART_ID: 
				//from Restart to PrincipalState
				if (true) {
				activeStateID = PRINCIPALSTATE_ID;
				//starting the counters for time events
				PrincipalState_Region1_Enter(CHASSISROBOTICARM_PRINCIPALSTATE_REGION1_DEFAULT);
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
void ChassisRoboticArm__Delegatee::push(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop& /*in*/ sig) {
	eventQueue.push(statemachine::PRIORITY_2, &sig, RESTARTAFTEREMERGENCYSTOP_ID, statemachine::SIGNAL_EVENT, 0, sizeof(::LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop));
}

/**
 * 
 */
void ChassisRoboticArm__Delegatee::processCompletionEvent() {
	systemState = statemachine::EVENT_PROCESSING;
	if (states[PRINCIPALSTATE_ID].actives[0] == START_MOTORS_ID && (currentEvent->associatedState == START_MOTORS_ID)) {
		//from start_motors to tip_up_chassis
		if (true) {
		states[PRINCIPALSTATE_ID].actives[0] = TIP_UP_CHASSIS_ID;
		//starting the counters for time events
		//start activity of tip_up_chassis by calling setFlag
		setFlag(TIP_UP_CHASSIS_ID, statemachine::TF_DO_ACTIVITY, true);
		systemState = statemachine::EVENT_CONSUMED;
		}
	} else 
	if (states[PRINCIPALSTATE_ID].actives[0] == TIP_UP_CHASSIS_ID && (currentEvent->associatedState == TIP_UP_CHASSIS_ID)) {
		//from tip_up_chassis to pick_chassis
		if (true) {
		states[PRINCIPALSTATE_ID].actives[0] = PICK_CHASSIS_ID;
		//starting the counters for time events
		//start activity of pick_chassis by calling setFlag
		setFlag(PICK_CHASSIS_ID, statemachine::TF_DO_ACTIVITY, true);
		systemState = statemachine::EVENT_CONSUMED;
		}
	} else 
	if (states[PRINCIPALSTATE_ID].actives[0] == PICK_CHASSIS_ID && (currentEvent->associatedState == PICK_CHASSIS_ID)) {
		//from pick_chassis to deliver_chassis
		if (true) {
		states[PRINCIPALSTATE_ID].actives[0] = DELIVER_CHASSIS_ID;
		//starting the counters for time events
		//start activity of deliver_chassis by calling setFlag
		setFlag(DELIVER_CHASSIS_ID, statemachine::TF_DO_ACTIVITY, true);
		systemState = statemachine::EVENT_CONSUMED;
		}
	} else 
	if (states[PRINCIPALSTATE_ID].actives[0] == DELIVER_CHASSIS_ID && (currentEvent->associatedState == DELIVER_CHASSIS_ID)) {
		//from deliver_chassis to SendDeliveredCarConveyorEvent
		if (true) {
		states[PRINCIPALSTATE_ID].actives[0] = SENDDELIVEREDCARCONVEYOREVENT_ID;
		//starting the counters for time events
		//start activity of SendDeliveredCarConveyorEvent by calling setFlag
		setFlag(SENDDELIVEREDCARCONVEYOREVENT_ID, statemachine::TF_DO_ACTIVITY, true);
		systemState = statemachine::EVENT_CONSUMED;
		}
	} else 
	if (states[PRINCIPALSTATE_ID].actives[0] == SENDDELIVEREDCARCONVEYOREVENT_ID && (currentEvent->associatedState == SENDDELIVEREDCARCONVEYOREVENT_ID)) {
		//from SendDeliveredCarConveyorEvent to Finalization
		if (true) {
		states[PRINCIPALSTATE_ID].actives[0] = FINALIZATION_ID;
		//starting the counters for time events
		systemState = statemachine::EVENT_CONSUMED;
		}
	}
}

/**
 * 
 * @param id 
 */
void ChassisRoboticArm__Delegatee::StateEntry(unsigned int /*in*/ id) {
	switch(id) {
		default:
			//do nothing
			break;
	}
}

/**
 * 
 * @param id 
 */
void ChassisRoboticArm__Delegatee::StateExit(unsigned int /*in*/ id) {
	switch(id) {
		default:
			//do nothing
			break;
	}
}

/**
 * 
 * @param id 
 */
void ChassisRoboticArm__Delegatee::StateDoActivity(unsigned int /*in*/ id) {
	switch(id) {
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
 void* ChassisRoboticArm__Delegatee::thread_func_wrapper(void* /*in*/ data) {
	statemachine::StructForThread_t* cptr = (statemachine::StructForThread_t*)data;
	ChassisRoboticArm__Delegatee* ptr = (ChassisRoboticArm__Delegatee*) cptr->ptr;
	switch(cptr->func_type) {
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
void ChassisRoboticArm__Delegatee::doCallActivity(int /*in*/ id) {
	flags[id] = false;
	while(systemState != statemachine::STOPPED) {
		pthread_mutex_lock(&mutexes[id]);
		while(!flags[id] && systemState != statemachine::STOPPED) {
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
		pthread_cond_signal(&conds[id]);
		pthread_mutex_unlock(&mutexes[id]);
		if (commitEvent && systemState != statemachine::STOPPED) {
			if(id == START_MOTORS_ID || id == TIP_UP_CHASSIS_ID || id == PICK_CHASSIS_ID || id == DELIVER_CHASSIS_ID || id == SENDDELIVEREDCARCONVEYOREVENT_ID) {
				//processCompletionEvent();
				eventQueue.push(statemachine::PRIORITY_1, NULL, COMPLETIONEVENT_ID, statemachine::COMPLETION_EVENT, id);
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
void ChassisRoboticArm__Delegatee::setFlag(int /*in*/ id, char /*in*/ func_type, bool /*in*/ value) {
	//value = true => start activity
	//value = false => stop activity
	if (func_type == statemachine::TF_DO_ACTIVITY) {
		//push completion event
			if (value) {
				if(id == START_MOTORS_ID || id == TIP_UP_CHASSIS_ID || id == PICK_CHASSIS_ID || id == DELIVER_CHASSIS_ID || id == SENDDELIVEREDCARCONVEYOREVENT_ID) {
					eventQueue.push(statemachine::PRIORITY_1, NULL, COMPLETIONEVENT_ID, statemachine::COMPLETION_EVENT, id);
				}
				return;
			} 
	}
}

/**
 * 
 * @param comp 
 */
void ChassisRoboticArm__Delegatee::setComponent(::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm* /*in*/ comp) {
	this->component = comp;
	this->get_upDownMotor();
	this->get_frontBackMotor();
	this->get_rightLeftMotor();
	this->get_plierMotor();
	this->get_pInStopProcess();
	this->get_pInRestart();
	this->get_pEndOfMo();
	this->get_pPickPiece();
}

/**
 * 
 * @return ret 
 */
 IPush<LegoCarFactoryRefactoringForSync::signals::StopProcess>* ChassisRoboticArm__Delegatee::get_pInStopProcess() {
	component->pInStopProcess.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
 IPush<LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop>* ChassisRoboticArm__Delegatee::get_pInRestart() {
	component->pInRestart.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
 IPush<CarFactoryLibrary::events::EndOfModule>* ChassisRoboticArm__Delegatee::get_pEndOfMo() {
	component->pEndOfMo.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
 IPush<CarFactoryLibrary::events::RoboticArmPickPiece>* ChassisRoboticArm__Delegatee::get_pPickPiece() {
	component->pPickPiece.inIntf = this;
	return this;
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* ChassisRoboticArm__Delegatee::get_upDownMotor() {
	component->upDownMotor.providedIntf = &(component->motor_up_down);
	return component->upDownMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* ChassisRoboticArm__Delegatee::get_frontBackMotor() {
	component->frontBackMotor.providedIntf = &(component->motor_up_down);
	return component->frontBackMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* ChassisRoboticArm__Delegatee::get_rightLeftMotor() {
	component->rightLeftMotor.providedIntf = &(component->motor_up_down);
	return component->rightLeftMotor.providedIntf;
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* ChassisRoboticArm__Delegatee::get_plierMotor() {
	component->plierMotor.providedIntf = &(component->motor_up_down);
	return component->plierMotor.providedIntf;
}

/**
 * 
 * @param ref 
 */
void ChassisRoboticArm__Delegatee::connect_pDelivered(IPush<CarFactoryLibrary::events::DeliveredCarConveyor>* /*in*/ ref) {
	component->pDelivered.outIntf = ref;
}

/**
 * 
 * @param ref 
 */
void ChassisRoboticArm__Delegatee::connect_pLCD(::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ ref) {
	component->pLCD.requiredIntf = ref;
}

/**
 * 
 * @param ref 
 */
void ChassisRoboticArm__Delegatee::connect_pModule(::CarFactoryLibrary::IModule* /*in*/ ref) {
	component->pModule.requiredIntf = ref;
}



} // of namespace Chassis
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of ChassisRoboticArm__Delegatee class body
 ************************************************************/