// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MINDSENSORSPAPYRUSLIBRARY_CONCRETECLASSES_CPPSENSORMUX_H
#define MINDSENSORSPAPYRUSLIBRARY_CONCRETECLASSES_CPPSENSORMUX_H

/************************************************************
 CppSensorMux class header
 ************************************************************/

#include "MindsensorsPapyrusLibrary/ConcreteClasses/Pkg_ConcreteClasses.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppDevice.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/ConcreteClasses/CppSensorMux__Delegatee.h"
#include "MindsensorsPapyrusLibrary/AbstractClasses/AbstractSensorMux.h"
#include "MindsensorsPapyrusLibrary/Interfaces/ISensorMux.h"
#include "MindsensorsPapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
namespace MindsensorsPapyrusLibrary {
namespace Interfaces {
class ISensorMux;
}
}

// End of Include stereotype (header)

namespace MindsensorsPapyrusLibrary {
namespace ConcreteClasses {

/************************************************************/
/**
 * 
 */
class CppSensorMux: public ::MindsensorsPapyrusLibrary::Interfaces::ISensorMux,
		public ::MindsensorsPapyrusLibrary::AbstractClasses::AbstractSensorMux,
		public ::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppDevice {
public:
	/**
	 * 
	 */
	sensor_mux referencedSensor_mux;
	DECLARE_DELEGATEE_COMPONENT (CppSensorMux)
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString type_name();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString bin_data_format();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString driver_name();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::CustomVectorChar bin_data();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString mode();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_mode(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet modes();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString port_name();
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
	 * @param portAddress 
	 * @param sensorTypes 
	 */
	CppSensorMux(::EV3PapyrusLibrary::Types::LocalString /*in*/portAddress =
			"in1",
			::MindsensorsPapyrusLibrary::Types::VectorLocalString /*in*/sensorTypes =
					std::vector<EV3PapyrusLibrary::Types::LocalString>());

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace ConcreteClasses
} // of namespace MindsensorsPapyrusLibrary

/************************************************************
 End of CppSensorMux class header
 ************************************************************/

#endif
