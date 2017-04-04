// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_ConcreteClasses_ev3devCpp_CppNxtServo_BODY

/************************************************************
 CppNxtServo class body
 ************************************************************/

// include associated header file
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/CppNxtServo.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/INxtServo.h"

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {

// static attributes (if any)

/**
 * 
 * @return ret 
 * @param power 
 */
::PrimitiveTypes::Boolean CppNxtServo::powered(
		::PrimitiveTypes::Integer /*in*/power) {
	return referencedNxt_servo.powered(power);
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Boolean CppNxtServo::stop_power() {
	return referencedNxt_servo.stop_power();
}

/**
 * generated comment
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean CppNxtServo::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
	return referencedNxt_servo.connect(dir, pattern, match);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Boolean CppNxtServo::connected() {
	return referencedNxt_servo.connected();
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppNxtServo::device_index() {
	return referencedNxt_servo.device_index();
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer CppNxtServo::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return referencedNxt_servo.get_attr_int(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppNxtServo::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
	referencedNxt_servo.set_attr_int(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppNxtServo::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return referencedNxt_servo.get_attr_string(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppNxtServo::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
	referencedNxt_servo.set_attr_string(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppNxtServo::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return referencedNxt_servo.get_attr_line(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet CppNxtServo::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
	return referencedNxt_servo.get_attr_set(name, pCur);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppNxtServo::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return referencedNxt_servo.get_attr_from_set(name);
}

/**
 * 
 * @param sensor_port 
 */
CppNxtServo::CppNxtServo(
		::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_port) :
		referencedNxt_servo(sensor_port) {
}

/**
 * 
 * @param motor_port 
 * @param sensor_port 
 */
CppNxtServo::CppNxtServo(
		::EV3PapyrusLibrary::Types::LocalString /*in*/motor_port,
		::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_port) :
		referencedNxt_servo(motor_port, sensor_port) {
}

} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppNxtServo class body
 ************************************************************/
