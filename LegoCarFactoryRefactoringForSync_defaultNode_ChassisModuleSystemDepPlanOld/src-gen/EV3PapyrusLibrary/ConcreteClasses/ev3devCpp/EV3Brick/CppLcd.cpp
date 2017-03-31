// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define EV3PapyrusLibrary_ConcreteClasses_ev3devCpp_EV3Brick_CppLcd_BODY

/************************************************************
 CppLcd class body
 ************************************************************/

// Include from Include stereotype (pre-body)
#include <iostream>
using namespace std;
// End of Include stereotype (pre-body)

// include associated header file
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLcd.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace EV3Brick {

// static attributes (if any)

/**
 * generated comment
 * @return ret 
 */
::PrimitiveTypes::Boolean CppLcd::available() {
	return referencedLcd.available();
}

/**
 * generated comment
 * @return ret 
 */
uint32_t CppLcd::resolution_x() {
	return referencedLcd.resolution_x();
}

/**
 * generated comment
 * @return ret 
 */
uint32_t CppLcd::resolution_y() {
	return referencedLcd.resolution_y();
}

/**
 * generated comment
 * @return ret 
 */
uint32_t CppLcd::bits_per_pixel() {
	return referencedLcd.bits_per_pixel();
}

/**
 * generated comment
 * @return ret 
 */
uint32_t CppLcd::frame_buffer_size() {
	return referencedLcd.frame_buffer_size();
}

/**
 * generated comment
 * @return ret 
 */
uint32_t CppLcd::line_length() {
	return referencedLcd.line_length();
}

/**
 * generated comment
 * @return ret 
 */
unsigned char* CppLcd::frame_buffer() {
	return referencedLcd.frame_buffer();
}

/**
 * generated comment
 * @return ret 
 * @param pixel 
 */
void CppLcd::fill(unsigned char /*in*/pixel) {
	return referencedLcd.fill(pixel);
}

/**
 * 
 */
CppLcd::CppLcd() :
		cpplcdController(this) {
	if (!referencedLcd.available()) {
		cout << endl << "###error: lcd not available ###" << endl;
	}
}

/**
 * 
 */
void CppLcd::clear() {
	referencedLcd.clear();
}

/**
 * 
 * @param x 
 * @param y 
 * @param text 
 * @param size 
 */
void CppLcd::write_text(int /*in*/x, int /*in*/y,
		::EV3PapyrusLibrary::Types::LocalString /*in*/text,
		::EV3PapyrusLibrary::Types::TextSize /*in*/size) {
	referencedLcd.write_text(x, y, text, size);
}

/**
 * 
 * @param x0 
 * @param y0 
 * @param x1 
 * @param y1 
 * @param isBlack 
 */
void CppLcd::draw_line(int /*in*/x0, int /*in*/y0, int /*in*/x1, int /*in*/y1,
		bool /*in*/isBlack) {
	referencedLcd.draw_line(x0, y0, x1, y1, isBlack);
}

/**
 * 
 * @param x 
 * @param y 
 * @param width 
 * @param height 
 * @param isBlack 
 */
void CppLcd::draw_full_rectangle(int /*in*/x, int /*in*/y, int /*in*/width,
		int /*in*/height, bool /*in*/isBlack) {
	referencedLcd.draw_full_rectangle(x, y, width, height, isBlack);
}

/**
 * 
 * @param x 
 * @param y 
 * @param width 
 * @param height 
 * @param isBlack 
 */
void CppLcd::draw_empty_rectangle(int /*in*/x, int /*in*/y, int /*in*/width,
		int /*in*/height, bool /*in*/isBlack) {
	referencedLcd.draw_empty_rectangle(x, y, width, height, isBlack);
}

/**
 * 
 * @param x 
 * @param y 
 * @param radius 
 * @param isBlack 
 */
void CppLcd::draw_full_circle(int /*in*/x, int /*in*/y, int /*in*/radius,
		bool /*in*/isBlack) {
	referencedLcd.draw_full_circle(x, y, radius, isBlack);
}

/**
 * 
 * @param x 
 * @param y 
 * @param radius 
 * @param isBlack 
 */
void CppLcd::draw_empty_circle(int /*in*/x, int /*in*/y, int /*in*/radius,
		bool /*in*/isBlack) {
	referencedLcd.draw_empty_circle(x, y, radius, isBlack);
}

/**
 * 
 * @param x 
 * @param y 
 * @param radiusx 
 * @param radiusy 
 * @param isBlack 
 */
void CppLcd::draw_full_ellipse(int /*in*/x, int /*in*/y, int /*in*/radiusx,
		int /*in*/radiusy, bool /*in*/isBlack) {
	referencedLcd.draw_full_ellipse(x, y, radiusx, radiusy, isBlack);

}

/**
 * 
 * @param x 
 * @param y 
 * @param radiusx 
 * @param radiusy 
 * @param isBlack 
 */
void CppLcd::draw_empty_ellipse(int /*in*/x, int /*in*/y, int /*in*/radiusx,
		int /*in*/radiusy, bool /*in*/isBlack) {
	referencedLcd.draw_empty_ellipse(x, y, radiusx, radiusy, isBlack);

}

/**
 * 
 * @param filename 
 * @param x 
 * @param y 
 * @param invertColor 
 */
void CppLcd::draw_bmp_image(
		::EV3PapyrusLibrary::Types::LocalString /*in*/filename, int /*in*/x,
		int /*in*/y, bool /*in*/invertColor) {
	referencedLcd.draw_bmp_image(filename, x, y, invertColor);

}

/**
 * 
 * @return ret 
 */
void CppLcd::init() {
}

/**
 * 
 * @return ret 
 */
void CppLcd::deinit() {
}

} // of namespace EV3Brick
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppLcd class body
 ************************************************************/
