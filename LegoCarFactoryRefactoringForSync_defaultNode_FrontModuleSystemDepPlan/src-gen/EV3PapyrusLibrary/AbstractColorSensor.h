// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_ABSTRACTCOLORSENSOR_H
#define EV3PAPYRUSLIBRARY_ABSTRACTCOLORSENSOR_H

/************************************************************
 AbstractColorSensor class header
 ************************************************************/

#include "EV3PapyrusLibrary/Pkg_EV3PapyrusLibrary.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/Sensors/AbstractSensor.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
namespace EV3PapyrusLibrary {
class IColorSensor;
}
#include "EV3PapyrusLibrary/IColorSensor.h"

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {

/************************************************************/
/**
 * 
 */
class AbstractColorSensor: public ::EV3PapyrusLibrary::AbstractClasses::Sensors::AbstractSensor {
public:
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::IColorSensor> colorSensorPort;
	/**
	 * 
	 * @return ret 
	 * @param index 
	 */
	::PrimitiveTypes::Integer value(unsigned int /*in*/index);
	/**
	 * 
	 * @return ret 
	 * @param index 
	 */
	float float_value(unsigned int /*in*/index);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString type_name();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString bin_data_format();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::CustomVectorChar bin_data();
	/**
	 * 
	 * @param v 
	 */
	void set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet commands();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer decimals();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString driver_name();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString mode();
	/**
	 * 
	 * @param v 
	 */
	void set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet modes();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer num_values();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString port_name();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString units();
	/**
	 * 
	 * @return ret 
	 * @param  
	 */
	::PrimitiveTypes::Boolean connect(
			::EV3PapyrusLibrary::Types::MapStringSetString /*in*/);
	/**
	 * 
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
	::PrimitiveTypes::Integer get_attr_int(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::PrimitiveTypes::Integer /*in*/value);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_string(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/value);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_line(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param pCur 
	 */
	::EV3PapyrusLibrary::Types::ModeSet get_attr_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_from_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer get_color() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer get_reflect_intensity() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Integer get_ambient_intensity() = 0;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3PapyrusLibrary

/************************************************************
 End of AbstractColorSensor class header
 ************************************************************/

#endif
