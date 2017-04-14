// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_ROOF_ROOFMODULESYSTEM_H
#define LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS_MODULES_ROOF_ROOFMODULESYSTEM_H

/************************************************************
 RoofModuleSystem class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/Pkg_Roof.h"

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofControlComponent.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofConvoyer.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Roof/RoofRoboticArm.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/SlavePress.h"
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/SlaveShelf.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/RoofRoofModuleSystem__Controller.h"

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Roof {

/************************************************************/
/**
 * 
 */
class RoofModuleSystem {
public:
	/**
	 * 
	 */
	RoofControlComponent control;
	/**
	 * 
	 */
	RoofConvoyer convoyer;
	/**
	 * 
	 */
	RoofRoboticArm robotic_arm;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Slaves::SlaveShelf shelf;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Slaves::SlavePress press;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::RoofRoofModuleSystem__Controller roofmodulesystemController;
	/**
	 * 
	 */
	RoofModuleSystem();
	/**
	 * 
	 */
	void connectorConfiguration();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Roof
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of RoofModuleSystem class header
 ************************************************************/

#endif
