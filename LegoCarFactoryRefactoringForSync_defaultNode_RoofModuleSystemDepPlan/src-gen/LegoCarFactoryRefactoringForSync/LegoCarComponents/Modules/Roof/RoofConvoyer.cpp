// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Roof_RoofConvoyer_BODY

/************************************************************
 RoofConvoyer class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofConvoyer.h"

// Derived includes directives
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "CarFactoryLibrary/events/PressAssemble.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "LegoCarFactoryRefactoringForSync/signals/GoToPress.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Roof {

// static attributes (if any)
/**
 * the command to send to the motor to go from the stop position to wait car position (from the other module)
 */
int RoofConvoyer::wait_car_offset = -180;
/**
 * the command to send to the motor to go from the stop position to wait car position (from the other module)
 */
int RoofConvoyer::take_car_offset = -208;
/**
 * 
 */
::CarFactoryLibrary::Colors RoofConvoyer::color;

/**
 * 
 */
void RoofConvoyer::sendErrorDetectionEvent() {

	CarFactoryLibrary::events::ErrorDetection s;
	pErrDetect.outIntf->push(s); //get_module()->sendErrorDetection(s);
	s.is_misplace = true;
	pModule.requiredIntf->setStatus(CarFactoryLibrary::RESULT_ERROR);
}

/**
 * 
 */
void RoofConvoyer::take_car() {

	motor.set_duty_cycle_sp(30);
	motor.set_stop_command("brake");
	motor.set_position_sp(take_car_offset);
	motor.run_to_rel_pos();

	//Wait conveyor is in the well position
	while (motor.speed() == 0) {
	}
	while (motor.speed() != 0) {
	}
}

/**
 * 
 */
void RoofConvoyer::go_wait_car() {

	motor.set_duty_cycle_sp(30);
	motor.set_stop_command("brake");
	motor.set_position_sp(wait_car_offset);
	motor.run_to_rel_pos();

	//Wait conveyor is in the well position
	while (motor.speed() == 0) {
	}
	while (motor.speed() != 0) {
	}
}

/**
 * 
 */
RoofConvoyer::RoofConvoyer() :
		roofconvoyerController(this) {
}

/**
 * 
 * @param sig 
 */
void RoofConvoyer::effectFromPrincipalStatetoRestart(
		::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/sig) {

	if (sig.is_emergency_stop)
		first_time = true;
}

/**
 * 
 * @param sig 
 */
void RoofConvoyer::save_color(
		::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/sig) {

	color = sig.color;
}

/**
 * 
 * @param sig 
 */
void RoofConvoyer::save_color(
		::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/sig) {
	color = sig.color;
}

/**
 * 
 * @return ret 
 */
bool RoofConvoyer::fromChoice1toSendReadyGuard() {

	return color == NONE;
}

/**
 * 
 * @return ret 
 */
bool RoofConvoyer::fromChoicetoMisplaceGuard() {

	return is_misplace == true;
}

/**
 * 
 */
void RoofConvoyer::go_initial_position() {

	if (first_time) {
		go_stop_position();
		go_wait_car();
	}
}

/**
 * 
 */
void RoofConvoyer::move_forward() {

	if (first_time) {
		take_car();
	}
}

/**
 * 
 */
void RoofConvoyer::replace() {

	if (first_time) {
		replace_car();
		go_wait_position();
	}
	first_time = false;
}

/**
 * 
 */
void RoofConvoyer::deliver() {

	pLCD.requiredIntf->clear(); //get_module()->ev3Brick.lcdScreen.clear();
	pLCD.requiredIntf->write_text(0, 20, "Deliver car ...",
			lcd::TextSize::LARGE);

	if (color != NONE) {
		delivered_car();
	} else {
		motor.set_duty_cycle_sp(50);
		motor.set_stop_command("coast");
		motor.set_position_sp(-800);
		motor.run_to_rel_pos();
		while (motor.speed() == 0) {
		}
		while (motor.speed() != 0) {
		}
	}
}

/**
 * 
 */
void RoofConvoyer::sendEndOfModuleEvent() {

	pModule.requiredIntf->setStatus(RESULT_READY);
	CarFactoryLibrary::events::EndOfModule s;
	pEndOfMo_Control.outIntf->push(s); //get_module()->sendEndOfModule(s);
	pEndOfMo_Shelf.outIntf->push(s); //get_shelf()->sendEndOfModule(s);
	pEndOfMo_Robotic.outIntf->push(s); //get_robotic_arm()->sendEndOfModule(s);
	pEndOfMo_Press.outIntf->push(s); //get_press()->sendEndOfModule(s);
}

/**
 * 
 */
void RoofConvoyer::sendPressAssembleEvent() {

	CarFactoryLibrary::events::PressAssemble s;
	pPressAssemble.outIntf->push(s); //get_press()->sendPressAssemble(s);
}

/**
 * 
 */
void RoofConvoyer::goCheckPresencePosition() {

	is_misplace = go_check_presence_position();
}

/**
 * 
 */
void RoofConvoyer::send_ready() {

	pModule.requiredIntf->setStatus(RESULT_READY); //set_status (RESULT_READY);
}

} // of namespace Roof
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of RoofConvoyer class body
 ************************************************************/
