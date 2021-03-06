// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_AbstractClasses_Actuators_AbstractLargeMotor_BODY

/************************************************************
              AbstractLargeMotor class body
 ************************************************************/


// include associated header file
#include "EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractLargeMotor.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"


namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace Actuators {

// static attributes (if any)

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractLargeMotor::commands() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::count_per_rot() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::driver_name() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::duty_cycle() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::duty_cycle_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_duty_cycle_sp(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::encoder_polarity() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_encoder_polarity(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::polarity() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_polarity(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::port_name() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::position() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_position(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::position_p() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_position_p(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::position_i() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_position_i(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::position_d() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_position_d(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::position_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_position_sp(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::speed() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::speed_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_speed_sp(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::ramp_up_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_ramp_up_sp(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::ramp_down_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_ramp_down_sp(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::speed_regulation_enabled() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_speed_regulation_enabled(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::speed_regulation_p() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_speed_regulation_p(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::speed_regulation_i() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_speed_regulation_i(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::speed_regulation_d() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_speed_regulation_d(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractLargeMotor::state() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::stop_command() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_stop_command(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractLargeMotor::stop_commands() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::time_sp() {
}

/**
 * 
 * @param v 
 */
void AbstractLargeMotor::set_time_sp(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::run_forever() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::run_to_abs_pos() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::run_to_rel_pos() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::run_timed() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::run_direct() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::stop() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLargeMotor::reset() {
}

/**
 * 
 * @return ret 
 * @param arg0 
 */
 ::PrimitiveTypes::Boolean AbstractLargeMotor::connect(::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ arg0) {
}

/**
 * 
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
 ::PrimitiveTypes::Boolean AbstractLargeMotor::connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ dir, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ pattern, ::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ match) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractLargeMotor::connected() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::device_index() {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::PrimitiveTypes::Integer AbstractLargeMotor::get_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractLargeMotor::set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::PrimitiveTypes::Integer /*in*/ value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::get_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractLargeMotor::set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::get_attr_line(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param pCur 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractLargeMotor::get_attr_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString* /*in*/ pCur) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLargeMotor::get_attr_from_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}



} // of namespace Actuators
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractLargeMotor class body
 ************************************************************/
