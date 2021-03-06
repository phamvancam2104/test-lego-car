// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_EV3BRICK_CPPBUTTON__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_EV3BRICK_CPPBUTTON__DELEGATEE_H

/************************************************************
 CppButton__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/EV3Brick/Pkg_EV3Brick.h"

// Include from Include stereotype (header)
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::EV3Brick;

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {
class CppButton;
}
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class IButton;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class CppButton__Delegatee {
public:
	/**
	 * 
	 * @param comp 
	 */
	void setComponent(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton* /*in*/comp);
	/**
	 * 
	 */
	CppButton__Delegatee();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_buttonPort();

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3Brick
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CppButton__Delegatee class header
 ************************************************************/

#endif
