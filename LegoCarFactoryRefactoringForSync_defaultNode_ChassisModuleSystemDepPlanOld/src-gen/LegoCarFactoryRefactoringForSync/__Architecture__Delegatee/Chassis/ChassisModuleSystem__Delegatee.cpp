// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_Chassis_ChassisModuleSystem__Delegatee_BODY

/************************************************************
              ChassisModuleSystem__Delegatee class body
 ************************************************************/


// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Chassis/ChassisModuleSystem__Delegatee.h"

// Derived includes directives
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisModuleSystem.h"


namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Chassis {

// static attributes (if any)

/**
 * 
 * @param comp 
 */
void ChassisModuleSystem__Delegatee::setComponent(::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisModuleSystem* /*in*/ comp) {
	this->component = comp;
}

/**
 * 
 */
ChassisModuleSystem__Delegatee::ChassisModuleSystem__Delegatee() {
}

/**
 * 
 */
void ChassisModuleSystem__Delegatee::createConnections() {
	// realization of connector <Connector_Chassis_to_Shelf>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->chassisController.ChassisControlComponentDelegatee.connect_pOutStopProcess_Shelf(component->shelf.ChassisShelfDelegatee.get_pInStopProcess());
		}
	}for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.ChassisShelfDelegatee.connect_pInStopProcess(component->chassisController.ChassisControlComponentDelegatee.get_pOutStopProcess_Shelf());
		}
	}
	// realization of connector <Connector_control_to_robotic_arm>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->chassisController.ChassisControlComponentDelegatee.connect_pOutStopProcess_RoboticArm(component->robotic_arm.ChassisRoboticArmDelegatee.get_pInStopProcess());
		}
	}
	// realization of connector <Connector1>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pStopProcess(component->chassisController.ChassisControlComponentDelegatee.get_pStopProcess_Convoyer());
		}
	}
	// realization of connector <Connector2>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->chassisController.ChassisControlComponentDelegatee.connect_pOutRestart_Shelf(component->shelf.ChassisShelfDelegatee.get_pInRestart());
		}
	}
	// realization of connector <Connector3>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->chassisController.ChassisControlComponentDelegatee.connect_pOutRestart_Robotic(component->robotic_arm.ChassisRoboticArmDelegatee.get_pInRestart());
		}
	}
	// realization of connector <Connector5>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->chassisController.ChassisControlComponentDelegatee.connect_pPrepare(component->convoyer.ChassisConvoyerDelegatee.get_pPrepare());
		}
	}
	// realization of connector <Connector6>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->robotic_arm.ChassisRoboticArmDelegatee.connect_pDelivered(component->convoyer.ChassisConvoyerDelegatee.get_pDelivered());
		}
	}
	// realization of connector <Connector7>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pCheckRack(component->shelf.ChassisShelfDelegatee.get_pCheckRack());
		}
	}
	// realization of connector <Connector8>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pErrDetect(component->chassisController.ChassisControlComponentDelegatee.get_pErrDetect());
		}
	}
	// realization of connector <Connector9>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pEndOfMo_Control(component->chassisController.ChassisControlComponentDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector10>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pEndOfMo_Shelf(component->shelf.ChassisShelfDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector11>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pEndOfMo_Robotic(component->robotic_arm.ChassisRoboticArmDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector12>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.ChassisShelfDelegatee.connect_pErrDetect(component->chassisController.ChassisControlComponentDelegatee.get_pErrDetect());
		}
	}
	// realization of connector <Connector13>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.ChassisShelfDelegatee.connect_pPickPiece(component->robotic_arm.ChassisRoboticArmDelegatee.get_pPickPiece());
		}
	}
	// realization of connector <Connector20>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->chassisController.ChassisControlComponentDelegatee.connect_pOutRestart_Convoyer(component->convoyer.ChassisConvoyerDelegatee.get_pRestart());
		}
	}
	// realization of connector <Connector27>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pLCD(component->chassisController.ChassisControlComponentDelegatee.get_pLCD());
		}
	}
	// realization of connector <Connector28>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.ChassisConvoyerDelegatee.connect_pModule(component->chassisController.ChassisControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector29>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->robotic_arm.ChassisRoboticArmDelegatee.connect_pModule(component->chassisController.ChassisControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector30>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->robotic_arm.ChassisRoboticArmDelegatee.connect_pLCD(component->chassisController.ChassisControlComponentDelegatee.get_pLCD());
		}
	}
	// realization of connector <Connector31>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.ChassisShelfDelegatee.connect_pModule(component->chassisController.ChassisControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector32>
	for(int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.ChassisShelfDelegatee.connect_pLCD(component->chassisController.ChassisControlComponentDelegatee.get_pLCD());
		}
	}
}



} // of namespace Chassis
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of ChassisModuleSystem__Delegatee class body
 ************************************************************/
