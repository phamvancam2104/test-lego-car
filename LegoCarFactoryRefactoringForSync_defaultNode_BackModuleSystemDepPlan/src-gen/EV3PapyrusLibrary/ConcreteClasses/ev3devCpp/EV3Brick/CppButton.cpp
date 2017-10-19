// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_ConcreteClasses_ev3devCpp_EV3Brick_CppButton_BODY

/************************************************************
              CppButton class body
 ************************************************************/


// include associated header file
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppButton.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IButton.h"


namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

// static attributes (if any)

/**
 * generated comment
 * @return ret 
 */
 ::PrimitiveTypes::Boolean CppButton::pressed() {
	return referencedButton.pressed();
}

/**
 * generated comment
 * @return ret 
 */
 ::PrimitiveTypes::Boolean CppButton::process() {
	return referencedButton.process();
}

/**
 * generated comment
 * @return ret 
 */
 ::PrimitiveTypes::Boolean CppButton::process_all() {
	return referencedButton.process_all();
}

/**
 * 
 * @param index 
 */
CppButton::CppButton(::PrimitiveTypes::Integer /*in*/ index): referencedButton(index) {
}



} // of namespace EV3Brick
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of CppButton class body
 ************************************************************/
