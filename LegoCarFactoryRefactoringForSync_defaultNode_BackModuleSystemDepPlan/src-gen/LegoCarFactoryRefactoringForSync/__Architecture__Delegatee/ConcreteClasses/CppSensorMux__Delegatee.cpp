// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_ConcreteClasses_CppSensorMux__Delegatee_BODY

/************************************************************
 CppSensorMux__Delegatee class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/ConcreteClasses/CppSensorMux__Delegatee.h"

// Derived includes directives
#include "MindsensorsPapyrusLibrary/ConcreteClasses/CppSensorMux.h"
#include "MindsensorsPapyrusLibrary/Interfaces/ISensorMux.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace ConcreteClasses {

// static attributes (if any)

/**
 * 
 * @param comp 
 */
void CppSensorMux__Delegatee::setComponent(
		::MindsensorsPapyrusLibrary::ConcreteClasses::CppSensorMux* /*in*/comp) {
	this->component = comp;
	this->get_sensorMuxPort_host();
}

/**
 * 
 */
CppSensorMux__Delegatee::CppSensorMux__Delegatee() {
}

/**
 * 
 * @return ret 
 */
::MindsensorsPapyrusLibrary::Interfaces::ISensorMux* CppSensorMux__Delegatee::get_sensorMuxPort_host() {
	component->sensorMuxPort_host.providedIntf = component;
	return component->sensorMuxPort_host.providedIntf;
}

} // of namespace ConcreteClasses
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CppSensorMux__Delegatee class body
 ************************************************************/
