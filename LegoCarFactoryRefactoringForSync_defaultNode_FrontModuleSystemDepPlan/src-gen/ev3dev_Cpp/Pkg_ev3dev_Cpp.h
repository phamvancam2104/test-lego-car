#ifndef PKG_EV3DEV_CPP
#define PKG_EV3DEV_CPP

/************************************************************
 Pkg_ev3dev_Cpp package header
 ************************************************************/

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
#include "LegoCarFactoryRefactoringForSync/Pkg_LegoCarFactoryRefactoringForSync.h"
// End of Include stereotype (header)
namespace ev3dev_Cpp {

// Types defined within the package
/**
 * 
 */
typedef std::set<mode_type> mode_set;

/**
 * 
 */
typedef std::string port_type;

} // of namespace ev3dev_Cpp

/************************************************************
 End of Pkg_ev3dev_Cpp package header
 ************************************************************/

#endif
