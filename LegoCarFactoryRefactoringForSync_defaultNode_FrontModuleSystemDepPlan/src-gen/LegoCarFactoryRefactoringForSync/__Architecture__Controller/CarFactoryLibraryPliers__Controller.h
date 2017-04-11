// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CARFACTORYLIBRARYPLIERS__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CARFACTORYLIBRARYPLIERS__CONTROLLER_H

/************************************************************
 CarFactoryLibraryPliers__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace CarFactoryLibrary {
class Pliers;
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Actuators {
class IServoMotor;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class CarFactoryLibraryPliers__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	CarFactoryLibraryPliers__Controller(
			::CarFactoryLibrary::Pliers* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* get_plierMotor();
	/**
	 * 
	 * @param origin 
	 */
	CarFactoryLibraryPliers__Controller(
			::CarFactoryLibrary::Pliers* /*in*/origin);

private:
	/**
	 * 
	 */
	::CarFactoryLibrary::Pliers* p_origin;
	/**
	 * 
	 */
	::CarFactoryLibrary::Pliers* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CarFactoryLibraryPliers__Controller class header
 ************************************************************/

#endif
