// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define OtherComponentsPapyrusLibrary_ConcreteClasses_CppLedStatus_BODY

/************************************************************
              CppLedStatus class body
 ************************************************************/


// include associated header file
#include "OtherComponentsPapyrusLibrary/ConcreteClasses/CppLedStatus.h"

// Derived includes directives
#include "OtherComponentsPapyrusLibrary/Interfaces/ILedStatus.h"


namespace OtherComponentsPapyrusLibrary {
namespace ConcreteClasses {

// static attributes (if any)

/**
 * 
 */
void CppLedStatus::all_led_on() {
	referencedLed_status.all_led_on();
}

/**
 * 
 */
void CppLedStatus::all_led_off() {
	referencedLed_status.all_led_off();
}

/**
 * 
 */
void CppLedStatus::red_led() {
	referencedLed_status.red_led();
}

/**
 * 
 */
void CppLedStatus::orange_led() {
	referencedLed_status.orange_led();
}

/**
 * 
 */
void CppLedStatus::green_led() {
	referencedLed_status.green_led();
}

/**
 * 
 * @param red_port 
 * @param orange_port 
 * @param green_port 
 */
CppLedStatus::CppLedStatus(::OtherComponentsPapyrusLibrary::Types::LocalString /*in*/ red_port, ::OtherComponentsPapyrusLibrary::Types::LocalString /*in*/ orange_port, ::OtherComponentsPapyrusLibrary::Types::LocalString /*in*/ green_port): referencedLed_status(red_port, orange_port, green_port) {
}

/**
 * 
 */
CppLedStatus::CppLedStatus() {
}



} // of namespace ConcreteClasses
} // of namespace OtherComponentsPapyrusLibrary

/************************************************************
              End of CppLedStatus class body
 ************************************************************/
