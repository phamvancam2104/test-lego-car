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
	p_origin->chassisController.chassiscontrolcomponentController.connect_pOutStopProcess_Shelf(
			p_origin->shelf.chassisshelfController.get_pInStopProcess());
	p_origin->shelf.chassisshelfController.connect_pInStopProcess(
			p_origin->chassisController.chassiscontrolcomponentController.get_pOutStopProcess_Shelf());

	// realization of connector <Connector_control_to_robotic_arm>
	p_origin->chassisController.chassiscontrolcomponentController.connect_pOutStopProcess_RoboticArm(
			p_origin->robotic_arm.chassisroboticarmController.get_pInStopProcess());

	// realization of connector <Connector1>
	p_origin->convoyer.chassisconvoyerController.connect_pStopProcess(
			p_origin->chassisController.chassiscontrolcomponentController.get_pStopProcess_Convoyer());

	// realization of connector <Connector2>
	p_origin->chassisController.chassiscontrolcomponentController.connect_pOutRestart_Shelf(
			p_origin->shelf.chassisshelfController.get_pInRestart());

	// realization of connector <Connector3>
	p_origin->chassisController.chassiscontrolcomponentController.connect_pOutRestart_Robotic(
			p_origin->robotic_arm.chassisroboticarmController.get_pInRestart());

	// realization of connector <Connector5>
	p_origin->chassisController.chassiscontrolcomponentController.connect_pPrepare(
			p_origin->convoyer.chassisconvoyerController.get_pPrepare());

	// realization of connector <Connector6>
	p_origin->robotic_arm.chassisroboticarmController.connect_pDelivered(
			p_origin->convoyer.chassisconvoyerController.get_pDelivered());

	// realization of connector <Connector7>
	p_origin->convoyer.chassisconvoyerController.connect_pCheckRack(
			p_origin->shelf.chassisshelfController.get_pCheckRack());

	// realization of connector <Connector8>
	p_origin->convoyer.chassisconvoyerController.connect_pErrDetect(
			p_origin->chassisController.chassiscontrolcomponentController.get_pErrDetect());

	// realization of connector <Connector9>
	p_origin->convoyer.chassisconvoyerController.connect_pEndOfMo_Control(
			p_origin->chassisController.chassiscontrolcomponentController.get_pEndOfMo());

	// realization of connector <Connector10>
	p_origin->convoyer.chassisconvoyerController.connect_pEndOfMo_Shelf(
			p_origin->shelf.chassisshelfController.get_pEndOfMo());

	// realization of connector <Connector11>
	p_origin->convoyer.chassisconvoyerController.connect_pEndOfMo_Robotic(
			p_origin->robotic_arm.chassisroboticarmController.get_pEndOfMo());

	// realization of connector <Connector12>
	p_origin->shelf.chassisshelfController.connect_pErrDetect(
			p_origin->chassisController.chassiscontrolcomponentController.get_pErrDetect());

	// realization of connector <Connector13>
	p_origin->shelf.chassisshelfController.connect_pPickPiece(
			p_origin->robotic_arm.chassisroboticarmController.get_pPickPiece());

	// realization of connector <Connector20>
	p_origin->chassisController.chassiscontrolcomponentController.connect_pOutRestart_Convoyer(
			p_origin->convoyer.chassisconvoyerController.get_pRestart());

	// realization of connector <Connector27>
	p_origin->convoyer.chassisconvoyerController.connect_pLCD(
			p_origin->chassisController.chassiscontrolcomponentController.get_pLCD());

	// realization of connector <Connector28>
	p_origin->convoyer.chassisconvoyerController.connect_pModule(
			p_origin->chassisController.chassiscontrolcomponentController.get_pModule());

	// realization of connector <Connector29>
	p_origin->robotic_arm.chassisroboticarmController.connect_pModule(
			p_origin->chassisController.chassiscontrolcomponentController.get_pModule());

	// realization of connector <Connector30>
	p_origin->robotic_arm.chassisroboticarmController.connect_pLCD(
			p_origin->chassisController.chassiscontrolcomponentController.get_pLCD());

	// realization of connector <Connector31>
	p_origin->shelf.chassisshelfController.connect_pModule(
			p_origin->chassisController.chassiscontrolcomponentController.get_pModule());

	// realization of connector <Connector32>
	p_origin->shelf.chassisshelfController.connect_pLCD(
			p_origin->chassisController.chassiscontrolcomponentController.get_pLCD());

}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisChassisModuleSystem__Controller class body
 ************************************************************/
