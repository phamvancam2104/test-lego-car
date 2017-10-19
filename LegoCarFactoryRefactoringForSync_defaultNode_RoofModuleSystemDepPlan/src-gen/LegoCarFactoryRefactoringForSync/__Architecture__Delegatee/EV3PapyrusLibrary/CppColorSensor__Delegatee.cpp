// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_EV3PapyrusLibrary_CppColorSensor__Delegatee_BODY

/************************************************************
 CppColorSensor__Delegatee class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/EV3PapyrusLibrary/CppColorSensor__Delegatee.h"

// Derived includes directives
#include "EV3PapyrusLibrary/CppColorSensor.h"
#include "EV3PapyrusLibrary/IColorSensor.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace EV3PapyrusLibrary {

// static attributes (if any)

/**
 * 
 * @param comp 
 */
void CppColorSensor__Delegatee::setComponent(
		::EV3PapyrusLibrary::CppColorSensor* /*in*/comp) {
	this->component = comp;
	this->get_colorSensorPort();
}

/**
 * 
 */
CppColorSensor__Delegatee::CppColorSensor__Delegatee() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::IColorSensor* CppColorSensor__Delegatee::get_colorSensorPort() {
	component->colorSensorPort.providedIntf = component;
	return component->colorSensorPort.providedIntf;
}

} // of namespace EV3PapyrusLibrary
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CppColorSensor__Delegatee class body
 ************************************************************/
