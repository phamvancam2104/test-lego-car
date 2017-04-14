// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_EV3BRICK_ABSTRACTBUTTON_H
#define EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_EV3BRICK_ABSTRACTBUTTON_H

/************************************************************
 AbstractButton class header
 ************************************************************/

#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/Pkg_EV3Brick.h"

#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {
class IButton;
}
}
}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/IButton.h"

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class AbstractButton {
public:
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::IButton> buttonPort;
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean pressed();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean process();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean process_all();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3Brick
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of AbstractButton class header
 ************************************************************/

#endif
