// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef CARFACTORYLIBRARY_IMODULE_H
#define CARFACTORYLIBRARY_IMODULE_H

/************************************************************
 IModule class header
 ************************************************************/

#include "CarFactoryLibrary/Pkg_CarFactoryLibrary.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"

namespace CarFactoryLibrary {

/************************************************************/
/**
 * 
 */
class IModule {
public:
	/**
	 * 
	 * @return ret 
	 */
	virtual BluetoothSlaveEnum getStatus() = 0;
	/**
	 * 
	 * @param status 
	 */
	virtual void setStatus(BluetoothSlaveEnum /*in*/status) = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual int getCurrentModule() = 0;
	/**
	 * 
	 * @return ret 
	 */
	virtual ::EV3PapyrusLibrary::Types::LocalString& getBluetoothName() = 0;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace CarFactoryLibrary

/************************************************************
 End of IModule class header
 ************************************************************/

#endif
