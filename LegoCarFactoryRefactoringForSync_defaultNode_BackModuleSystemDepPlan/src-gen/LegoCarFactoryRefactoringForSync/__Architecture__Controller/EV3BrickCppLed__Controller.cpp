// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_EV3BrickCppLed__Controller_BODY

/************************************************************
 EV3BrickCppLed__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/EV3BrickCppLed__Controller.h"

// Derived includes directives
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLed.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 * @param origin 
 */
EV3BrickCppLed__Controller::EV3BrickCppLed__Controller(
		::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* /*in*/origin) :
		p_origin(origin) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* EV3BrickCppLed__Controller::get_ledPort() {
	p_origin->ledPort.providedIntf = p_origin;
	return p_origin->ledPort.providedIntf;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3BrickCppLed__Controller class body
 ************************************************************/