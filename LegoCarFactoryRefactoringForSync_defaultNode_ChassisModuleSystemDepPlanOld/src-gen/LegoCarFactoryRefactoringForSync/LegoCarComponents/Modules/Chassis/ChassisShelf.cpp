// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Chassis_ChassisShelf_BODY

/************************************************************
 ChassisShelf class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisShelf.h"

// Derived includes directives
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
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
bool ChassisShelf::fromWhich_racktoSecond_rackGuard() {
	return !is_empty(2);
}

/**
 * 
 * @return ret 
 */
bool ChassisShelf::fromChoicetoWait_endGuard() {
	return get_status() == RESULT_READY;
}

/**
 * 
 * @return ret 
 */
bool ChassisShelf::fromChoicetoEmpty_rackGuard() {
	return get_status() == RESULT_ERROR;
}

/**
 * 
 * @return ret 
 */
bool ChassisShelf::fromTesttoNot_Master_ModuleGuard() {
	return get_current_module() != MASTER_MODULE;
}

/**
 * 
 * @return ret 
 */
bool ChassisShelf::fromWhich_racktoFirst_rackGuard() {
	return !is_empty(1);
}

/**
 * 
 */
ChassisShelf::ChassisShelf() :
		chassisshelfController(this) {
}

} // of namespace Chassis
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisShelf class body
 ************************************************************/