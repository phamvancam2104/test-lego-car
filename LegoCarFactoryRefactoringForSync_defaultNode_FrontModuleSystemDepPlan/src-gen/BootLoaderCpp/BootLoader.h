// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef BOOTLOADERCPP_BOOTLOADER_H
#define BOOTLOADERCPP_BOOTLOADER_H

/************************************************************
              BootLoader class header
 ************************************************************/

#include "BootLoaderCpp/Pkg_BootLoaderCpp.h"

#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/FrontModuleSystem.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"



namespace BootLoaderCpp {

/************************************************************/
/**
 * 
 */
class BootLoader {
	public:
	/**
	 * 
	 */
	static ::PrimitiveTypes::Integer argc;
	/**
	 * 
	 */
	static ::PrimitiveTypes::String* argv;
	/**
	 * 
	 */
	 ::LegoCarFactoryRefactoringForSync::LegoCarComponents::Modules::Front::FrontModuleSystem mainInstance;
	/**
	 * 
	 */
	void init();


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace BootLoaderCpp

/************************************************************
              End of BootLoader class header
 ************************************************************/

#endif
