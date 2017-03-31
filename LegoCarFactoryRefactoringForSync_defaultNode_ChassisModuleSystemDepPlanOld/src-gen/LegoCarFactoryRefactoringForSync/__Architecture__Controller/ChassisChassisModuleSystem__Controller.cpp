// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_ChassisChassisModuleSystem__Controller_BODY

/************************************************************
 ChassisChassisModuleSystem__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ChassisChassisModuleSystem__Controller.h"

// Derived includes directives
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisModuleSystem.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 * @param origin 
 */
ChassisChassisModuleSystem__Controller::ChassisChassisModuleSystem__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisModuleSystem* /*in*/origin) :
		p_origin(origin) {
}

/**
 * 
 */
void ChassisChassisModuleSystem__Controller::createConnections() {
	// realization of connector <Connector_Chassis_to_Shelf>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.connect_pOutStopProcess_Shelf(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf) p_origin->shelf).chassisshelfController.get_pInStopProcess());

	// realization of connector <Connector_control_to_robotic_arm>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.connect_pOutStopProcess_RoboticArm(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm) p_origin->robotic_arm).chassisroboticarmController.get_pInStopProcess());

	// realization of connector <Connector1>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.connect_pStopProcess(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pStopProcess_Convoyer());

	// realization of connector <Connector2>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.connect_pOutRestart_Shelf(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf) p_origin->shelf).chassisshelfController.get_pInRestart());

	// realization of connector <Connector3>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.connect_pOutRestart_Robotic(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm) p_origin->robotic_arm).chassisroboticarmController.get_pInRestart());

	// realization of connector <Connector5>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.connect_pPrepare(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.get_pPrepare());

	// realization of connector <Connector6>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm) p_origin->robotic_arm).chassisroboticarmController.connect_pDelivered(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.get_pDelivered());

	// realization of connector <Connector7>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.connect_pCheckRack(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf) p_origin->shelf).chassisshelfController.get_pCheckRack());

	// realization of connector <Connector8>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.connect_pErrDetect(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pErrDetect());

	// realization of connector <Connector9>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.connect_pEndOfMo_Control(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pEndOfMo());

	// realization of connector <Connector10>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.connect_pEndOfMo_Shelf(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf) p_origin->shelf).chassisshelfController.get_pEndOfMo());

	// realization of connector <Connector11>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.connect_pEndOfMo_Robotic(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm) p_origin->robotic_arm).chassisroboticarmController.get_pEndOfMo());

	// realization of connector <Connector12>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf) p_origin->shelf).chassisshelfController.connect_pErrDetect(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pErrDetect());

	// realization of connector <Connector13>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisShelf) p_origin->shelf).chassisshelfController.connect_pPickPiece(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisRoboticArm) p_origin->robotic_arm).chassisroboticarmController.get_pPickPiece());

	// realization of connector <Connector20>
	((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.connect_pOutRestart_Convoyer(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisConvoyer) p_origin->convoyer).chassisconvoyerController.get_pRestart());

	// realization of connector <Connector27>
	((::CarFactoryLibrary::Conveyor) p_origin->convoyer).conveyorController.connect_pLCD(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pLCD());

	// realization of connector <Connector28>
	((::CarFactoryLibrary::Conveyor) p_origin->convoyer).conveyorController.connect_pModule(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pModule());

	// realization of connector <Connector29>
	((::CarFactoryLibrary::RoboticArm) p_origin->robotic_arm).roboticarmController.connect_pModule(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pModule());

	// realization of connector <Connector30>
	((::CarFactoryLibrary::RoboticArm) p_origin->robotic_arm).roboticarmController.connect_pLCD(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pLCD());

	// realization of connector <Connector31>
	((::CarFactoryLibrary::Shelf) p_origin->shelf).shelfController.connect_pModule(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pModule());

	// realization of connector <Connector32>
	((::CarFactoryLibrary::Shelf) p_origin->shelf).shelfController.connect_pLCD(
			((::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisControlComponent) p_origin->chassisController).chassiscontrolcomponentController.get_pLCD());

}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisChassisModuleSystem__Controller class body
 ************************************************************/
