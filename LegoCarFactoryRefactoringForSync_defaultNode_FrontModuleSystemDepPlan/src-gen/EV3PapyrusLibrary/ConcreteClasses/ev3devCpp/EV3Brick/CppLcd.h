// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPLCD_H
#define EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_EV3BRICK_CPPLCD_H

/************************************************************
              CppLcd class header
 ************************************************************/

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/Pkg_EV3Brick.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLcd.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Delegatee/EV3Brick/CppLcd__Delegatee.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
namespace EV3PapyrusLibrary {namespace Interfaces {namespace EV3Brick {class ILcd;}}}

// End of Include stereotype (header)


namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

/************************************************************/
/**
 * 
 */
class CppLcd : 
public ::EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd, 
public ::EV3PapyrusLibrary::AbstractClasses::EV3Brick::AbstractLcd	
 {
	public:
	/**
	 * 
	 */
	 lcd referencedLcd;
	DECLARE_DELEGATEE_COMPONENT (CppLcd)
	/**
	 * generated comment
	 * @return ret 
	 */
	 ::PrimitiveTypes::Boolean available();
	/**
	 * generated comment
	 * @return ret 
	 */
	 uint32_t resolution_x();
	/**
	 * generated comment
	 * @return ret 
	 */
	 uint32_t resolution_y();
	/**
	 * generated comment
	 * @return ret 
	 */
	 uint32_t bits_per_pixel();
	/**
	 * generated comment
	 * @return ret 
	 */
	 uint32_t frame_buffer_size();
	/**
	 * generated comment
	 * @return ret 
	 */
	 uint32_t line_length();
	/**
	 * generated comment
	 * @return ret 
	 */
	 unsigned char* frame_buffer();
	/**
	 * generated comment
	 * @return ret 
	 * @param pixel 
	 */
	 void fill(unsigned char /*in*/ pixel);
	/**
	 * 
	 */
	CppLcd();
	/**
	 * 
	 */
	void clear();
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param text 
	 * @param size 
	 */
	void write_text(int /*in*/ x, int /*in*/ y, ::EV3PapyrusLibrary::Types::LocalString /*in*/ text, ::EV3PapyrusLibrary::Types::TextSize /*in*/ size);
	/**
	 * 
	 * @param x0 
	 * @param y0 
	 * @param x1 
	 * @param y1 
	 * @param isBlack 
	 */
	void draw_line(int /*in*/ x0, int /*in*/ y0, int /*in*/ x1, int /*in*/ y1, bool /*in*/ isBlack);
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param width 
	 * @param height 
	 * @param isBlack 
	 */
	void draw_full_rectangle(int /*in*/ x, int /*in*/ y, int /*in*/ width, int /*in*/ height, bool /*in*/ isBlack);
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param width 
	 * @param height 
	 * @param isBlack 
	 */
	void draw_empty_rectangle(int /*in*/ x, int /*in*/ y, int /*in*/ width, int /*in*/ height, bool /*in*/ isBlack);
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radius 
	 * @param isBlack 
	 */
	void draw_full_circle(int /*in*/ x, int /*in*/ y, int /*in*/ radius, bool /*in*/ isBlack);
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radius 
	 * @param isBlack 
	 */
	void draw_empty_circle(int /*in*/ x, int /*in*/ y, int /*in*/ radius, bool /*in*/ isBlack);
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radiusx 
	 * @param radiusy 
	 * @param isBlack 
	 */
	void draw_full_ellipse(int /*in*/ x, int /*in*/ y, int /*in*/ radiusx, int /*in*/ radiusy, bool /*in*/ isBlack);
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radiusx 
	 * @param radiusy 
	 * @param isBlack 
	 */
	void draw_empty_ellipse(int /*in*/ x, int /*in*/ y, int /*in*/ radiusx, int /*in*/ radiusy, bool /*in*/ isBlack);
	/**
	 * 
	 * @param filename 
	 * @param x 
	 * @param y 
	 * @param invertColor 
	 */
	void draw_bmp_image(::EV3PapyrusLibrary::Types::LocalString /*in*/ filename, int /*in*/ x, int /*in*/ y, bool /*in*/ invertColor);
	/**
	 * 
	 * @return ret 
	 */
	 void init();
	/**
	 * 
	 * @return ret 
	 */
	 void deinit();


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace EV3Brick
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
              End of CppLcd class header
 ************************************************************/

#endif
