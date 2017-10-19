// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Back_BackConvoyer_BODY

/************************************************************
              BackConvoyer class body
 ************************************************************/


// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackConvoyer.h"

// Derived includes directives
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "CarFactoryLibrary/events/PressAssemble.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/CppLargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "LegoCarFactoryRefactoringForSync/signals/GoToPress.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"


namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Back {

// static attributes (if any)
/**
 * the command to send to the motor to go from the stop position to wait car position (from the other module)
 */
 int  BackConvoyer::wait_car_offset=-180;
/**
 * the command to send to the motor to go from the stop position to wait car position (from the other module)
 */
 int  BackConvoyer::take_car_offset=-208;
/**
 * 
 */
 ::CarFactoryLibrary::Colors  BackConvoyer::color;

/**
 * 
 */
void BackConvoyer::sendErrorDetectionEvent() {
	CarFactoryLibrary::events::ErrorDetection s;
		pErrDetect.outIntf->push(s); //get_module()->sendErrorDetection(s);
		s.is_misplace = true;
		set_status(CarFactoryLibrary::RESULT_ERROR);
}

/**
 * 
 */
void BackConvoyer::go_wait_car() {
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
void BackConvoyer::take_car() {
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
 * @return ret 
 */
 bool BackConvoyer::check_presence() {
	color_sensor.set_mode("COL-COLOR");
		bool ret = false;
		//wait for the and of the movement
		while (motor.speed() == 0)
			;
		while (motor.speed() != 0)
			;
	
		//check color
		int obtain_color = color_sensor.value(0);
	
		switch (color) {
		case CarFactoryLibrary::RED:
			if (obtain_color == 5) { //blue=2; red = 5 and white=6
				ret = true;
			}
			break;
		case CarFactoryLibrary::WHITE:
			if (obtain_color == 6) { //blue=2; red = 5 and white=6
				ret = true;
			}
			break;
		case CarFactoryLibrary::BLUE:
			if (obtain_color == 2) { //blue=2; red = 5 and white=6
				ret = true;
			}
			break;
		case CarFactoryLibrary::NONE:
			ret = true;
			break;
		}
	
		if (ret) {
			motor.set_duty_cycle_sp(30);
			motor.set_stop_command("brake");
			motor.set_position_sp(48);
			motor.run_to_rel_pos();
			//wait for the and of the movement
			while (motor.speed() == 0)
				;
			while (motor.speed() != 0)
				;
		}
		return ret;
}

/**
 * 
 * @param status 
 */
void BackConvoyer::set_status(::CarFactoryLibrary::BluetoothSlaveEnum /*in*/ status) {
	pModule.requiredIntf->setStatus(status);
}

/**
 * 
 * @return ret 
 */
 ::CarFactoryLibrary::BluetoothSlaveEnum BackConvoyer::get_status() {
	return pModule.requiredIntf->getStatus();
}

/**
 * 
 */
BackConvoyer::BackConvoyer(): CarFactoryLibrary::Conveyor("outC", "in1") {
}

/**
 * 
 * @param sig 
 */
void BackConvoyer::effectFromPrincipalStatetoRestart(::LegoCarFactoryRefactoringForSync::signals::StopProcess& /*in*/ sig) {
	if (sig.is_emergency_stop)
			first_time = true;
}

/**
 * 
 * @param sig 
 */
void BackConvoyer::save_color(::LegoCarFactoryRefactoringForSync::signals::PrepareConveyor& /*in*/ sig) {
	color = sig.color;
}

/**
 * 
 * @param sig 
 */
void BackConvoyer::save_color(::LegoCarFactoryRefactoringForSync::signals::GoToPress& /*in*/ sig) {
	color = sig.color;
}

/**
 * 
 * @return ret 
 */
 bool BackConvoyer::fromChoicetoMisplaceGuard() {
	return is_misplace == true;
}

/**
 * 
 */
void BackConvoyer::go_initial_position() {
	if (first_time) {
				go_stop_position();
				go_wait_car();
			}
}

/**
 * 
 */
void BackConvoyer::move_forward() {
	if (first_time) {
			take_car();
		}
}

/**
 * 
 */
void BackConvoyer::Entry_go_wait_position() {
	pLCD.requiredIntf->clear();//get_module()->ev3Brick.lcdScreen.clear();
		pLCD.requiredIntf->write_text(0, 20, "Load car ...",
				lcd::TextSize::LARGE);
	
		go_wait_position();
	
		set_status (RESULT_READY);
}

/**
 * 
 */
void BackConvoyer::goCheckPresencePosition() {
	is_misplace = go_check_presence_position();
}

/**
 * 
 */
void BackConvoyer::replace() {
	if (first_time) {
			replace_car();
			go_wait_position();
		}
		first_time = false;
}

/**
 * 
 */
void BackConvoyer::deliver() {
	pLCD.requiredIntf->clear(); //get_module()->ev3Brick.lcdScreen.clear();
		pLCD.requiredIntf->write_text(0, 20, "Deliver car ...",
				lcd::TextSize::LARGE);
	
		delivered_car();
}

/**
 * 
 */
void BackConvoyer::sendEndOfModuleEvent() {
	set_status (RESULT_READY);
		CarFactoryLibrary::events::EndOfModule s;
		pEndOfMo_Control.outIntf->push(s); //get_module()->sendEndOfModule(s);
		pEndOfMo_Shelf.outIntf->push(s); //get_shelf()->sendEndOfModule(s);
		pEndOfMo_Robotic.outIntf->push(s); //get_robotic_arm()->sendEndOfModule(s);
		pEndOfMo_Press.outIntf->push(s); //get_press()->sendEndOfModule(s);
}

/**
 * 
 */
void BackConvoyer::sendPressAssembleEvent() {
	CarFactoryLibrary::events::PressAssemble s;
		pOutPressAssemble.outIntf->push(s); //get_press()->sendPressAssemble(s);
}



} // of namespace Back
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of BackConvoyer class body
 ************************************************************/
