// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef OTHERCOMPONENTSPAPYRUSLIBRARY_ABSTRACTCLASSES_ABSTRACTLEDSTATUS_H
#define OTHERCOMPONENTSPAPYRUSLIBRARY_ABSTRACTCLASSES_ABSTRACTLEDSTATUS_H

/************************************************************
 AbstractLedStatus class header
 ************************************************************/

#include "OtherComponentsPapyrusLibrary/AbstractClasses/Pkg_AbstractClasses.h"

// Include from Include stereotype (header)
#include <stdint.h>
// End of Include stereotype (header)

namespace OtherComponentsPapyrusLibrary {
namespace AbstractClasses {

/************************************************************/
/**
 * 
 */
class AbstractLedStatus {
public:
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

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace AbstractClasses
} // of namespace OtherComponentsPapyrusLibrary

/************************************************************
 End of AbstractLedStatus class header
 ************************************************************/

#endif
