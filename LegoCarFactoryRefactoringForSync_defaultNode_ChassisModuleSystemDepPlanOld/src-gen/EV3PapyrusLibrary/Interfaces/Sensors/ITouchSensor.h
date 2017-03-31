// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_INTERFACES_SENSORS_ITOUCHSENSOR_H
#define EV3PAPYRUSLIBRARY_INTERFACES_SENSORS_ITOUCHSENSOR_H

/************************************************************
 ITouchSensor class header
 ************************************************************/

#include "EV3PapyrusLibrary/Interfaces/Sensors/Pkg_Sensors.h"

#include "EV3PapyrusLibrary/Interfaces/Sensors/ISensor.h"
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
class ITouchSensor: public ISensor {
public:
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Boolean isTouch() = 0;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Sensors
} // of namespace Interfaces
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of ITouchSensor class header
 ************************************************************/

#endif
