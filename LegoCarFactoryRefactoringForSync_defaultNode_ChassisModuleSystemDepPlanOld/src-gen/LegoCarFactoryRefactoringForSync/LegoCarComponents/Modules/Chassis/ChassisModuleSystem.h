// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_CHASSIS_CHASSISMODULESYSTEM_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_CHASSIS_CHASSISMODULESYSTEM_H

/************************************************************
 ChassisModuleSystem class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/Pkg_Chassis.h"

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisControlComponent.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisConvoyer.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisRoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisShelf.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ChassisChassisModuleSystem__Controller.h"

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Chassis {

/************************************************************/
/**
 * 
 */
class ChassisModuleSystem {
public:
	/**
	 * 
	 */
	ChassisControlComponent chassisController;
	/**
	 * 
	 */
	ChassisConvoyer convoyer;
	/**
	 * 
	 */
	ChassisRoboticArm robotic_arm;
	/**
	 * 
	 */
	ChassisShelf shelf;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ChassisChassisModuleSystem__Controller chassismodulesystemController;
	/**
	 * 
	 */
	ChassisModuleSystem();
	/**
	 * 
	 */
	void connectorConfiguration();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Chassis
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ChassisModuleSystem class header
 ************************************************************/

#endif
