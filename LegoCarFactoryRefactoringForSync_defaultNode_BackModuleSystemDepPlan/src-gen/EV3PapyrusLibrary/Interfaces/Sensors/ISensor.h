// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_INTERFACES_SENSORS_ISENSOR_H
#define EV3PAPYRUSLIBRARY_INTERFACES_SENSORS_ISENSOR_H

/************************************************************
              ISensor class header
 ************************************************************/

#include "EV3PapyrusLibrary/Interfaces/Sensors/Pkg_Sensors.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IDevice.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
// End of Include stereotype (header)


namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Sensors {

/************************************************************/
/**
 * 
 */
class ISensor : 
public ::EV3PapyrusLibrary::Interfaces::EV3Brick::IDevice	
 {
	public:
	/**
	 * 
	 * @return ret 
	 * @param index 
	 */
	virtual  ::PrimitiveTypes::Integer value(unsigned int /*in*/ index = 0) = 0;
	/**
	 * 
	 * @return ret 
	 * @param index 
	 */
	virtual  float float_value(unsigned int /*in*/ index = 0) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::LocalString type_name() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::LocalString bin_data_format() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::CustomVectorChar bin_data() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::ModeSet commands() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::PrimitiveTypes::Integer decimals() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::LocalString driver_name() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::LocalString mode() = 0;
	/**
	 * 
	 * @param v 
	 */
	virtual void set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/ v) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::ModeSet modes() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::PrimitiveTypes::Integer num_values() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::LocalString port_name() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::EV3PapyrusLibrary::Types::LocalString units() = 0;


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace Sensors
} // of namespace Interfaces
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of ISensor class header
 ************************************************************/

#endif
