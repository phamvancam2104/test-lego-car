// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Front_FrontRoboticArm_BODY

/************************************************************
 FrontRoboticArm class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/FrontRoboticArm.h"

// Derived includes directives
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Front {

// static attributes (if any)

/**
 * 
 */
void FrontRoboticArm::stop_motors() {
	float_motors();
}

/**
 * 
 * @param sig 
 */
void FrontRoboticArm::save_rack_number(
		::CarFactoryLibrary::events::RoboticArmPickPiece& /*in*/sig) {
	rack_number = sig.rack_number;
}

/**
 * 
 */
void FrontRoboticArm::init() {
	run_motors();
	motor_pliers.open();
	go_rest_position_rack();
	float_motors();
}

/**
 * 
 */
void FrontRoboticArm::start_motors() {
	get_module()->ev3Brick.lcdScreen.clear();
	get_module()->ev3Brick.lcdScreen.write_text(0, 20, "Pick place...",
			lcd::TextSize::LARGE);

	run_motors();
}

/**
 * 
 */
void FrontRoboticArm::pick_front_part() {
	pick_front_part (rack_number);
}

/**
 * 
 */
void FrontRoboticArm::deliver_front_part() {
	deliver_front_part();
}

/**
 * 
 */
void FrontRoboticArm::replace_front_part() {
	replace_front_part();
}

/**
 * 
 */
void FrontRoboticArm::sendGoToPressEvent() {
	Events::GoToPress s;
	s.color = static_cast<CarFactoryLibrary::Colors>(rack_number);
	static_cast<FrontConveyor*>(get_conveyor())->sendGoToPress(s);
}

/**
 * 
 */
FrontRoboticArm::FrontRoboticArm() :
		frontroboticarmController(this) {
}

} // of namespace Front
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of FrontRoboticArm class body
 ************************************************************/