// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_ICOLORSENSOR_H
#define EV3PAPYRUSLIBRARY_ICOLORSENSOR_H

/************************************************************
              IColorSensor class header
 ************************************************************/

#include "EV3PapyrusLibrary/Pkg_EV3PapyrusLibrary.h"

#include "EV3PapyrusLibrary/Interfaces/Sensors/ISensor.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
// End of Include stereotype (header)


namespace EV3PapyrusLibrary {

/************************************************************/
/**
 * 
 */
class IColorSensor : 
public ::EV3PapyrusLibrary::Interfaces::Sensors::ISensor	
 {
	public:
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::PrimitiveTypes::Integer get_color() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::PrimitiveTypes::Integer get_reflect_intensity() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  ::PrimitiveTypes::Integer get_ambient_intensity() = 0;


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3PapyrusLibrary

/************************************************************
              End of IColorSensor class header
 ************************************************************/

#endif
