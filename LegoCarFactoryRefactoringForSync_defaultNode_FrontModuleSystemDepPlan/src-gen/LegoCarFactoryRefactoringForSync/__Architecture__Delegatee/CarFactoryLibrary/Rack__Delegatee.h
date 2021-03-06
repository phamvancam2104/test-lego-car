// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_CARFACTORYLIBRARY_RACK__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_CARFACTORYLIBRARY_RACK__DELEGATEE_H

/************************************************************
 Rack__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/CarFactoryLibrary/Pkg_CarFactoryLibrary.h"

// Include from Include stereotype (header)
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::CarFactoryLibrary;

// End of Include stereotype (header)

namespace CarFactoryLibrary {
class Rack;
}
namespace EV3PapyrusLibrary {
class IColorSensor;
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace CarFactoryLibrary {

/************************************************************/
/**
 * 
 */
class Rack__Delegatee {
public:
	/**
	 * 
	 * @param comp 
	 */
	void setComponent(::CarFactoryLibrary::Rack* /*in*/comp);
	/**
	 * 
	 */
	Rack__Delegatee();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor();

private:
	/**
	 * 
	 */
	::CarFactoryLibrary::Rack* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace CarFactoryLibrary
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of Rack__Delegatee class header
 ************************************************************/

#endif
