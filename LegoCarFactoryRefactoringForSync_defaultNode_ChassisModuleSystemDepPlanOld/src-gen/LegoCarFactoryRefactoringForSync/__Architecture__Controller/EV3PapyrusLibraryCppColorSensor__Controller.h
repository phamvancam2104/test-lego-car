// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3PAPYRUSLIBRARYCPPCOLORSENSOR__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3PAPYRUSLIBRARYCPPCOLORSENSOR__CONTROLLER_H

/************************************************************
 EV3PapyrusLibraryCppColorSensor__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace EV3PapyrusLibrary {
class CppColorSensor;
}
namespace EV3PapyrusLibrary {
class IColorSensor;
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class EV3PapyrusLibraryCppColorSensor__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	EV3PapyrusLibraryCppColorSensor__Controller(
			::EV3PapyrusLibrary::CppColorSensor* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_colorSensorPort();

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::CppColorSensor* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3PapyrusLibraryCppColorSensor__Controller class header
 ************************************************************/

#endif
