// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_EV3BRICK_ABSTRACTSOUND_H
#define EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_EV3BRICK_ABSTRACTSOUND_H

/************************************************************
              AbstractSound class header
 ************************************************************/

#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
namespace EV3PapyrusLibrary {namespace Interfaces {namespace EV3Brick {class ISound;}}}
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ISound.h"

// End of Include stereotype (header)


namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class AbstractSound {
	public:
	/**
	 * 
	 */
	 ProvidedPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ISound> soundDevicePort;
	/**
	 * 
	 * @return ret 
	 */
	 void beep();
	/**
	 * 
	 * @return ret 
	 * @param frequency 
	 * @param ms 
	 */
	 void tone(unsigned int /*in*/ frequency, unsigned int /*in*/ ms);
	/**
	 * 
	 * @return ret 
	 * @param soundfile 
	 * @param bSynchronous 
	 */
	 void play(::EV3PapyrusLibrary::Types::LocalString /*in*/ soundfile, ::PrimitiveTypes::Boolean /*in*/ bSynchronous);
	/**
	 * 
	 * @return ret 
	 * @param text 
	 * @param bSynchronous 
	 */
	 void speak(::EV3PapyrusLibrary::Types::LocalString& /*in*/ text, ::PrimitiveTypes::Boolean /*in*/ bSynchronous);
	/**
	 * 
	 * @return ret 
	 */
	 unsigned int volume();
	/**
	 * 
	 * @return ret 
	 * @param v 
	 */
	 void set_volume(unsigned int /*in*/ v);
	/**
	 * play a file
	 * @return ret 
	 * @param soundfile the file name of the sound file
	 * @param volume the volume to play
	 */
	virtual  void play_file(::EV3PapyrusLibrary::Types::LocalString /*in*/ soundfile, unsigned int /*in*/ volume = 100) = 0;
	/**
	 * 
	 * @return ret 
	 * @param frequency the frequency of the tone
	 * @param ms the duration the tone play (in millisecond)
	 * @param volume the volume to play
	 */
	virtual  void play_tone(unsigned int /*in*/ frequency, unsigned int /*in*/ ms = 1000, unsigned int /*in*/ volume = 100) = 0;


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3Brick
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of AbstractSound class header
 ************************************************************/

#endif
