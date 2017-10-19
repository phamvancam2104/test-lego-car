// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Delegatee_EV3Brick_CppBlutooth__Delegatee_BODY

/************************************************************
 CppBlutooth__Delegatee class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/EV3Brick/CppBlutooth__Delegatee.h"

// Derived includes directives
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IBlutooth.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace EV3Brick {

// static attributes (if any)

/**
 * 
 * @param comp 
 */
void CppBlutooth__Delegatee::setComponent(
		::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppBlutooth* /*in*/comp) {
	this->component = comp;
	for (int i = 0; i < 0; i++) {
		this->get_BluetoothPortServer(i);
	}
	for (int i = 0; i < 0; i++) {
		this->get_BluetoothPortClient(i);
	}
	for (int i = 0; i < 0; i++) {
		this->get_BluetoothPortServer(i);
	}
	for (int i = 0; i < 0; i++) {
		this->get_BluetoothPortClient(i);
	}
}

/**
 * 
 */
CppBlutooth__Delegatee::CppBlutooth__Delegatee() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IBlutooth* CppBlutooth__Delegatee::get_BluetoothPortServer() {
	component->BluetoothPortServer.providedIntf = component;
	return component->BluetoothPortServer.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IBlutooth* CppBlutooth__Delegatee::get_BluetoothPortClient() {
	component->BluetoothPortClient.providedIntf = component;
	return component->BluetoothPortClient.providedIntf;
}

} // of namespace EV3Brick
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CppBlutooth__Delegatee class body
 ************************************************************/
