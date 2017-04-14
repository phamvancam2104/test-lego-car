// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_BACKBACKMODULESYSTEM__CONTROLLER_H
#define LEGOCARFACTORYREFACTORINGFORSYNC___ARCHITECTURE__CONTROLLER_BACKBACKMODULESYSTEM__CONTROLLER_H

/************************************************************
 BackBackModuleSystem__Controller class header
 ************************************************************/

#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/Pkg___Architecture__Controller.h"

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Back {
class BackModuleSystem;
}
}
}
}

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

/************************************************************/
/**
 * 
 */
class BackBackModuleSystem__Controller {
public:
	/**
	 * 
	 * @param origin 
	 */
	BackBackModuleSystem__Controller(
			::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Back::BackModuleSystem* /*in*/origin);
	/**
	 * 
	 */
	void createConnections();

private:
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Back::BackModuleSystem* p_origin;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of BackBackModuleSystem__Controller class header
 ************************************************************/

#endif