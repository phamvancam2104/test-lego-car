// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_AbstractClasses_EV3Brick_AbstractLed_BODY

/************************************************************
              AbstractLed class body
 ************************************************************/


// include associated header file
#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLed.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"


namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace EV3Brick {

// static attributes (if any)

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLed::max_brightness() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLed::brightness() {
}

/**
 * 
 * @param v 
 */
void AbstractLed::set_brightness(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractLed::triggers() {
}

/**
 * 
 * @return ret 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLed::trigger() {
}

/**
 * 
 * @param v 
 */
void AbstractLed::set_trigger(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLed::delay_on() {
}

/**
 * 
 * @param v 
 */
void AbstractLed::set_delay_on(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLed::delay_off() {
}

/**
 * 
 * @param v 
 */
void AbstractLed::set_delay_off(::PrimitiveTypes::Integer /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 float AbstractLed::brightness_pct() {
}

/**
 * 
 * @param v 
 */
void AbstractLed::set_brightness_pct(float /*in*/ v) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::on() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::off() {
}

/**
 * 
 * @return ret 
 * @param on_ms 
 * @param off_ms 
 */
 void AbstractLed::flash(unsigned int /*in*/ on_ms, unsigned int /*in*/ off_ms) {
}

/**
 * 
 * @return ret 
 * @param red 
 * @param green 
 */
 void AbstractLed::mix_colors(float /*in*/ red, float /*in*/ green) {
}

/**
 * 
 * @return ret 
 * @param intensity 
 */
 void AbstractLed::set_red(float /*in*/ intensity) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::red_on() {
}

/**
 * 
 * @return ret 
 * @param intensity 
 */
 void AbstractLed::set_green(float /*in*/ intensity) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::green_on() {
}

/**
 * 
 * @return ret 
 * @param intensity 
 */
 void AbstractLed::set_amber(float /*in*/ intensity) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::amber_on() {
}

/**
 * 
 * @return ret 
 * @param intensity 
 */
 void AbstractLed::set_orange(float /*in*/ intensity) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::orange_on() {
}

/**
 * 
 * @return ret 
 * @param intensity 
 */
 void AbstractLed::set_yellow(float /*in*/ intensity) {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::yellow_on() {
}

/**
 * 
 * @return ret 
 */
 void AbstractLed::all_off() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractLed::connected() {
}

/**
 * 
 * @return ret 
 */
 ::PrimitiveTypes::Integer AbstractLed::device_index() {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::PrimitiveTypes::Integer AbstractLed::get_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractLed::set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::PrimitiveTypes::Integer /*in*/ value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLed::get_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param value 
 */
 void AbstractLed::set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ value) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLed::get_attr_line(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param name 
 * @param pCur 
 */
 ::EV3PapyrusLibrary::Types::ModeSet AbstractLed::get_attr_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString* /*in*/ pCur) {
}

/**
 * 
 * @return ret 
 * @param name 
 */
 ::EV3PapyrusLibrary::Types::LocalString AbstractLed::get_attr_from_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @return ret 
 * @param dir 
 * @param pattern 
 * @param match 
 */
 ::PrimitiveTypes::Boolean AbstractLed::connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ dir, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ pattern, ::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ match) {
}



} // of namespace EV3Brick
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractLed class body
 ************************************************************/
