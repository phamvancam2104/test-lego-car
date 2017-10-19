// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_AbstractClasses_AbstractNxtServo_BODY

/************************************************************
              AbstractNxtServo class body
 ************************************************************/


// include associated header file
#include "EV3PapyrusLibrary/AbstractClasses/AbstractNxtServo.h"

// Derived includes directives


namespace EV3PapyrusLibrary {
namespace AbstractClasses {

// static attributes (if any)

/**
 * 
 * @return ret 
 * @param power 
 */
 ::PrimitiveTypes::Boolean AbstractNxtServo::powered(::PrimitiveTypes::Integer /*in*/ power) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractNxtServo::stop_power() {
}

/**
 * generated comment
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
 ::PrimitiveTypes::Boolean AbstractNxtServo::connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ dir, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ pattern, ::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ match) {
}

/**
 * generated comment
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractNxtServo::connected() {
}

/**
 * generated comment
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractNxtServo::device_index() {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
 ::PrimitiveTypes::Integer AbstractNxtServo::get_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractNxtServo::set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::PrimitiveTypes::Integer /*in*/ value) {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractNxtServo::get_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractNxtServo::set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ value) {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractNxtServo::get_attr_line(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param pCur 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractNxtServo::get_attr_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString* /*in*/ pCur) {
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractNxtServo::get_attr_from_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}



} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractNxtServo class body
 ************************************************************/
