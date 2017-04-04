#ifndef PKG_LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS
#define PKG_LEGOCARFACTORYREFACTORINGFORSYNC_LEGOCARCOMPONENTS

/************************************************************
 Pkg_LegoCarComponents package header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/Pkg_LegoCarFactoryRefactoringForSync.h"

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
#ifdef __linux__ 
//linux code goes here
#elif _WIN32
#include "windows.h"
#else

#endif

#include <string>
#include <sstream>
using namespace std;
// End of Include stereotype (header)
namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {

// Types defined within the package
}// of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of Pkg_LegoCarComponents package header
 ************************************************************/

#endif
