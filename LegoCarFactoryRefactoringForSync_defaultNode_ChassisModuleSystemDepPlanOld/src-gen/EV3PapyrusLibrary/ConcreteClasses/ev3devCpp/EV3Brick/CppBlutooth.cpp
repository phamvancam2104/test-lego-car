// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_ConcreteClasses_ev3devCpp_EV3Brick_CppBlutooth_BODY

/************************************************************
 CppBlutooth class body
 ************************************************************/

// include associated header file
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IBlutooth.h"

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

// static attributes (if any)

/**
 * 
 * @param name 
 * @return ret 
 */
::PrimitiveTypes::Boolean CppBlutooth::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return referencedBluetooth.connect(name);
}

/**
 * 
 * @param name 
 * @return ret 
 */
::PrimitiveTypes::Boolean CppBlutooth::accept_connection(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return referencedBluetooth.accept_connection(name);
}

/**
 * 
 * @param name 
 * @param result 
 * @return ret 
 */
::PrimitiveTypes::Boolean CppBlutooth::read(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/result) {
	return referencedBluetooth.read(name, result);
}

/**
 * 
 * @param name 
 * @param msg 
 * @return ret 
 */
::PrimitiveTypes::Boolean CppBlutooth::write(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/msg) {
	return referencedBluetooth.write(name, msg);
}

/**
 * 
 * @param uselessString 
 */
CppBlutooth::CppBlutooth(
		::EV3PapyrusLibrary::Types::LocalString /*in*/uselessString) :
		referencedBluetooth(), cppblutoothController(this) {
}

} // of namespace EV3Brick
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppBlutooth class body
 ************************************************************/
