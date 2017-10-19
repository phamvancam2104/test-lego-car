// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_CHASSIS_CHASSISMODULESYSTEM__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_CHASSIS_CHASSISMODULESYSTEM__DELEGATEE_H

/************************************************************
              ChassisModuleSystem__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Chassis/Pkg_Chassis.h"


// Include from Include stereotype (header)
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Chassis;

// End of Include stereotype (header)

namespace LegoCarFactoryRefactoringForSync {namespace LegoCarComponents {namespace Modules {namespace Chassis {class ChassisModuleSystem;}}}}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Chassis {

/************************************************************/
/**
 * 
 */
class ChassisModuleSystem__Delegatee {
	public:
	/**
	 * 
	 * @param comp 
	 */
	void setComponent(::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisModuleSystem* /*in*/ comp);
	/**
	 * 
	 */
	ChassisModuleSystem__Delegatee();
	/**
	 * 
	 */
	void createConnections();


	private:
	/**
	 * 
	 */
	 ::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Chassis::ChassisModuleSystem* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace Chassis
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of ChassisModuleSystem__Delegatee class header
 ************************************************************/

#endif
