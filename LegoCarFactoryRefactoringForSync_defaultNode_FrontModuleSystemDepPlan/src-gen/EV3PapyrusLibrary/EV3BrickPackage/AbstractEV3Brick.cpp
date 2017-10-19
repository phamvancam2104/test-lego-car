// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_EV3BrickPackage_AbstractEV3Brick_BODY

/************************************************************
              AbstractEV3Brick class body
 ************************************************************/


// include associated header file
#include "EV3PapyrusLibrary/EV3BrickPackage/AbstractEV3Brick.h"

// Derived includes directives
#include "EV3PapyrusLibrary/EV3BrickPackage/IEV3Brick.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IButton.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ISound.h"


namespace EV3PapyrusLibrary {
namespace EV3BrickPackage {

// static attributes (if any)

/**
 * 
 */
void AbstractEV3Brick::allLedOn() {
}

/**
 * 
 */
void AbstractEV3Brick::allLedOff() {
}

/**
 * 
 * @param name 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractEV3Brick::connect(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @param name 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractEV3Brick::accept_connection(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name) {
}

/**
 * 
 * @param name 
 * @param result 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractEV3Brick::read(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString* /*in*/ result) {
}

/**
 * 
 * @param name 
 * @param msg 
 * @return ret 
 */
 ::PrimitiveTypes::Boolean AbstractEV3Brick::write(::EV3PapyrusLibrary::Types::LocalString& /*in*/ name, ::EV3PapyrusLibrary::Types::LocalString& /*in*/ msg) {
}

/**
 * 
 */
void AbstractEV3Brick::connectorConfiguration() {
	bindPorts(this->LeftRedLedPort, leftRedLed.ledPort);
	bindPorts(rightGreenLed.ledPort, this->RightGreenLedPort);
	bindPorts(this->RightRedLedPort, rightRedLed.ledPort);
	bindPorts(this->BackButtonPort, backButton.buttonPort);
	bindPorts(this->OkButtonPort, okButton.buttonPort);
	bindPorts(this->UpButtonPort, topButton.buttonPort);
	bindPorts(rightButton.buttonPort, this->RightButtonPort);
	bindPorts(downButton.buttonPort, this->DownButtonPort);
	bindPorts(leftButton.buttonPort, this->LeftButtonPort);
	bindPorts(this->screenPort, lcdScreen.lcdScreenPort);
	bindPorts(this->soundPort, soundDevice.soundDevicePort);
	bindPorts(this->LeftGreenLedPort, leftGreenLed.ledPort);
}



} // of namespace EV3BrickPackage
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractEV3Brick class body
 ************************************************************/
