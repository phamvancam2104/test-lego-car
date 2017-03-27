// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_INTERFACES_EV3BRICK_ILED_H
#define EV3PAPYRUSLIBRARY_INTERFACES_EV3BRICK_ILED_H

/************************************************************
 ILed class header
 ************************************************************/

#include "EV3PapyrusLibrary/Interfaces/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IDevice.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class ILed: public IDevice {
public:
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer max_brightness() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer brightness() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_brightness(::PrimitiveTypes::Integer /*in*/v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Types::ModeSet triggers() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Types::LocalString trigger() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_trigger(
			::EV3PapyrusLibrary::Types::LocalString /*in*/v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer delay_on() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_delay_on(::PrimitiveTypes::Integer /*in*/v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer delay_off() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_delay_off(::PrimitiveTypes::Integer /*in*/v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual float brightness_pct() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_brightness_pct(float /*in*/v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void on() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void off() = 0;
	/**
	 * 
	 * @return ret 
	 * @param on_ms 
	 * @param off_ms 
	 */
	virtual void flash(unsigned int /*in*/on_ms, unsigned int /*in*/off_ms) = 0;
	/**
	 * 
	 * @return ret 
	 * @param red 
	 * @param green 
	 */
	virtual void mix_colors(float /*in*/red, float /*in*/green) = 0;
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	virtual void set_red(float /*in*/intensity) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void red_on() = 0;
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	virtual void set_green(float /*in*/intensity) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void green_on() = 0;
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	virtual void set_amber(float /*in*/intensity) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void amber_on() = 0;
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	virtual void set_orange(float /*in*/intensity) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void orange_on() = 0;
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	virtual void set_yellow(float /*in*/intensity) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void yellow_on() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void all_off() = 0;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3Brick
} // of namespace Interfaces
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of ILed class header
 ************************************************************/

#endif