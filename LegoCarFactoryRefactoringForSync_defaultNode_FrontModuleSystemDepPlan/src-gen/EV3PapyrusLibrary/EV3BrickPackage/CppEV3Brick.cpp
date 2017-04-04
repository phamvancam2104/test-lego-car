// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_EV3BrickPackage_CppEV3Brick_BODY

/************************************************************
 CppEV3Brick class body
 ************************************************************/

// include associated header file
#include "EV3PapyrusLibrary/EV3BrickPackage/CppEV3Brick.h"

// Derived includes directives

namespace EV3PapyrusLibrary {
namespace EV3BrickPackage {

// static attributes (if any)

/**
 * 
 */
void CppEV3Brick::allLedOn() {
	leftGreenLed.on();
	rightGreenLed.on();
	leftRedLed.on();
	rightRedLed.on();
}

/**
 * 
 */
void CppEV3Brick::allLedOff() {
	leftGreenLed.off();
	rightGreenLed.off();
	leftRedLed.off();
	rightRedLed.off();
}

/**
 * 
 */
CppEV3Brick::CppEV3Brick() :
		cppev3brickController(this) {
	//we init the led
	//leftGreenLed.referencedLed=&led::green_left;
	//rightGreenLed.referencedLed=&led::green_right;
	//leftRedLed.referencedLed=&led::red_left;
	//rightRedLed.referencedLed=&led::red_right;
}

} // of namespace EV3BrickPackage
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppEV3Brick class body
 ************************************************************/
