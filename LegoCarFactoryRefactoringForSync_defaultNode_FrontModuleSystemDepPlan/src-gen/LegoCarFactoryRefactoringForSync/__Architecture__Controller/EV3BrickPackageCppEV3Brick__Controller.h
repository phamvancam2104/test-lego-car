// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3BRICKPACKAGECPPEV3BRICK__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_EV3BRICKPACKAGECPPEV3BRICK__CONTROLLER_H

/************************************************************
 EV3BrickPackageCppEV3Brick__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace EV3PapyrusLibrary {
namespace EV3BrickPackage {
class CppEV3Brick;
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class IButton;
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILcd;
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILed;
}
}
}
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ISound;
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class EV3BrickPackageCppEV3Brick__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	EV3BrickPackageCppEV3Brick__Controller(
			::EV3PapyrusLibrary::EV3BrickPackage::CppEV3Brick* /*in*/origin);
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* get_LeftGreenLedPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* get_LeftRedLedPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* get_RightGreenLedPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* get_RightRedLedPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_BackButtonPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_OkButtonPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_DownButtonPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_UpButtonPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_LeftButtonPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* get_RightButtonPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* get_screenPort();
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Interfaces::EV3Brick::ISound* get_soundPort();

private:
	/**
	 * 
	 */
	::EV3PapyrusLibrary::EV3BrickPackage::CppEV3Brick* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3BrickPackageCppEV3Brick__Controller class header
 ************************************************************/

#endif