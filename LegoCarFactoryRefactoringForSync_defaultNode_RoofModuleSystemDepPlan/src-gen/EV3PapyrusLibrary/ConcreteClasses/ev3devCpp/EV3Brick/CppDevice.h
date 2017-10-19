// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPDEVICE_H
#define EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPDEVICE_H

/************************************************************
 CppDevice class header
 ************************************************************/

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractDevice.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class CppDevice: public ::EV3PapyrusLibrary::AbstractClasses::EV3Brick::AbstractDevice {
public:
	/**
	 * 
	 */
	device referencedDevice;
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
			::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur = nullptr);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_from_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 */
	CppDevice();

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
 End of CppDevice class header
 ************************************************************/

#endif
