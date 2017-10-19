// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_AbstractColorSensor_BODY

/************************************************************
              AbstractColorSensor class body
 ************************************************************/


// include associated header file
#include "EV3PapyrusLibrary/AbstractColorSensor.h"

// Derived includes directives
#include "EV3PapyrusLibrary/IColorSensor.h"


namespace EV3PapyrusLibrary {

// static attributes (if any)

/**
 * 
 * @return ret 
 * @param index 
 */
 ::PrimitiveTypes::Integer AbstractColorSensor::value(unsigned int /*in*/ index) {
}

/**
 * 
 * @return ret 
 * @param index 
 */
 float AbstractColorSensor::float_value(unsigned int /*in*/ index) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::type_name() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::bin_data_format() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::CustomVectorChar AbstractColorSensor::bin_data() {
}

/**
 * 
 * @param v 
 */
void AbstractColorSensor::set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractColorSensor::commands() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractColorSensor::decimals() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::driver_name() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::mode() {
}

/**
 * 
 * @param v 
 */
void AbstractColorSensor::set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractColorSensor::modes() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractColorSensor::num_values() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::port_name() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::units() {
}

/**
 * 
 * @return ret 
 * @param  
 */
 ::PrimitiveTypes::Boolean AbstractColorSensor::connect(::EV3PapyrusLibrary::Types::MapStringSetString /*in*/ ) {
}

/**
 * 
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
 ::PrimitiveTypes::Boolean AbstractColorSensor::connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ dir, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ pattern, ::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ match) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractColorSensor::connected() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractColorSensor::device_index() {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::PrimitiveTypes::Integer AbstractColorSensor::get_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractColorSensor::set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::PrimitiveTypes::Integer /*in*/ value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::get_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractColorSensor::set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::get_attr_line(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param pCur 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractColorSensor::get_attr_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString* /*in*/ pCur) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractColorSensor::get_attr_from_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}



} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractColorSensor class body
 ************************************************************/
