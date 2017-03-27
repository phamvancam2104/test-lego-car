// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_SENSORS_CPPTOUCHSENSOR_H
#define EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_SENSORS_CPPTOUCHSENSOR_H

/************************************************************
 CppTouchSensor class header
 ************************************************************/

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/Pkg_Sensors.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/Sensors/AbstractTouchSensor.h"
#include "EV3PapyrusLibrary/Interfaces/Sensors/ITouchSensor.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/SensorsCppTouchSensor__Controller.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace Sensors {

/************************************************************/
/**
 * 
 */
class CppTouchSensor: public ::EV3PapyrusLibrary::Interfaces::Sensors::ITouchSensor,
		public ::EV3PapyrusLibrary::AbstractClasses::Sensors::AbstractTouchSensor {
public:
	/**
	 * 
	 */
	touch_sensor referencedTouch_sensor;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::SensorsCppTouchSensor__Controller cpptouchsensorController;
	/**
	 * generated comment
	 * @return ret 
	 * @param index 
	 */
	::PrimitiveTypes::Integer value(unsigned int /*in*/index = 0);
	/**
	 * generated comment
	 * @return ret 
	 * @param index 
	 */
	float float_value(unsigned int /*in*/index = 0);
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
	::EV3PapyrusLibrary::Types::CustomVectorChar bin_data();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet commands();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer decimals();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString driver_name();
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
	::PrimitiveTypes::Integer num_values();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString port_name();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString units();
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
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean isTouch();
	/**
	 * 
	 * @param portAdress 
	 */
	CppTouchSensor(
			::EV3PapyrusLibrary::Types::PortType /*in*/portAdress = "in1");

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Sensors
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppTouchSensor class header
 ************************************************************/

#endif