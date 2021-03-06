// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Slaves_SlaveShelf_BODY

/************************************************************
 SlaveShelf class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/SlaveShelf.h"

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
namespace Slaves {

// static attributes (if any)

/**
 * 
 */
void SlaveShelf::sendRoboticArmPickPieceEvent() {
	CarFactoryLibrary::events::RoboticArmPickPiece s;
	s.rack_number = which_rack;
	pPickPiece.outIntf->push(s); //get_roboticArm()->sendRoboticArmPickPiece(s);
}

/**
 * 
 * @return ret 
 */
::CarFactoryLibrary::BluetoothSlaveEnum SlaveShelf::get_status() {
	return pModule.requiredIntf->getStatus();
}

/**
 * 
 * @param status 
 */
void SlaveShelf::set_status(
		::CarFactoryLibrary::BluetoothSlaveEnum /*in*/status) {
	pModule.requiredIntf->setStatus(status);
}

/**
 * 
 * @param sig 
 */
void SlaveShelf::save_which_rack(
		::CarFactoryLibrary::events::CheckRack& /*in*/sig) {
	which_rack = sig.color;
}

/**
 * 
 * @return ret 
 */
bool SlaveShelf::() {
	return !is_empty(which_rack);
}

/**
 * 
 */
void SlaveShelf::sendErrorDetectionEvent() {
	CarFactoryLibrary::events::ErrorDetection s;
	s.is_misplace = false;
	get_module()->sendErrorDetection(s);
	set_status(CarFactoryLibrary::RESULT_ERROR);
}

/**
 * 
 */
SlaveShelf::SlaveShelf() :
		::CarFactoryLibrary::Shelf(2, "in2:i2c82:mux3", "in2:i2c81:mux2") {
}

} // of namespace Slaves
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SlaveShelf class body
 ************************************************************/
