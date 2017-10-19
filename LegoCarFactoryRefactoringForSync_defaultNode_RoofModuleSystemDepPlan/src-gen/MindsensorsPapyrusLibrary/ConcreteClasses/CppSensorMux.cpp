// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define MindsensorsPapyrusLibrary_ConcreteClasses_CppSensorMux_BODY

/************************************************************
 CppSensorMux class body
 ************************************************************/

// include associated header file
#include "MindsensorsPapyrusLibrary/ConcreteClasses/CppSensorMux.h"

// Derived includes directives
#include "MindsensorsPapyrusLibrary/Interfaces/ISensorMux.h"

namespace MindsensorsPapyrusLibrary {
namespace ConcreteClasses {

// static attributes (if any)

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::type_name() {
	return referencedSensor_mux.type_name();
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::bin_data_format() {
	return referencedSensor_mux.bin_data_format();
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::driver_name() {
	return referencedSensor_mux.driver_name();
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::CustomVectorChar CppSensorMux::bin_data() {
	return referencedSensor_mux.bin_data();
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::mode() {
	return referencedSensor_mux.mode();
}

/**
 * generated comment
 * @param v 
 */
void CppSensorMux::set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
	referencedSensor_mux.set_mode(v);
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::ModeSet CppSensorMux::modes() {
	return referencedSensor_mux.modes();
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::port_name() {
	return referencedSensor_mux.port_name();
}

/**
 * generated comment
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean CppSensorMux::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
	return ((device*) &referencedSensor_mux)->connect(dir, pattern, match);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Boolean CppSensorMux::connected() {
	return referencedSensor_mux.connected();
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppSensorMux::device_index() {
	return referencedSensor_mux.device_index();
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer CppSensorMux::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedSensor_mux)->get_attr_int(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppSensorMux::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
	((device*) &referencedSensor_mux)->set_attr_int(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedSensor_mux)->get_attr_string(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppSensorMux::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
	((device*) &referencedSensor_mux)->set_attr_string(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedSensor_mux)->get_attr_line(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet CppSensorMux::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
	return ((device*) &referencedSensor_mux)->get_attr_set(name, pCur);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppSensorMux::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedSensor_mux)->get_attr_from_set(name);
}

/**
 * 
 * @param portAddress 
 * @param sensorTypes 
 */
CppSensorMux::CppSensorMux(
		::EV3PapyrusLibrary::Types::LocalString /*in*/portAddress,
		::MindsensorsPapyrusLibrary::Types::VectorLocalString /*in*/sensorTypes) :
		referencedSensor_mux(portAddress, sensorTypes) {
}

} // of namespace ConcreteClasses
} // of namespace MindsensorsPapyrusLibrary

/************************************************************
 End of CppSensorMux class body
 ************************************************************/
