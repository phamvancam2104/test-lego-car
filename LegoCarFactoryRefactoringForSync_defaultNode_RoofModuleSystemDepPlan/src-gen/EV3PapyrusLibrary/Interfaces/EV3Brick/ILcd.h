// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_INTERFACES_EV3BRICK_ILCD_H
#define EV3PAPYRUSLIBRARY_INTERFACES_EV3BRICK_ILCD_H

/************************************************************
 ILcd class header
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
class ILcd {
public:
	/**
	 * 
	 * @return ret 
	 */
	virtual ::PrimitiveTypes::Boolean available() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual uint32_t resolution_x() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual uint32_t resolution_y() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual uint32_t bits_per_pixel() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual uint32_t frame_buffer_size() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual uint32_t line_length() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual unsigned char* frame_buffer() = 0;
	/**
	 * 
	 * @return ret 
	 * @param pixel 
	 */
	virtual void fill(unsigned char /*in*/pixel) = 0;
	/**
	 * 
	 */
	virtual void clear() = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param text 
	 * @param size 
	 */
	virtual void write_text(int /*in*/x, int /*in*/y,
			::EV3PapyrusLibrary::Types::LocalString /*in*/text,
			::EV3PapyrusLibrary::Types::TextSize /*in*/size) = 0;
	/**
	 * 
	 * @param x0 
	 * @param y0 
	 * @param x1 
	 * @param y1 
	 * @param isBlack 
	 */
	virtual void draw_line(int /*in*/x0, int /*in*/y0, int /*in*/x1,
			int /*in*/y1, bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param width 
	 * @param height 
	 * @param isBlack 
	 */
	virtual void draw_full_rectangle(int /*in*/x, int /*in*/y, int /*in*/width,
			int /*in*/height, bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param width 
	 * @param height 
	 * @param isBlack 
	 */
	virtual void draw_empty_rectangle(int /*in*/x, int /*in*/y, int /*in*/width,
			int /*in*/height, bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radius 
	 * @param isBlack 
	 */
	virtual void draw_full_circle(int /*in*/x, int /*in*/y, int /*in*/radius,
			bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radius 
	 * @param isBlack 
	 */
	virtual void draw_empty_circle(int /*in*/x, int /*in*/y, int /*in*/radius,
			bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radiusx 
	 * @param radiusy 
	 * @param isBlack 
	 */
	virtual void draw_full_ellipse(int /*in*/x, int /*in*/y, int /*in*/radiusx,
			int /*in*/radiusy, bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param x 
	 * @param y 
	 * @param radiusx 
	 * @param radiusy 
	 * @param isBlack 
	 */
	virtual void draw_empty_ellipse(int /*in*/x, int /*in*/y, int /*in*/radiusx,
			int /*in*/radiusy, bool /*in*/isBlack) = 0;
	/**
	 * 
	 * @param filename 
	 * @param x 
	 * @param y 
	 * @param invertColor 
	 */
	virtual void draw_bmp_image(
			::EV3PapyrusLibrary::Types::LocalString /*in*/filename, int /*in*/x,
			int /*in*/y, bool /*in*/invertColor) = 0;

protected:
	/**
	 * 
	 * @return ret 
	 */
	virtual void init() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual void deinit() = 0;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace EV3Brick
} // of namespace Interfaces
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of ILcd class header
 ************************************************************/

#endif
