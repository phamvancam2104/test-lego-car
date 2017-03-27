// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_EV3BrickPackageAbstractEV3Brick__Controller_BODY

/************************************************************
 EV3BrickPackageAbstractEV3Brick__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/EV3BrickPackageAbstractEV3Brick__Controller.h"

// Derived includes directives
#include "EV3PapyrusLibrary/EV3BrickPackage/AbstractEV3Brick.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IButton.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ISound.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 * @param origin 
 */
EV3BrickPackageAbstractEV3Brick__Controller::EV3BrickPackageAbstractEV3Brick__Controller(
		::EV3PapyrusLibrary::EV3BrickPackage::AbstractEV3Brick* /*in*/origin) :
		p_origin(origin) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* EV3BrickPackageAbstractEV3Brick__Controller::get_LeftGreenLedPort() {
	p_origin->LeftGreenLedPort.providedIntf =
			p_origin->leftGreenLed.cppledController.get_ledPort();
	return p_origin->LeftGreenLedPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* EV3BrickPackageAbstractEV3Brick__Controller::get_LeftRedLedPort() {
	p_origin->LeftRedLedPort.providedIntf =
			p_origin->leftRedLed.cppledController.get_ledPort();
	return p_origin->LeftRedLedPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* EV3BrickPackageAbstractEV3Brick__Controller::get_RightGreenLedPort() {
	p_origin->RightGreenLedPort.providedIntf =
			p_origin->rightGreenLed.cppledController.get_ledPort();
	return p_origin->RightGreenLedPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILed* EV3BrickPackageAbstractEV3Brick__Controller::get_RightRedLedPort() {
	p_origin->RightRedLedPort.providedIntf =
			p_origin->rightRedLed.cppledController.get_ledPort();
	return p_origin->RightRedLedPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* EV3BrickPackageAbstractEV3Brick__Controller::get_BackButtonPort() {
	p_origin->BackButtonPort.providedIntf =
			p_origin->backButton.cppbuttonController.get_buttonPort();
	return p_origin->BackButtonPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* EV3BrickPackageAbstractEV3Brick__Controller::get_OkButtonPort() {
	p_origin->OkButtonPort.providedIntf =
			p_origin->okButton.cppbuttonController.get_buttonPort();
	return p_origin->OkButtonPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* EV3BrickPackageAbstractEV3Brick__Controller::get_DownButtonPort() {
	p_origin->DownButtonPort.providedIntf =
			p_origin->downButton.cppbuttonController.get_buttonPort();
	return p_origin->DownButtonPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* EV3BrickPackageAbstractEV3Brick__Controller::get_UpButtonPort() {
	p_origin->UpButtonPort.providedIntf =
			p_origin->topButton.cppbuttonController.get_buttonPort();
	return p_origin->UpButtonPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* EV3BrickPackageAbstractEV3Brick__Controller::get_LeftButtonPort() {
	p_origin->LeftButtonPort.providedIntf =
			p_origin->leftButton.cppbuttonController.get_buttonPort();
	return p_origin->LeftButtonPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::IButton* EV3BrickPackageAbstractEV3Brick__Controller::get_RightButtonPort() {
	p_origin->RightButtonPort.providedIntf =
			p_origin->rightButton.cppbuttonController.get_buttonPort();
	return p_origin->RightButtonPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd* EV3BrickPackageAbstractEV3Brick__Controller::get_screenPort() {
	p_origin->screenPort.providedIntf =
			p_origin->lcdScreen.cpplcdController.get_lcdScreenPort();
	return p_origin->screenPort.providedIntf;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::EV3Brick::ISound* EV3BrickPackageAbstractEV3Brick__Controller::get_soundPort() {
	p_origin->soundPort.providedIntf =
			p_origin->soundDevice.cppsoundController.get_soundDevicePort();
	return p_origin->soundPort.providedIntf;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of EV3BrickPackageAbstractEV3Brick__Controller class body
 ************************************************************/