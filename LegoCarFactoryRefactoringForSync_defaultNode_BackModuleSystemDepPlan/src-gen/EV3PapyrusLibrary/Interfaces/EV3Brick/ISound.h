// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_INTERFACES_EV3BRICK_ISOUND_H
#define EV3PAPYRUSLIBRARY_INTERFACES_EV3BRICK_ISOUND_H

/************************************************************
              ISound class header
 ************************************************************/

#include "EV3PapyrusLibrary/Interfaces/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
// End of Include stereotype (header)


namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class ISound {
	public:
	/**
	 * 
	 * @return ret 
	 */
	virtual  void beep() = 0;
	/**
	 * 
	 * @return ret 
	 * @param frequency 
	 * @param ms 
	 */
	virtual  void tone(unsigned int /*in*/ frequency, unsigned int /*in*/ ms) = 0;
	/**
	 * 
	 * @return ret 
	 * @param soundfile 
	 * @param bSynchronous 
	 */
	virtual  void play(::EV3PapyrusLibrary::Types::LocalString /*in*/ soundfile, ::PrimitiveTypes::Boolean /*in*/ bSynchronous = false) = 0;
	/**
	 * 
	 * @return ret 
	 * @param text 
	 * @param bSynchronous 
	 */
	virtual  void speak(::EV3PapyrusLibrary::Types::LocalString& /*in*/ text, ::PrimitiveTypes::Boolean /*in*/ bSynchronous = false) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual  unsigned int volume() = 0;
	/**
	 * 
	 * @return ret 
	 * @param v 
	 */
	virtual  void set_volume(unsigned int /*in*/ v) = 0;


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3Brick
} // of namespace Interfaces
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of ISound class header
 ************************************************************/

#endif
