// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Roof_RoofControlComponent_BODY

/************************************************************
 RoofControlComponent class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofControlComponent.h"

// Derived includes directives
#include "CarFactoryLibrary/CommunicationInterfaces/IRoboticArmFloatMotor.h"
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"

// Include from Include declaration (body)
void bindPorts(Port& p1, Port& p2) {
}
// End of Include declaration (body)

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Roof {

// static attributes (if any)

/**
 * 
 */
void RoofControlComponent::send_check_racks_event() {

	write(MASTER_MODULE, RESULT_OK); //acknowledgement
	manageGreenLights();
	CarFactoryLibrary::events::CheckRack s;
	s.color = static_cast<Colors>(std::stoi(extra_msg));
	color = static_cast<Colors>(std::stoi(extra_msg));
	pOutCheckRack.outIntf->push(s); //shelf.sendCheckRack(s);
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::init_bluetooth_communication() {

	cout << "init " << endl;
	if (!ev3Brick.bluetoothDevice.accept_connection(
			bluetooth_name[MASTER_MODULE])) {
		perror("not connected");
		return false;
	}
	write(MASTER_MODULE, RESULT_OK);
	cout << "return true " << endl;
	return true;
}

/**
 * 
 */
RoofControlComponent::RoofControlComponent() :
		roofcontrolcomponentController(this) {
}

/**
 * 
 * @param sig 
 */
void RoofControlComponent::effectFromEmnergencyStopStatetoMisplace(
		::CarFactoryLibrary::events::ErrorDetection& /*in*/sig) {

	error_detection_is_misplace = sig.is_misplace;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromWaittoEmergencyButtonPressGuard() {

	return emergency_button.value(0);
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoice2toRestartGuard() {

	return ev3Brick.topButton.pressed();
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoice1toRestartGuard() {

	return ev3Brick.topButton.pressed();
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoPingGuard() {

	return msg == CMD_PING;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoGetStatusGuard() {

	return msg == CMD_GET_STATUS;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoLoadCarGuard() {

	return msg == CMD_LOAD_CAR;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoDeliverGuard() {

	return msg == CMD_DELIVER;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoRewindGuard() {

	return msg == CMD_REWIND;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoAssembleGuard() {

	return msg == CMD_ASSEMBLE;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoResetGuard() {

	return msg == CMD_RESET;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromChoicetoFinalState1Guard() {

	return msg == CMD_STOP;
}

/**
 * 
 * @return ret 
 */
bool RoofControlComponent::fromInitializationtoPrincipalStateGuard() {

	return init_bluetooth_communication();
}

/**
 * 
 */
void RoofControlComponent::init() {

	led_status.all_led_on();
	usleep(50000);
	led_status.all_led_off();
	manageOrangeLights();
}

/**
 * 
 */
void RoofControlComponent::doActivityCheck() {

	//CHECKPOINT
}

/**
 * 
 */
void RoofControlComponent::sendStopProcessEvent() {

	ev3Brick.soundDevice.tone(100, 100);
	pFloatMotor.requiredIntf->float_motors(); //robotic_arm.float_motors();
	pLargeMotor_Convoyer.requiredIntf->stop(); //conveyor.motor.stop(false);
	pLargeMotor_Press.requiredIntf->stop(); //press.motor.stop(false);
	LegoCarFactoryRefactoringForSync::signals::StopProcess s;
	s.is_emergency_stop = true;
	pOutStopProcess_Shelf.outIntf->push(s); //shelf.sendStopProcess(s);
	pOutStopProcess_RoboticArm.outIntf->push(s); //robotic_arm.sendStopProcess(s);
	pStopProcess_Convoyer.outIntf->push(s); //conveyor.sendStopProcess(s);
	pStopProcess_Press.outIntf->push(s); //press.sendStopProcess(s);
	status = RESULT_STOP;
}

/**
 * 
 */
void RoofControlComponent::sendStopProcess() {

	if (error_detection_is_misplace) {
		showMisplacePartGUI();
	} else {
		showEmptyRackGUI (color);
	}
	LegoCarFactoryRefactoringForSync::signals::StopProcess s;
	s.is_emergency_stop = false;
	pOutStopProcess_Shelf.outIntf->push(s); //shelf.sendStopProcess(s);
	pOutStopProcess_RoboticArm.outIntf->push(s); //robotic_arm.sendStopProcess(s);
	pStopProcess_Convoyer.outIntf->push(s); //conveyor.sendStopProcess(s);
}

/**
 * 
 */
void RoofControlComponent::send_restart_event() {

	LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop s;
	pOutRestart_Shelf.outIntf->push(s); //shelf.sendRestartAfterEmergencyStop(s);
	pOutRestart_Robotic.outIntf->push(s); //robotic_arm.sendRestartAfterEmergencyStop(s);
	pOutRestart_Convoyer.outIntf->push(s); //conveyor.sendRestartAfterEmergencyStop(s);
	pOutRestart_Press.outIntf->push(s); //press.sendRestartAfterEmergencyStop(s);
	status = RESULT_READY;
}

/**
 * 
 */
void RoofControlComponent::show_stop_GUI() {

	showStopGUI();
}

/**
 * 
 */
void RoofControlComponent::read() {

	bool stop = false;
	while (!stop) {
		string tmp_string = readFromMaster();

		//split receive message
		int split_index = tmp_string.find("-");
		if (split_index != string::npos) {
			extra_msg = tmp_string.substr(split_index + 1);
			msg = parseMasterMessage(tmp_string.substr(0, split_index));
			cout << msg << endl;
		} else {
			msg = parseMasterMessage(tmp_string);
		}
		if (msg == CMD_ASSEMBLE || msg == CMD_DELIVER || msg == CMD_LOAD_CAR) {
			status = RESULT_BUSY;
		}
		if (msg != NO_MASTER_MSG)
			stop = true;
		//CHECKPOINT
	}
}

/**
 * 
 */
void RoofControlComponent::reset() {

	write(MASTER_MODULE, RESULT_OK); //acknowledgement
	pFloatMotor.requiredIntf->float_motors(); //robotic_arm.float_motors();
	pLargeMotor_Convoyer.requiredIntf->stop(); //conveyor.motor.stop(false);
	pLargeMotor_Press.requiredIntf->stop(); //press.motor.stop(false);
	LegoCarFactoryRefactoringForSync::signals::StopProcess s;
	s.is_emergency_stop = true;
	pOutStopProcess_Shelf.outIntf->push(s); //shelf.sendStopProcess(s);
	pOutStopProcess_RoboticArm.outIntf->push(s); //robotic_arm.sendStopProcess(s);
	pStopProcess_Convoyer.outIntf->push(s); //conveyor.sendStopProcess(s);
	pStopProcess_Press.outIntf->push(s); //press.sendStopProcess(s);

	LegoCarFactoryRefactoringForSync::signals::RestartAfterEmergencyStop s1;
	pOutRestart_Shelf.outIntf->push(s1); //shelf.sendRestartAfterEmergencyStop(s1);
	pOutRestart_Robotic.outIntf->push(s1); //robotic_arm.sendRestartAfterEmergencyStop(s1);
	pOutRestart_Convoyer.outIntf->push(s1); //conveyor.sendRestartAfterEmergencyStop(s1);
	pOutRestart_Press.outIntf->push(s1); //press.sendRestartAfterEmergencyStop(s1);

	status = RESULT_READY;
}

/**
 * 
 */
void RoofControlComponent::ping_response() {

	ping_response();
}

/**
 * 
 */
void RoofControlComponent::get_status_response() {

	get_status_response();
}

/**
 * 
 */
void RoofControlComponent::sendPrepareConveyorEvent() {

	write(MASTER_MODULE, RESULT_OK); //acknowledgement	
	manageGreenLights();
	LegoCarFactoryRefactoringForSync::signals::PrepareConveyor s;
	pPrepare.outIntf->push(s); //conveyor.sendPrepareConveyor(s);
}

/**
 * 
 */
void RoofControlComponent::deliver() {

	write(MASTER_MODULE, RESULT_OK); //acknowledgement	
	manageGreenLights();
	CarFactoryLibrary::events::DeliveredCarConveyor s;
	pOutDelivered.outIntf->push(s); //conveyor.sendDeliveredCarConveyor(s);
}

/**
 * 
 */
void RoofControlComponent::rewind() {

	write(MASTER_MODULE, RESULT_OK); //acknowledgement	
	manageGreenLights();
	//TODO:conveyor.rewind();
}

} // of namespace Roof
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of RoofControlComponent class body
 ************************************************************/
