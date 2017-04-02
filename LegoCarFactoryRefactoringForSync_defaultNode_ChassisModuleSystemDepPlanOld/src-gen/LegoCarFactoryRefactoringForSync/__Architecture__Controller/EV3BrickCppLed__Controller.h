// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3BRICKCPPLED__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3BRICKCPPLED__CONTROLLER_H

/************************************************************
 EV3BrickCppLed__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {
class CppLed;
}
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILed;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class EV3BrickCppLed__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	EV3BrickCppLed__Controller(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* get_ledPort();
	/**
	 * 
	 * @param origin 
	 */
	EV3BrickCppLed__Controller(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* /*in*/origin);

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* p_origin;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3BrickCppLed__Controller class header
 ************************************************************/

#endif
