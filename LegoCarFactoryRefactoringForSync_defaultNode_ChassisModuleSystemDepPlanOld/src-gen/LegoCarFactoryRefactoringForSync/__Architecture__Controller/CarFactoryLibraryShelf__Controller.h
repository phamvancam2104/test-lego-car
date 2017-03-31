// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CARFACTORYLIBRARYSHELF__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_CARFACTORYLIBRARYSHELF__CONTROLLER_H

/************************************************************
 CarFactoryLibraryShelf__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace CarFactoryLibrary {
class IModule;
}
namespace CarFactoryLibrary {
class Shelf;
}
namespace EV3PapyrusLibrary {
class IColorSensor;
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILcd;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class CarFactoryLibraryShelf__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	CarFactoryLibraryShelf__Controller(
			::CarFactoryLibrary::Shelf* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor1();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor2();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::IColorSensor* get_sensor3();
	/**
	 * 
	 * @param ref 
	 */
	void connect_pLCD(
			::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* /*in*/ref);
	/**
	 * 
	 * @param ref 
	 */
	void connect_pModule(::CarFactoryLibrary::IModule* /*in*/ref);

private:
	/**
	 * 
	 */
	::CarFactoryLibrary::Shelf* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of CarFactoryLibraryShelf__Controller class header
 ************************************************************/

#endif
