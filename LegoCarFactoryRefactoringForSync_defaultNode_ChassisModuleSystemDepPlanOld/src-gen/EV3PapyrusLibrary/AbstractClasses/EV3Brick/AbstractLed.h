// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_EV3BRICK_ABSTRACTLED_H
#define EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_EV3BRICK_ABSTRACTLED_H

/************************************************************
              AbstractLed class header
 ************************************************************/

#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractDevice.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
namespace EV3PapyrusLibrary {namespace Interfaces {namespace EV3Brick {class ILed;}}}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"

// End of Include stereotype (header)


namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class AbstractLed : 
public AbstractDevice	
 {
	public:
	/**
	 * 
	 */
	 ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILed> ledPort;
	/**
	 * 
	 * @return ret 
	 */
	 ::PrimitiveTypes::Integer max_brightness();
	/**
	 * 
	 * @return ret 
	 */
	 ::PrimitiveTypes::Integer brightness();
	/**
	 * 
	 * @param v 
	 */
	void set_brightness(::PrimitiveTypes::Integer /*in*/ v);
	/**
	 * 
	 * @return ret 
	 */
	 ::EV3PapyrusLibrary::Types::ModeSet triggers();
	/**
	 * 
	 * @return ret 
	 */
	 ::EV3PapyrusLibrary::Types::LocalString trigger();
	/**
	 * 
	 * @param v 
	 */
	void set_trigger(::EV3PapyrusLibrary::Types::LocalString /*in*/ v);
	/**
	 * 
	 * @return ret 
	 */
	 ::PrimitiveTypes::Integer delay_on();
	/**
	 * 
	 * @param v 
	 */
	void set_delay_on(::PrimitiveTypes::Integer /*in*/ v);
	/**
	 * 
	 * @return ret 
	 */
	 ::PrimitiveTypes::Integer delay_off();
	/**
	 * 
	 * @param v 
	 */
	void set_delay_off(::PrimitiveTypes::Integer /*in*/ v);
	/**
	 * 
	 * @return ret 
	 */
	 float brightness_pct();
	/**
	 * 
	 * @param v 
	 */
	void set_brightness_pct(float /*in*/ v);
	/**
	 * 
	 * @return ret 
	 */
	 void on();
	/**
	 * 
	 * @return ret 
	 */
	 void off();
	/**
	 * 
	 * @return ret 
	 * @param on_ms 
	 * @param off_ms 
	 */
	 void flash(unsigned int /*in*/ on_ms, unsigned int /*in*/ off_ms);
	/**
	 * 
	 * @return ret 
	 * @param red 
	 * @param green 
	 */
	 void mix_colors(float /*in*/ red, float /*in*/ green);
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	 void set_red(float /*in*/ intensity);
	/**
	 * 
	 * @return ret 
	 */
	 void red_on();
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	 void set_green(float /*in*/ intensity);
	/**
	 * 
	 * @return ret 
	 */
	 void green_on();
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	 void set_amber(float /*in*/ intensity);
	/**
	 * 
	 * @return ret 
	 */
	 void amber_on();
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	 void set_orange(float /*in*/ intensity);
	/**
	 * 
	 * @return ret 
	 */
	 void orange_on();
	/**
	 * 
	 * @return ret 
	 * @param intensity 
	 */
	 void set_yellow(float /*in*/ intensity);
	/**
	 * 
	 * @return ret 
	 */
	 void yellow_on();
	/**
	 * 
	 * @return ret 
	 */
	 void all_off();
	/**
	 * 
	 * @return ret 
	 */
	 ::PrimitiveTypes::Boolean connected();
	/**
	 * 
	 * @return ret 
	 */
	 ::PrimitiveTypes::Integer device_index();
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	 ::PrimitiveTypes::Integer get_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	 void set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::PrimitiveTypes::Integer /*in*/ value);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	 ::EV3PapyrusLibrary::Types::LocalString get_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	 void set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ value);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	 ::EV3PapyrusLibrary::Types::LocalString get_attr_line(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param pCur 
	 */
	 ::EV3PapyrusLibrary::Types::ModeSet get_attr_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString* /*in*/ pCur);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	 ::EV3PapyrusLibrary::Types::LocalString get_attr_from_set(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name);
	/**
	 * 
	 * @return ret 
	 * @param dir 
	 * @param pattern 
	 * @param match 
	 */
	 ::PrimitiveTypes::Boolean connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ dir, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ pattern, ::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ match);


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3Brick
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractLed class header
 ************************************************************/

#endif
