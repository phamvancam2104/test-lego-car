// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_AbstractClasses_Actuators_AbstractServoMotor_BODY

/************************************************************
 AbstractServoMotor class body
 ************************************************************/

// include associated header file
#include "EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractServoMotor.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"

namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace Actuators {

// static attributes (if any)

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_command(
		::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractServoMotor::driver_name() {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractServoMotor::max_pulse_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_max_pulse_sp(::PrimitiveTypes::Integer /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractServoMotor::mid_pulse_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_mid_pulse_sp(::PrimitiveTypes::Integer /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractServoMotor::min_pulse_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_min_pulse_sp(::PrimitiveTypes::Integer /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractServoMotor::polarity() {
}

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_polarity(
		::EV3PapyrusLibrary::Types::LocalString /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractServoMotor::port_name() {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractServoMotor::position_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_position_sp(::PrimitiveTypes::Integer /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractServoMotor::rate_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractServoMotor::set_rate_sp(::PrimitiveTypes::Integer /*in*/v) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::ModeSet AbstractServoMotor::state() {
}

/**
 * 
 * @return ret 
 */
void AbstractServoMotor::run() {
}

/**
 * 
 * @return ret 
 */
void AbstractServoMotor::float_() {
}

/**
 * 
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
::PrimitiveTypes::Boolean AbstractServoMotor::connect(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
		::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match) {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Boolean AbstractServoMotor::connected() {
}

/**
 * 
 * @return ret 
 */
::PrimitiveTypes::Integer AbstractServoMotor::device_index() {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::PrimitiveTypes::Integer AbstractServoMotor::get_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
void AbstractServoMotor::set_attr_int(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::PrimitiveTypes::Integer /*in*/value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractServoMotor::get_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
void AbstractServoMotor::set_attr_string(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString& /*in*/value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractServoMotor::get_attr_line(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param pCur 
 */
::EV3PapyrusLibrary::Types::ModeSet AbstractServoMotor::get_attr_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
		::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
::EV3PapyrusLibrary::Types::LocalString AbstractServoMotor::get_attr_from_set(
		::EV3PapyrusLibrary::Types::LocalString& /*in*/name) {
}

} // of namespace Actuators
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of AbstractServoMotor class body
 ************************************************************/
