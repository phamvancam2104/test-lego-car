// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPLED_H
#define EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPLED_H

/************************************************************
 CppLed class header
 ************************************************************/

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLed.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppDevice.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/EV3BrickCppLed__Controller.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILed;
}
}
}

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class CppLed: public ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed,
		public CppDevice,
		public ::EV3PapyrusLibrary::AbstractClasses::EV3Brick::AbstractLed {
public:
	/**
	 * 
	 */
	led referencedLed;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::EV3BrickCppLed__Controller cppledController;
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer max_brightness();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer brightness();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_brightness(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet triggers();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString trigger();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_trigger(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer delay_on();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_delay_on(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer delay_off();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_delay_off(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	float brightness_pct();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_brightness_pct(float /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	void on();
	/**
	 * generated comment
	 * @return ret 
	 */
	void off();
	/**
	 * generated comment
	 * @return ret 
	 * @param on_ms 
	 * @param off_ms 
	 */
	void flash(unsigned int /*in*/on_ms, unsigned int /*in*/off_ms);
	/**
	 * generated comment
	 * @return ret 
	 * @param red 
	 * @param green 
	 */
	void mix_colors(float /*in*/red, float /*in*/green);
	/**
	 * generated comment
	 * @return ret 
	 * @param intensity 
	 */
	void set_red(float /*in*/intensity);
	/**
	 * generated comment
	 * @return ret 
	 */
	void red_on();
	/**
	 * generated comment
	 * @return ret 
	 * @param intensity 
	 */
	void set_green(float /*in*/intensity);
	/**
	 * generated comment
	 * @return ret 
	 */
	void green_on();
	/**
	 * generated comment
	 * @return ret 
	 * @param intensity 
	 */
	void set_amber(float /*in*/intensity);
	/**
	 * generated comment
	 * @return ret 
	 */
	void amber_on();
	/**
	 * generated comment
	 * @return ret 
	 * @param intensity 
	 */
	void set_orange(float /*in*/intensity);
	/**
	 * generated comment
	 * @return ret 
	 */
	void orange_on();
	/**
	 * generated comment
	 * @return ret 
	 * @param intensity 
	 */
	void set_yellow(float /*in*/intensity);
	/**
	 * generated comment
	 * @return ret 
	 */
	void yellow_on();
	/**
	 * generated comment
	 * @return ret 
	 */
	void all_off();
	/**
	 * generated comment
	 * @return ret 
	 * @param dir 
	 * @param pattern 
	 * @param match 
	 */
	::PrimitiveTypes::Boolean connect(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
			::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean connected();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer device_index();
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::PrimitiveTypes::Integer get_attr_int(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::PrimitiveTypes::Integer /*in*/value);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_string(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/value);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_line(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 * @param pCur 
	 */
	::EV3PapyrusLibrary::Types::ModeSet get_attr_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_from_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @param ledPath 
	 */
	CppLed(::EV3PapyrusLibrary::Types::LocalString /*in*/ledPath);

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3Brick
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppLed class header
 ************************************************************/

#endif
