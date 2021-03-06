// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPBUTTON_H
#define EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPBUTTON_H

/************************************************************
              CppButton class header
 ************************************************************/

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/Pkg_EV3Brick.h"

#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractButton.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IButton.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/EV3Brick/CppButton__Delegatee.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
namespace EV3PapyrusLibrary {namespace Interfaces {namespace EV3Brick {class IButton;}}}

// End of Include stereotype (header)


namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class CppButton : 
public ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton, 
public ::EV3PapyrusLibrary::AbstractClasses::EV3Brick::AbstractButton	
 {
	public:
	/**
	 * 
	 */
	 button referencedButton;
	DECLARE_DELEGATEE_COMPONENT (CppButton)
	/**
	 * generated comment
	 * @return ret 
	 */
	 ::PrimitiveTypes::Boolean pressed();
	/**
	 * generated comment
	 * @return ret 
	 */
	 ::PrimitiveTypes::Boolean process();
	/**
	 * generated comment
	 * @return ret 
	 */
	 ::PrimitiveTypes::Boolean process_all();
	/**
	 * 
	 * @param index 
	 */
	CppButton(::PrimitiveTypes::Integer /*in*/ index);


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3Brick
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of CppButton class header
 ************************************************************/

#endif
