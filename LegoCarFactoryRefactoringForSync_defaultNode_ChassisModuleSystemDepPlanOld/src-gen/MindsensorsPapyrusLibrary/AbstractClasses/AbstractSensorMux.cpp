// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define MindsensorsPapyrusLibrary_AbstractClasses_AbstractSensorMux_BODY

/************************************************************
 AbstractSensorMux class body
 ************************************************************/

// include associated header file
#include "MindsensorsPapyrusLibrary/AbstractClasses/AbstractSensorMux.h"

// Derived includes directives

namespace MindsensorsPapyrusLibrary {
namespace AbstractClasses {

// static attributes (if any)

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::type_name() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::bin_data_format() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::CustomVectorChar AbstractSensorMux::bin_data() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::driver_name() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::mode() {
}

/**
 * 
 * @param v 
 */
void AbstractSensorMux::set_mode(
		::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::ModeSet AbstractSensorMux::modes() {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::port_name() {
}

/**
 * 
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean AbstractSensorMux::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Boolean AbstractSensorMux::connected() {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractSensorMux::device_index() {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer AbstractSensorMux::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
void AbstractSensorMux::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
void AbstractSensorMux::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet AbstractSensorMux::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractSensorMux::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 */
AbstractSensorMux::AbstractSensorMux() :
		abstractsensormuxController(this) {
}

} // of namespace AbstractClasses
} // of namespace MindsensorsPapyrusLibrary

/************************************************************
 End of AbstractSensorMux class body
 ************************************************************/
