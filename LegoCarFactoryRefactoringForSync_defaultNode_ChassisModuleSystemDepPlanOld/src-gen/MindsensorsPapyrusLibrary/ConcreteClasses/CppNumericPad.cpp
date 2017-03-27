// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define MindsensorsPapyrusLibrary_ConcreteClasses_CppNumericPad_BODY

/************************************************************
 CppNumericPad class body
 ************************************************************/

// include associated header file
#include "MindsensorsPapyrusLibrary/ConcreteClasses/CppNumericPad.h"

// Derived includes directives
#include "MindsensorsPapyrusLibrary/Interfaces/INumericPad.h"

namespace MindsensorsPapyrusLibrary {
namespace ConcreteClasses {

// static attributes (if any)

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppNumericPad::read_current_touched_key() {
	return referencedNumeric_pad.read_current_touched_key();
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppNumericPad::read_next_touched_key() {
	return referencedNumeric_pad.read_next_touched_key();
}

/**
 * generated comment
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean CppNumericPad::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
	return ((device*) &referencedNumeric_pad)->connect(dir, pattern, match);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Boolean CppNumericPad::connected() {
	return referencedNumeric_pad.connected();
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppNumericPad::device_index() {
	return referencedNumeric_pad.device_index();
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer CppNumericPad::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedNumeric_pad)->get_attr_int(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppNumericPad::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
	((device*) &referencedNumeric_pad)->set_attr_int(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppNumericPad::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedNumeric_pad)->get_attr_string(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppNumericPad::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
	((device*) &referencedNumeric_pad)->set_attr_string(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppNumericPad::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedNumeric_pad)->get_attr_line(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet CppNumericPad::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
	return ((device*) &referencedNumeric_pad)->get_attr_set(name, pCur);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppNumericPad::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedNumeric_pad)->get_attr_from_set(name);
}

/**
 * 
 * @param port 
 */
CppNumericPad::CppNumericPad(::EV3PapyrusLibrary::Types::LocalString /*in*/port) :
		referencedNumeric_pad(port), cppnumericpadController(this) {
}

} // of namespace ConcreteClasses
} // of namespace MindsensorsPapyrusLibrary

/************************************************************
 End of CppNumericPad class body
 ************************************************************/