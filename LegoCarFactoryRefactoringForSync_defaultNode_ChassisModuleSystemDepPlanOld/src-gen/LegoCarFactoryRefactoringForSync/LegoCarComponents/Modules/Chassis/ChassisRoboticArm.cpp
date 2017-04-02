// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Chassis_ChassisRoboticArm_BODY

/************************************************************
 ChassisRoboticArm class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisRoboticArm.h"

// Derived includes directives
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/RoboticArmPickPiece.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Chassis {

// static attributes (if any)

/**
 * 
 * @return ret 
 */
bool ChassisRoboticArm::fromChoicetoSendDeliveredCarConveyorEventGuard() {
	return true; //get_current_module() != MASTER_MODULE
}

/**
 * 
 */
ChassisRoboticArm::ChassisRoboticArm() :
		::CarFactoryLibrary::RoboticArm("in3:i2c88:sv3", "in3:i2c88:sv2",
				"in3:i2c88:sv1", "in3:i2c88:sv4"), chassisroboticarmController(
				this) {
}

} // of namespace Chassis
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisRoboticArm class body
 ************************************************************/
