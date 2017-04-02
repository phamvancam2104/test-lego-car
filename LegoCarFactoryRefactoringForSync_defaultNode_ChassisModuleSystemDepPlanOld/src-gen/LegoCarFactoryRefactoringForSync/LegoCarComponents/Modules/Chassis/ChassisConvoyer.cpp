// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Chassis_ChassisConvoyer_BODY

/************************************************************
 ChassisConvoyer class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisConvoyer.h"

// Derived includes directives
#include "CarFactoryLibrary/events/CheckRack.h"
#include "CarFactoryLibrary/events/DeliveredCarConveyor.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
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
bool ChassisConvoyer::fromChoicetoMisplaceGuard() {
	return true; //get_status() == RESULT_ERROR
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 * @return ret true if the chassis is present and false otherwise
 */
bool ChassisConvoyer::check_presence() {
	/*
	 color_sensor.set_mode("COL-COLOR");
	 int color_state = 0;
	 bool ret = false;
	 //check white - black - white sequence
	 while(motor.speed() == 0);
	 while (motor.speed() != 0) {
	 char color = color_sensor.value(0);
	 if (color == 6 && color_state==0) { //first white wheel
	 color_state++;
	 }
	 if (color == 0 && color_state==1) { //none after white wheel
	 color_state++;
	 }
	 if (color == 6 && color_state==2) { //detect second white whell
	 color_state++;
	 ret = true;
	 }
	 }
	 
	 return ret;
	 */
	return 0;
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 * @return ret true if the chassis is present and false otherwise
 */
int ChassisConvoyer::get_current_module() {
	return 0;
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 * @return ret true if the chassis is present and false otherwise
 */
::CarFactoryLibrary::BluetoothSlaveEnum ChassisConvoyer::get_status() {
	return CarFactoryLibrary::NO_SLAVE_MSG;
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 * @param status true if the chassis is present and false otherwise
 */
void ChassisConvoyer::set_status(
		::CarFactoryLibrary::BluetoothSlaveEnum /*in*/status) {
	//get_module()->status = status;
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 */
void ChassisConvoyer::send_stop_process_event() {
	//Events::StopProcess s;
	//s.is_emergency_stop = true;
	//static_cast<ChassisModule*>(get_module())->sendStopProcess(s);
}

/**
 * 
 */
void ChassisConvoyer::effectFromChoicetoRestart() {
	first_time = true;
	send_stop_process_event();
}

/**
 * 
 * @return ret 
 */
bool ChassisConvoyer::fromChoice0toGo_wait_positionGuard() {
	return true;	//get_current_module() == MASTER_MODULE
}

/**
 * 
 * @return ret 
 */
bool ChassisConvoyer::fromChoice1toReplaceGuard() {
	return true;	//get_current_module() == MASTER_MODULE
}

/**
 * 
 * @return ret 
 */
bool ChassisConvoyer::fromChoice2toMisplaceGuard() {
	return true;	//is_misplace == true
}

/**
 * 
 * @return ret 
 */
bool ChassisConvoyer::fromChoice3toGo_wait_positionGuard() {
	return true;	//get_status() == RESULT_READY
}

/**
 * 
 * @return ret 
 */
bool ChassisConvoyer::fromChoicetoSendEndOfModuleEventGuard() {
	return true;	//get_status() == RESULT_READY
}

/**
 * 
 */
ChassisConvoyer::ChassisConvoyer() :
		::CarFactoryLibrary::Conveyor("outC", "in2:i2c80:mux1"), chassisconvoyerController(
				this) {
}

} // of namespace Chassis
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisConvoyer class body
 ************************************************************/
