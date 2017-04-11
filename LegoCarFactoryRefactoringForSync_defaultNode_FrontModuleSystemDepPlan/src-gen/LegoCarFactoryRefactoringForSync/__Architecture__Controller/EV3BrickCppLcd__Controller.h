// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3BRICKCPPLCD__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3BRICKCPPLCD__CONTROLLER_H

/************************************************************
 EV3BrickCppLcd__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {
class CppLcd;
}
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILcd;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class EV3BrickCppLcd__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	EV3BrickCppLcd__Controller(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLcd* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* get_lcdScreenPort();
	/**
	 * 
	 * @param origin 
	 */
	EV3BrickCppLcd__Controller(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLcd* /*in*/origin);

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLcd* p_origin;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLcd* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3BrickCppLcd__Controller class header
 ************************************************************/

#endif
