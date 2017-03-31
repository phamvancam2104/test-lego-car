#ifndef PKG_CARFACTORYLIBRARY
#define PKG_CARFACTORYLIBRARY

/************************************************************
 Pkg_CarFactoryLibrary package header
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
namespace CarFactoryLibrary {

// Types defined within the package
/**
 * 
 */
enum BluetoothSlaveEnum {
	/**
	 * there is no message receive
	 */
	NO_SLAVE_MSG = -1,
	/**
	 * acknoledge when command is received
	 */
	RESULT_OK,
	/**
	 * status when module is ready to execute commands
	 */
	RESULT_READY,
	/**
	 * status when module is busy
	 */
	RESULT_BUSY,
	/**
	 * status when module is stopped
	 */
	RESULT_STOP,
	/**
	 * status if part was misplaced
	 */
	RESULT_ERROR,
	/**
	 * status if selected color rack is empty
	 */
	RESULT_EMPTY
};
/**
 * 
 */
enum BluetoothMasterEnum {
	/**
	 * there is no message receive
	 */
	NO_MASTER_MSG = -1,
	/**
	 * move conveyor fordward to load car
	 */
	CMD_LOAD_CAR,
	/**
	 * pick and place, check, press
	 */
	CMD_ASSEMBLE,
	/**
	 * deliver car to next module
	 */
	CMD_DELIVER,
	/**
	 * reset the program running
	 */
	CMD_REWIND,
	/**
	 * this requires a special ack from slave
	 */
	CMD_GET_STATUS,
	/**
	 * the reply is in the format "RK=<R><W><B>" each field being "1" if ok or "0" if rack is empty
	 */
	CMD_GET_RACKS,
	/**
	 * required reply
	 */
	CMD_PING,
	/**
	 * cancel order
	 */
	CMD_STOP,
	/**
	 * move conveyor to the very beginning to receive car
	 */
	CMD_RESET
};
/**
 * 
 */
enum ModuleName {
	/**
	 * there is no message receive
	 */
	MASTER_MODULE,
	/**
	 * acknoledge when command is received
	 */
	FRONT_MODULE,
	/**
	 * status when module is ready to execute commands
	 */
	BACK_MODULE,
	/**
	 * status when module is busy
	 */
	ROOF_MODULE
};
/**
 * 
 */
enum Colors {
	/**
	 * 
	 */
	NONE,
	/**
	 * 
	 */
	BLUE,
	/**
	 * 
	 */
	WHITE,
	/**
	 * 
	 */
	RED
};
} // of namespace CarFactoryLibrary

/************************************************************
 End of Pkg_CarFactoryLibrary package header
 ************************************************************/

#endif
