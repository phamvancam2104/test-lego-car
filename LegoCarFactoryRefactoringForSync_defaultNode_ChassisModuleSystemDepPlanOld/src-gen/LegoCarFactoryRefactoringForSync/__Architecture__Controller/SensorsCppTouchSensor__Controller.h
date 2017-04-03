// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_SENSORSCPPTOUCHSENSOR__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_SENSORSCPPTOUCHSENSOR__CONTROLLER_H

/************************************************************
 SensorsCppTouchSensor__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

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
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class SensorsCppTouchSensor__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	SensorsCppTouchSensor__Controller(
			::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Sensors::CppTouchSensor* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Sensors::ITouchSensor* get_touchSensorPort();

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Sensors::CppTouchSensor* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SensorsCppTouchSensor__Controller class header
 ************************************************************/

#endif
