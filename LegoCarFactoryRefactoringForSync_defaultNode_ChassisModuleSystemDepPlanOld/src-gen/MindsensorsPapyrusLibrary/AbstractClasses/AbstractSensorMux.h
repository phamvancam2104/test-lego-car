// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MINDSENSORSPAPYRUSLIBRARY_ABSTRACTCLASSES_ABSTRACTSENSORMUX_H
#define MINDSENSORSPAPYRUSLIBRARY_ABSTRACTCLASSES_ABSTRACTSENSORMUX_H

/************************************************************
              AbstractSensorMux class header
 ************************************************************/

#include "MindsensorsPapyrusLibrary/AbstractClasses/Pkg_AbstractClasses.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractDevice.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
namespace MindsensorsPapyrusLibrary {namespace Interfaces {class ISensorMux;}}
#include "MindsensorsPapyrusLibrary/Interfaces/ISensorMux.h"

// End of Include stereotype (header)


namespace MindsensorsPapyrusLibrary {
namespace AbstractClasses {

/************************************************************/
/**
 * 
 */
class AbstractSensorMux : 
public ::EV3PapyrusLibrary::AbstractClasses::EV3Brick::AbstractDevice	
 {
	public:
	/**
	 * 
	 */
	 ProvidedPort<MindsensorsPapyrusLibrary::Interfaces::ISensorMux> sensorMuxPort_host;
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
	void set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/ v);
	/**
	 * 
	 * @return ret 
	 */
	 ::EV3PapyrusLibrary::Types::ModeSet modes();
	/**
	 * 
	 * @return ret 
	 */
	 ::EV3PapyrusLibrary::Types::LocalString port_name();
	/**
	 * 
	 * @return ret 
	 * @param dir 
	 * @param pattern 
	 * @param match 
	 */
	 ::PrimitiveTypes::Boolean connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ dir, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ pattern, ::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/ match);
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


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace AbstractClasses
} // of namespace MindsensorsPapyrusLibrary

/************************************************************
              End of AbstractSensorMux class header
 ************************************************************/

#endif
