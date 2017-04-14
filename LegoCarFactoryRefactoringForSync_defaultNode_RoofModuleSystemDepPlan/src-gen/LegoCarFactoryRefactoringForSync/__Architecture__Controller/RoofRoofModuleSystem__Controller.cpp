// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_RoofRoofModuleSystem__Controller_BODY

/************************************************************
 RoofRoofModuleSystem__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/RoofRoofModuleSystem__Controller.h"

// Derived includes directives
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofModuleSystem.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 * @param origin 
 */
RoofRoofModuleSystem__Controller::RoofRoofModuleSystem__Controller(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Roof::RoofModuleSystem* /*in*/origin) :
		p_origin(origin) {
}

/**
 * 
 */
void RoofRoofModuleSystem__Controller::createConnections() {
	// realization of connector <connector_pDelivered_to_pDelivered_DeliveredCarConveyor>
	p_origin->robotic_arm.roofroboticarmController.connect_pDelivered(
			p_origin->convoyer.roofconvoyerController.get_pDelivered());

	// realization of connector <connector_pOutStopProcess_Shelf_to_pInStopProcess_StopProcess>
	p_origin->control.roofcontrolcomponentController.connect_pOutStopProcess_Shelf(
			p_origin->shelf.slaveshelfController.get_pInStopProcess());

	// realization of connector <connector_pOutStopProcess_RoboticArm_to_pInStopProcess_StopProcess>
	p_origin->control.roofcontrolcomponentController.connect_pOutStopProcess_RoboticArm(
			p_origin->robotic_arm.roofroboticarmController.get_pInStopProcess());

	// realization of connector <connector_pStopProcess_Convoyer_to_pInStopProcess_StopProcess>
	p_origin->control.roofcontrolcomponentController.connect_pStopProcess_Convoyer(
			p_origin->convoyer.roofconvoyerController.get_pInStopProcess());

	// realization of connector <connector_pOutRestart_Shelf_to_pInRestart_RestartAfterEmergencyStop>
	p_origin->control.roofcontrolcomponentController.connect_pOutRestart_Shelf(
			p_origin->shelf.slaveshelfController.get_pInRestart());

	// realization of connector <connector_pOutRestart_Convoyer_to_pRestart_RestartAfterEmergencyStop>
	p_origin->control.roofcontrolcomponentController.connect_pOutRestart_Convoyer(
			p_origin->convoyer.roofconvoyerController.get_pRestart());

	// realization of connector <connector_pOutRestart_Robotic_to_pInRestart_RestartAfterEmergencyStop>
	p_origin->control.roofcontrolcomponentController.connect_pOutRestart_Robotic(
			p_origin->robotic_arm.roofroboticarmController.get_pInRestart());

	// realization of connector <connector_pCheckRack_to_pCheckRack_CheckRack>
	p_origin->convoyer.roofconvoyerController.connect_pCheckRack(
			p_origin->shelf.slaveshelfController.get_pCheckRack());

	// realization of connector <connector_pErrDetect_to_pErrDetect_ErrorDetection>
	p_origin->convoyer.roofconvoyerController.connect_pErrDetect(
			p_origin->control.roofcontrolcomponentController.get_pErrDetect());

	// realization of connector <connector_pEndOfMo_to_pEndOfMo_Control_EndOfModule>
	p_origin->convoyer.roofconvoyerController.connect_pEndOfMo_Control(
			p_origin->control.roofcontrolcomponentController.get_pEndOfMo());

	// realization of connector <connector_pEndOfMo_Shelf_to_pEndOfMo_EndOfModule>
	p_origin->convoyer.roofconvoyerController.connect_pEndOfMo_Shelf(
			p_origin->shelf.slaveshelfController.get_pEndOfMo());

	// realization of connector <connector_pEndOfMo_to_pEndOfMo_Robotic_EndOfModule>
	p_origin->convoyer.roofconvoyerController.connect_pEndOfMo_Robotic(
			p_origin->robotic_arm.roofroboticarmController.get_pEndOfMo());

	// realization of connector <connector_pEndOfMo_to_pErrDetect_EndOfModule>
	p_origin->shelf.slaveshelfController.connect_pErrDetect(
			p_origin->control.roofcontrolcomponentController.get_pEndOfMo());

	// realization of connector <connector_pPickPiece_to_pPickPiece_RoboticArmPickPiece>
	p_origin->shelf.slaveshelfController.connect_pPickPiece(
			p_origin->robotic_arm.roofroboticarmController.get_pPickPiece());

	// realization of connector <connector_pFloatMotor_to_pFloatMotor_IRoboticArmFloatMotor>
	p_origin->control.roofcontrolcomponentController.connect_pFloatMotor(
			p_origin->robotic_arm.roofroboticarmController.get_pFloatMotor());

	// realization of connector <connector_pLargeMotor_Convoyer_to_pLargeMotor_ILargeMotor>
	p_origin->control.roofcontrolcomponentController.connect_pLargeMotor_Convoyer(
			p_origin->convoyer.roofconvoyerController.get_pLargeMotor());

	// realization of connector <connector_pLargeMotor_Press_to_pILargeMotor_ILargeMotor>
	p_origin->control.roofcontrolcomponentController.connect_pLargeMotor_Press(
			p_origin->press.slavepressController.get_pILargeMotor());

	// realization of connector <connector_pStopProcess_Press_to_pInStopProcess_StopProcess>
	p_origin->control.roofcontrolcomponentController.connect_pStopProcess_Press(
			p_origin->press.slavepressController.get_pInStopProcess());

	// realization of connector <connector_pOutRestart_Press_to_pInRestart_RestartAfterEmergencyStop>
	p_origin->control.roofcontrolcomponentController.connect_pOutRestart_Press(
			p_origin->press.slavepressController.get_pInRestart());

	// realization of connector <connector_pOutDelivered_to_pDelivered_DeliveredCarConveyor>
	p_origin->control.roofcontrolcomponentController.connect_pOutDelivered(
			p_origin->convoyer.roofconvoyerController.get_pDelivered());

	// realization of connector <connector_pOutCheckRack_to_pCheckRack_CheckRack>
	p_origin->control.roofcontrolcomponentController.connect_pOutCheckRack(
			p_origin->shelf.slaveshelfController.get_pCheckRack());

	// realization of connector <connector_pPressAssemble_to_pPressAssemble_PressAssemble>
	p_origin->convoyer.roofconvoyerController.connect_pPressAssemble(
			p_origin->press.slavepressController.get_pPressAssemble());

	// realization of connector <connector_pEndOfMo_Press_to_pEndOfMo_EndOfModule>
	p_origin->convoyer.roofconvoyerController.connect_pEndOfMo_Press(
			p_origin->press.slavepressController.get_pEndOfMo());

	// realization of connector <connector_pOutGotoProcess_to_pGotoProcess_GoToPress>
	p_origin->robotic_arm.roofroboticarmController.connect_pOutGotoProcess(
			p_origin->convoyer.roofconvoyerController.get_pGotoProcess());

}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of RoofRoofModuleSystem__Controller class body
 ************************************************************/
