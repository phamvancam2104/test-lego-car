// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Back_BackModuleSystem_BODY

/************************************************************
              BackModuleSystem class body
 ************************************************************/


// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackModuleSystem.h"

// Derived includes directives


namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Back {

// static attributes (if any)

/**
 * 
 */
BackModuleSystem::BackModuleSystem() {
}

/**
 * 
 */
void BackModuleSystem::connectorConfiguration() {
	bindPorts(conveyor.pCheckRack, shelf.pCheckRack);
	bindPorts(conveyor.pEndOfMo_Shelf, shelf.pEndOfMo);
	bindPorts(robotic_arm.pEndOfMo, conveyor.pEndOfMo_Robotic);
	bindPorts(conveyor.pDelivered, robotic_arm.pDelivered);
	bindPorts(robotic_arm.pPickPiece, shelf.pPickPiece);
	bindPorts(conveyor.pEndOfMo_Press, press.pEndOfMo);
	bindPorts(press.pPressAssemble, conveyor.pOutPressAssemble);
	bindPorts(controller.pOutStopProcess_Shelf, shelf.pInStopProcess);
	bindPorts(controller.pOutStopProcess_RoboticArm, robotic_arm.pInStopProcess);
	bindPorts(controller.pStopProcess_Convoyer, conveyor.pInStopProcess);
	bindPorts(shelf.pInRestart, controller.pOutRestart_Shelf);
	bindPorts(conveyor.pRestart, controller.pOutRestart_Convoyer);
	bindPorts(robotic_arm.pInRestart, controller.pOutRestart_Robotic);
	bindPorts(conveyor.pPrepare, controller.pPrepare);
	bindPorts(controller.pErrDetect, shelf.pErrDetect);
	bindPorts(controller.pEndOfMo, conveyor.pEndOfMo_Control);
	bindPorts(press.pModule, controller.pModule);
	bindPorts(press.pLCD, controller.pLCD);
	bindPorts(press.pILargeMotor, controller.pLargeMotorPress);
	bindPorts(controller.pFloatMotor, robotic_arm.pFloatMotor);
	bindPorts(controller.pLargeMotorConvoyer, conveyor.pILargeMotor);
	bindPorts(controller.pOutStopProcess_Press, press.pInStopProcess);
	bindPorts(controller.pOutRestart_Press, press.pInRestart);
	bindPorts(controller.pOutDelivered, conveyor.pDelivered);
	bindPorts(controller.pOutCheckRack, shelf.pCheckRack);
	bindPorts(conveyor.pGotoProcess, robotic_arm.pOutGotoProcess);
}



} // of namespace Back
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of BackModuleSystem class body
 ************************************************************/
