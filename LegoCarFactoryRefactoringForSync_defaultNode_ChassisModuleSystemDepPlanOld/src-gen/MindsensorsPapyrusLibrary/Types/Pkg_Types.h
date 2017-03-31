#ifndef PKG_MINDSENSORSPAPYRUSLIBRARY_TYPES
#define PKG_MINDSENSORSPAPYRUSLIBRARY_TYPES

/************************************************************
 Pkg_Types package header
 ************************************************************/

#include "MindsensorsPapyrusLibrary/Pkg_MindsensorsPapyrusLibrary.h"

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
namespace MindsensorsPapyrusLibrary {
namespace Types {

// Types defined within the package
/**
 * 
 */
typedef std::vector<EV3PapyrusLibrary::Types::LocalString> VectorLocalString;

} // of namespace Types
} // of namespace MindsensorsPapyrusLibrary

/************************************************************
 End of Pkg_Types package header
 ************************************************************/

#endif
