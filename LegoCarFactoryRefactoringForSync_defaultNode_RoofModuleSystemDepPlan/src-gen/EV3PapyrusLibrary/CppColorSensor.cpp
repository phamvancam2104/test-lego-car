// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_CppColorSensor_BODY

/************************************************************
 CppColorSensor class body
 ************************************************************/

// include associated header file
#include "EV3PapyrusLibrary/CppColorSensor.h"

// Derived includes directives
#include "EV3PapyrusLibrary/IColorSensor.h"

namespace EV3PapyrusLibrary {

// static attributes (if any)

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::bin_data_format() {
	return referencedColor_sensor.bin_data_format();
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::CustomVectorChar CppColorSensor::bin_data() {
	return referencedColor_sensor.bin_data();
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::ModeSet CppColorSensor::commands() {
	return referencedColor_sensor.commands();
}

/**
 * 
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean CppColorSensor::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
	return ((device*) &referencedColor_sensor)->connect(dir, pattern, match);
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Boolean CppColorSensor::connected() {
	return referencedColor_sensor.connected();
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppColorSensor::decimals() {
	return referencedColor_sensor.decimals();
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppColorSensor::device_index() {
	return referencedColor_sensor.device_index();
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::driver_name() {
	return referencedColor_sensor.driver_name();
}

/**
 * 
 * @return ret 
 * @param index 
 */
float CppColorSensor::float_value(unsigned int /*in*/index) {
	return referencedColor_sensor.float_value(index);
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedColor_sensor)->get_attr_from_set(name);
}

/**
 * 
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer CppColorSensor::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedColor_sensor)->get_attr_int(name);
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedColor_sensor)->get_attr_line(name);
}

/**
 * 
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet CppColorSensor::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
	return ((device*) &referencedColor_sensor)->get_attr_set(name, pCur);
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedColor_sensor)->get_attr_string(name);
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::mode() {
	return referencedColor_sensor.mode();
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::ModeSet CppColorSensor::modes() {
	return referencedColor_sensor.modes();
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppColorSensor::num_values() {
	return referencedColor_sensor.num_values();
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::port_name() {
	return referencedColor_sensor.port_name();
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
void CppColorSensor::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
	((device*) &referencedColor_sensor)->set_attr_int(name, value);
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
void CppColorSensor::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
	((device*) &referencedColor_sensor)->set_attr_string(name, value);
}

/**
 * 
 * @param v 
 */
void CppColorSensor::set_command(
		::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
	referencedColor_sensor.set_command(v);
}

/**
 * 
 * @param v 
 */
void CppColorSensor::set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
	referencedColor_sensor.set_mode(v);
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::type_name() {
	return referencedColor_sensor.type_name();
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppColorSensor::units() {
	return referencedColor_sensor.units();
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppColorSensor::get_reflect_intensity() {
	//we configure it as reflect mode
	set_mode("COL-REFLECT");
	while (mode() != "COL-REFLECT") { //Solve problem with robot user in the initialization of the sensor
		set_mode("COL-REFLECT");
	}
	return value(0);
}

/**
 * 
 * @return ret 
 * @param index 
 */
::PrimitiveTypes::Integer CppColorSensor::value(unsigned int /*in*/index) {
	return referencedColor_sensor.value(index);
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppColorSensor::get_color() {
	set_mode("COL-COLOR");
	while (mode() != "COL-COLOR") { //Solve problem with robot user in the initialization of the sensor
		set_mode("COL-COLOR");
	}
	return value(0);
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer CppColorSensor::get_ambient_intensity() {
	set_mode("COL-AMBIENT");
	while (mode() != "COL-AMBIENT") { //Solve problem with robot user in the initialization of the sensor
		set_mode("COL-AMBIENT");
	}
	return value(0);
}

/**
 * 
 * @param portAdress 
 */
CppColorSensor::CppColorSensor(
		::EV3PapyrusLibrary::Types::LocalString /*in*/portAdress) :
		referencedColor_sensor(portAdress) {
}

} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppColorSensor class body
 ************************************************************/
