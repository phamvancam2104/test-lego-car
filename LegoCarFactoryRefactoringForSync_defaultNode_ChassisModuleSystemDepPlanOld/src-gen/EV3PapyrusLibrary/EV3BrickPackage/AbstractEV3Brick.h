// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_EV3BRICKPACKAGE_ABSTRACTEV3BRICK_H
#define EV3PAPYRUSLIBRARY_EV3BRICKPACKAGE_ABSTRACTEV3BRICK_H

/************************************************************
 AbstractEV3Brick class header
 ************************************************************/

#include "EV3PapyrusLibrary/EV3BrickPackage/Pkg_EV3BrickPackage.h"

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppButton.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLcd.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLed.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppSound.h"
#include "EV3PapyrusLibrary/EV3BrickPackage/IEV3Brick.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#ifndef NO_LINUX_HEADERS
#include <linux/fb.h>
#include <linux/input.h>
#else
#define KEY_CNT 8
#endif
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILed;
}
}
}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILed.h"
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class IButton;
}
}
}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IButton.h"
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ILcd;
}
}
}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class ISound;
}
}
}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ISound.h"

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace EV3BrickPackage {

/************************************************************/
/**
 * 
 */
class AbstractEV3Brick: public IEV3Brick {
public:
	AbstractEV3Brick() :
			leftGreenLed("ev3-left1:green:ev3dev"), rightGreenLed(
					"ev3-right1:green:ev3dev"), leftRedLed(
					"ev3-left0:red:ev3dev"), rightRedLed(
					"ev3-right0:red:ev3dev"), backButton(KEY_BACKSPACE), leftButton(
					KEY_LEFT), rightButton(KEY_RIGHT), topButton(KEY_UP), downButton(
					KEY_DOWN), okButton(KEY_ENTER), bluetoothDevice("useless") {
	}
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed leftGreenLed;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed rightGreenLed;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed leftRedLed;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLed rightRedLed;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton backButton;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton leftButton;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton rightButton;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton topButton;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton downButton;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppButton okButton;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppLcd lcdScreen;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppSound soundDevice;
	/**
	 * 
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::EV3Brick::CppBlutooth bluetoothDevice;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILed> LeftGreenLedPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILed> LeftRedLedPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILed> RightGreenLedPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILed> RightRedLedPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> BackButtonPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> OkButtonPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> DownButtonPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> UpButtonPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> LeftButtonPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> RightButtonPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd> screenPort;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ISound> soundPort;
	/**
	 * 
	 */
	void allLedOn();
	/**
	 * 
	 */
	void allLedOff();
	/**
	 * 
	 * @param name 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean connect(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @param name 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean accept_connection(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @param name 
	 * @param result 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean read(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString* /*in*/result);
	/**
	 * 
	 * @param name 
	 * @param msg 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean write(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/msg);
	/**
	 * 
	 */
	void connectorConfiguration();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3BrickPackage
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of AbstractEV3Brick class header
 ************************************************************/

#endif
