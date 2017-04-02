// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_EV3BrickCppBlutooth__Controller_BODY

/************************************************************
 EV3BrickCppBlutooth__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/EV3BrickCppBlutooth__Controller.h"

// Derived includes directives
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IBlutooth.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 * @param origin 
 */
EV3BrickCppBlutooth__Controller::EV3BrickCppBlutooth__Controller(
		::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppBlutooth* /*in*/origin) :
		p_origin(origin) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IBlutooth* EV3BrickCppBlutooth__Controller::get_BluetoothPortServer() {
	p_origin->BluetoothPortServer.providedIntf = p_origin;
	return p_origin->BluetoothPortServer.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IBlutooth* EV3BrickCppBlutooth__Controller::get_BluetoothPortClient() {
	p_origin->BluetoothPortClient.providedIntf = p_origin;
	return p_origin->BluetoothPortClient.providedIntf;
}

/**
 * 
 * @param origin 
 */
EV3BrickCppBlutooth__Controller::EV3BrickCppBlutooth__Controller(
		::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppBlutooth* /*in*/origin) :
		p_origin(origin) {
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3BrickCppBlutooth__Controller class body
 ************************************************************/
