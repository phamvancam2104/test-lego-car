// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_SENSORSABSTRACTTOUCHSENSOR__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_SENSORSABSTRACTTOUCHSENSOR__CONTROLLER_H

/************************************************************
 SensorsAbstractTouchSensor__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace Sensors {
class AbstractTouchSensor;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class SensorsAbstractTouchSensor__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	SensorsAbstractTouchSensor__Controller(
			::EV3PapyrusLibrary::AbstractClasses::Sensors::AbstractTouchSensor* /*in*/origin);

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::AbstractClasses::Sensors::AbstractTouchSensor* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of SensorsAbstractTouchSensor__Controller class header
 ************************************************************/

#endif