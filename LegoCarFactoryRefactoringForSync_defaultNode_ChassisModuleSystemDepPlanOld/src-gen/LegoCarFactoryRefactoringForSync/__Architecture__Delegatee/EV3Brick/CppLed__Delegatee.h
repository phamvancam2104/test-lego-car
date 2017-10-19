// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_EV3BRICK_CPPLED__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_EV3BRICK_CPPLED__DELEGATEE_H

/************************************************************
              CppLed__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/EV3Brick/Pkg_EV3Brick.h"


// Include from Include stereotype (header)
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::EV3Brick;

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {namespace ConcreteClasses {namespace ev3devCpp {namespace EV3Brick {class CppLed;}}}}
namespace EV3PapyrusLibrary {namespace Interfaces {namespace EV3Brick {class ILed;}}}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class CppLed__Delegatee {
	public:
	/**
	 * 
	 * @param comp 
	 */
	void setComponent(::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* /*in*/ comp);
	/**
	 * 
	 */
	CppLed__Delegatee();
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* get_ledPort();


	private:
	/**
	 * 
	 */
	 ::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3Brick
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of CppLed__Delegatee class header
 ************************************************************/

#endif