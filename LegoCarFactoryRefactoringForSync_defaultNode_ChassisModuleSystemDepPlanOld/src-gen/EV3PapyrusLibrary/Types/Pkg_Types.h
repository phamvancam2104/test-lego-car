#ifndef PKG_EV3PAPYRUSLIBRARY_TYPES
#define PKG_EV3PAPYRUSLIBRARY_TYPES

/************************************************************
 Pkg_Types package header
 ************************************************************/

#include "EV3PapyrusLibrary/Pkg_EV3PapyrusLibrary.h"

#ifndef _IN_
#define _IN_
#endif
#ifndef _OUT_
#define _OUT_
#endif
#ifndef _INOUT_
#define _INOUT_
#endif

/* Package dependency header include                        */

// Include from Include stereotype (header)
#include "ev3dev.h"
#include <stdio.h>
// End of Include stereotype (header)
namespace EV3PapyrusLibrary {
namespace Types {

// Types defined within the package
/**
 * 
 */
typedef std::string LocalString;

/**
 * 
 */
typedef std::map<std::string, std::set<std::string>> MapStringSetString;

/**
 * 
 */
typedef ev3dev::mode_set ModeSet;

/**
 * 
 */
typedef std::vector<char> CustomVectorChar;

/**
 * 
 */
typedef ev3dev::lcd::TextSize TextSize;

/**
 * 
 */
typedef ev3dev::port_type PortType;

} // of namespace Types
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of Pkg_Types package header
 ************************************************************/

#endif
