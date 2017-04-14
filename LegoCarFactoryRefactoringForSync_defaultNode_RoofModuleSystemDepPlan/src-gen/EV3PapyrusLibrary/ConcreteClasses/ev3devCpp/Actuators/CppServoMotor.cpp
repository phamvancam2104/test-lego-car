// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_ConcreteClasses_ev3devCpp_Actuators_CppServoMotor_BODY

/************************************************************
 CppServoMotor class body
 ************************************************************/

// include associated header file
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/CppServoMotor.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace Actuators {

// static attributes (if any)

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_command(
		::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
	referencedServo_motor.set_command(v);
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppServoMotor::driver_name() {
	return referencedServo_motor.driver_name();
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppServoMotor::max_pulse_sp() {
	return referencedServo_motor.max_pulse_sp();
}

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_max_pulse_sp(::PrimitiveTypes::Integer /*in*/v) {
	referencedServo_motor.set_max_pulse_sp(v);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppServoMotor::mid_pulse_sp() {
	return referencedServo_motor.mid_pulse_sp();
}

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_mid_pulse_sp(::PrimitiveTypes::Integer /*in*/v) {
	referencedServo_motor.set_mid_pulse_sp(v);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppServoMotor::min_pulse_sp() {
	return referencedServo_motor.min_pulse_sp();
}

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_min_pulse_sp(::PrimitiveTypes::Integer /*in*/v) {
	referencedServo_motor.set_min_pulse_sp(v);
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppServoMotor::polarity() {
	return referencedServo_motor.polarity();
}

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_polarity(
		::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
	referencedServo_motor.set_polarity(v);
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString CppServoMotor::port_name() {
	return referencedServo_motor.port_name();
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppServoMotor::position_sp() {
	return referencedServo_motor.position_sp();
}

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_position_sp(::PrimitiveTypes::Integer /*in*/v) {
	referencedServo_motor.set_position_sp(v);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppServoMotor::rate_sp() {
	return referencedServo_motor.rate_sp();
}

/**
 * generated comment
 * @param v 
 */
void CppServoMotor::set_rate_sp(::PrimitiveTypes::Integer /*in*/v) {
	referencedServo_motor.set_rate_sp(v);
}

/**
 * generated comment
 * @return ret 
 */
::EV3PapyrusLibrary::Types::ModeSet CppServoMotor::state() {
	return referencedServo_motor.state();
}

/**
 * generated comment
 * @return ret 
 */
void CppServoMotor::run() {
	return referencedServo_motor.run();
}

/**
 * generated comment
 * @return ret 
 */
void CppServoMotor::float_() {
	return referencedServo_motor.float_();
}

/**
 * generated comment
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean CppServoMotor::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
	return referencedServo_motor.connect(dir, pattern, match);
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Boolean CppServoMotor::connected() {
	return referencedServo_motor.connected();
}

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Integer CppServoMotor::device_index() {
	return referencedServo_motor.device_index();
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer CppServoMotor::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedServo_motor)->get_attr_int(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppServoMotor::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
	((device*) &referencedServo_motor)->set_attr_int(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppServoMotor::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedServo_motor)->get_attr_string(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param value 
 */
void CppServoMotor::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
	((device*) &referencedServo_motor)->set_attr_string(name, value);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppServoMotor::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedServo_motor)->get_attr_line(name);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet CppServoMotor::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
	return ((device*) &referencedServo_motor)->get_attr_set(name, pCur);
}

/**
 * generated comment
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString CppServoMotor::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
	return ((device*) &referencedServo_motor)->get_attr_from_set(name);
}

/**
 * generated comment
 * @param port_ 
 */
CppServoMotor::CppServoMotor(::EV3PapyrusLibrary::Types::PortType /*in*/port_) :
		referencedServo_motor(port_), cppservomotorController(this) {
}

} // of namespace Actuators
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppServoMotor class body
 ************************************************************/
