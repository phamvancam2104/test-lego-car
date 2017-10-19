// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_SENSORS_CPPTOUCHSENSOR__DELEGATEE_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__DELEGATEE_SENSORS_CPPTOUCHSENSOR__DELEGATEE_H

/************************************************************
 CppTouchSensor__Delegatee class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/Sensors/Pkg_Sensors.h"

// Include from Include stereotype (header)
using namespace LegoCarFactoryRefactoringForSync::__Architecture__Delegatee::Sensors;

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace Sensors {
class CppTouchSensor;
}
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Sensors {
class ITouchSensor;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Delegatee {
namespace Sensors {

/************************************************************/
/**
 * 
 */
class CppTouchSensor__Delegatee {
public:
	/**
	 * 
	 * @param comp 
	 */
	void setComponent(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Sensors::CppTouchSensor* /*in*/comp);
	/**
	 * 
	 */
	CppTouchSensor__Delegatee();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Sensors::ITouchSensor* get_touchSensorPort();

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Sensors::CppTouchSensor* component;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Sensors
} // of namespace __Architecture__Delegatee
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CppTouchSensor__Delegatee class header
 ************************************************************/

#endif