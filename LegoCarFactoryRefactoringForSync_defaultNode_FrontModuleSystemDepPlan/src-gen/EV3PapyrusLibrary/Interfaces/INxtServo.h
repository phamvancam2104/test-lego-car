// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_INTERFACES_INXTSERVO_H
#define EV3PAPYRUSLIBRARY_INTERFACES_INXTSERVO_H

/************************************************************
 INxtServo class header
 ************************************************************/

#include "EV3PapyrusLibrary/Interfaces/Pkg_Interfaces.h"

#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IDevice.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

namespace EV3PapyrusLibrary {
namespace Interfaces {

/************************************************************/
/**
 * 
 */
class INxtServo: public ::EV3PapyrusLibrary::Interfaces::EV3Brick::IDevice {
public:
	/**
	 * 
	 * @return ret 
	 * @param power 
	 */
	virtual ::PrimitiveTypes::Boolean powered(
			::PrimitiveTypes::Integer /*in*/power = 80) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Boolean stop_power() = 0;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Interfaces
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of INxtServo class header
 ************************************************************/

#endif
