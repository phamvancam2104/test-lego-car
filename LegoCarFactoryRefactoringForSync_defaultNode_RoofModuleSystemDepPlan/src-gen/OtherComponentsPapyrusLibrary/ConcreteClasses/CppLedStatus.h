// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef OTHERCOMPONENTSPAPYRUSLIBRARY_CONCRETECLASSES_CPPLEDSTATUS_H
#define OTHERCOMPONENTSPAPYRUSLIBRARY_CONCRETECLASSES_CPPLEDSTATUS_H

/************************************************************
 CppLedStatus class header
 ************************************************************/

#include "OtherComponentsPapyrusLibrary/ConcreteClasses/Pkg_ConcreteClasses.h"

#include "OtherComponentsPapyrusLibrary/AbstractClasses/AbstractLedStatus.h"
#include "OtherComponentsPapyrusLibrary/Interfaces/ILedStatus.h"
#include "OtherComponentsPapyrusLibrary/Types/Pkg_Types.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
// End of Include stereotype (header)

namespace OtherComponentsPapyrusLibrary {
namespace ConcreteClasses {

/************************************************************/
/**
 * 
 */
class CppLedStatus: public ::OtherComponentsPapyrusLibrary::Interfaces::ILedStatus,
		public ::OtherComponentsPapyrusLibrary::AbstractClasses::AbstractLedStatus {
public:
	/**
	 * 
	 */
	led_status referencedLed_status;
	/**
	 * 
	 */
	void all_led_on();
	/**
	 * 
	 */
	void all_led_off();
	/**
	 * 
	 */
	void red_led();
	/**
	 * 
	 */
	void orange_led();
	/**
	 * 
	 */
	void green_led();
	/**
	 * 
	 * @param red_port 
	 * @param orange_port 
	 * @param green_port 
	 */
	CppLedStatus(
			::OtherComponentsPapyrusLibrary::Types::LocalString /*in*/red_port,
			::OtherComponentsPapyrusLibrary::Types::LocalString /*in*/orange_port,
			::OtherComponentsPapyrusLibrary::Types::LocalString /*in*/green_port);
	/**
	 * 
	 */
	CppLedStatus();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace ConcreteClasses
} // of namespace OtherComponentsPapyrusLibrary

/************************************************************
 End of CppLedStatus class header
 ************************************************************/

#endif
