// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_Front_FrontModuleSystem__Delegatee_BODY

/************************************************************
 FrontModuleSystem__Delegatee class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Front/FrontModuleSystem__Delegatee.h"

// Derived includes directives
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/FrontModuleSystem.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Front {

// static attributes (if any)

/**
 * 
 * @param comp 
 */
void FrontModuleSystem__Delegatee::setComponent(
		::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Front::FrontModuleSystem* /*in*/comp) {
	this->component = comp;
}

/**
 * 
 */
FrontModuleSystem__Delegatee::FrontModuleSystem__Delegatee() {
}

/**
 * 
 */
void FrontModuleSystem__Delegatee::createConnections() {
	// realization of connector <Connector1>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutStopProcess_Shelf(
					component->shelf.SlaveShelfDelegatee.get_pInStopProcess());
		}
	}
	// realization of connector <Connector2>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutStopProcess_RoboticArm(
					component->roboticArm.FrontRoboticArmDelegatee.get_pStopProcess());
		}
	}
	// realization of connector <Connector3>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pStopProcess_Convoyer(
					component->convoyer.FrontConvoyerDelegatee.get_pInStopProcess());
		}
	}
	// realization of connector <Connector4>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutStopProcess_Press(
					component->press.SlavePressDelegatee.get_pInStopProcess());
		}
	}
	// realization of connector <Connector5>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutRestart_Shelf(
					component->shelf.SlaveShelfDelegatee.get_pInRestart());
		}
	}
	// realization of connector <Connector6>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutRestart_Convoyer(
					component->convoyer.FrontConvoyerDelegatee.get_pRestart());
		}
	}
	// realization of connector <Connector7>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutRestart_Robotic(
					component->roboticArm.FrontRoboticArmDelegatee.get_pInRestart());
		}
	}
	// realization of connector <Connector8>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pOutRestart_Press(
					component->press.SlavePressDelegatee.get_pInRestart());
		}
	}
	// realization of connector <Connector9>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pPrepare(
					component->convoyer.FrontConvoyerDelegatee.get_pPrepare());
		}
	}
	// realization of connector <Connector10>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pCheckRack(
					component->shelf.SlaveShelfDelegatee.get_pCheckRack());
		}
	}
	// realization of connector <Connector11>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pDelivered(
					component->convoyer.FrontConvoyerDelegatee.get_pDelivered());
		}
	}
	// realization of connector <Connector12>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->roboticArm.FrontRoboticArmDelegatee.connect_pDelivered(
					component->convoyer.FrontConvoyerDelegatee.get_pDelivered());
		}
	}
	// realization of connector <Connector13>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			int cumulative = 0;
			//connect all interfaces of star attribute to ports connected to the outside port in a star pattern
			pStopProcess_controller_StarAttributeInterfaces[cumulative++] =
					component->controller.FrontControlComponentDelegatee.get_pOutStopProcess_RoboticArm();
			pStopProcess_controller_StarAttributeInterfaces[cumulative++] =
					component->convoyer.FrontConvoyerDelegatee.get_pInStopProcess();
			pStopProcess_controller_StarAttribute.setInterfaces(
					(pStopProcess_controller_StarAttributeInterfaces), 2);
			component->roboticArm.FrontRoboticArmDelegatee.connect_pStopProcess(
					&(pStopProcess_controller_StarAttribute));
		}
	}
	// realization of connector <Connector14>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pCheckRack(
					component->shelf.SlaveShelfDelegatee.get_pCheckRack());
		}
	}
	// realization of connector <Connector15>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pErrDetect(
					component->controller.FrontControlComponentDelegatee.get_pErrDetect());
		}
	}
	// realization of connector <Connector16>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pEndOfMo_Control(
					component->controller.FrontControlComponentDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector17>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pEndOfMo_Shelf(
					component->shelf.SlaveShelfDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector18>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pEndOfMo_Robotic(
					component->roboticArm.FrontRoboticArmDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector19>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pEndOfMo_Press(
					component->press.SlavePressDelegatee.get_pEndOfMo());
		}
	}
	// realization of connector <Connector20>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.SlaveShelfDelegatee.connect_pErrDetect(
					component->controller.FrontControlComponentDelegatee.get_pErrDetect());
		}
	}
	// realization of connector <Connector21>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.SlaveShelfDelegatee.connect_pPickPiece(
					component->roboticArm.FrontRoboticArmDelegatee.get_pPickPiece());
		}
	}
	// realization of connector <Connector22>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pOutAssemble(
					component->press.SlavePressDelegatee.get_pPressAssemble());
		}
	}
	// realization of connector <Connector23>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->roboticArm.FrontRoboticArmDelegatee.connect_pLCD(
					component->controller.FrontControlComponentDelegatee.get_pLCD());
		}
	}
	// realization of connector <Connector24>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.SlaveShelfDelegatee.connect_pLCD(
					component->controller.FrontControlComponentDelegatee.get_pLCD());
		}
	}
	// realization of connector <Connector25>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->press.SlavePressDelegatee.connect_pLCD(
					component->controller.FrontControlComponentDelegatee.get_pLCD());
		}
	}
	// realization of connector <Connector26>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pLCD(
					component->controller.FrontControlComponentDelegatee.get_pLCD());
		}
	}
	// realization of connector <Connector27>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->roboticArm.FrontRoboticArmDelegatee.connect_pModule(
					component->controller.FrontControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector28>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->convoyer.FrontConvoyerDelegatee.connect_pModule(
					component->controller.FrontControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector29>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->shelf.SlaveShelfDelegatee.connect_pModule(
					component->controller.FrontControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector30>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->press.SlavePressDelegatee.connect_pModule(
					component->controller.FrontControlComponentDelegatee.get_pModule());
		}
	}
	// realization of connector <Connector31>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pIFloatMotor(
					component->roboticArm.FrontRoboticArmDelegatee.get_pIFloatMotor());
		}
	}
	// realization of connector <Connector32>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pILargeMotor(
					component->convoyer.FrontConvoyerDelegatee.get_pILargeMotor());
		}
	}
	// realization of connector <Connector33>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->controller.FrontControlComponentDelegatee.connect_pPressILargeMotor(
					component->press.SlavePressDelegatee.get_pILargeMotor());
		}
	}
	// realization of connector <Connector34>
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			component->roboticArm.FrontRoboticArmDelegatee.connect_pGotoProcess(
					component->convoyer.FrontConvoyerDelegatee.get_pGotoProcess());
		}
	}
}

} // of namespace Front
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of FrontModuleSystem__Delegatee class body
 ************************************************************/
