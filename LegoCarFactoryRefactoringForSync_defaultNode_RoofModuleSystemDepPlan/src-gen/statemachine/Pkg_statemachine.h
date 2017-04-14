#ifndef PKG_STATEMACHINE
#define PKG_STATEMACHINE

/************************************************************
 Pkg_statemachine package header
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
// common definitions for statemachine
#include "time.h"
#include "pthread.h"
#define CHECKPOINT if (controller.systemState == statemachine::EVENT_PROCESSING || controller.systemState == statemachine::STOPPED) {return;}
#include "LegoCarFactoryRefactoringForSync/Pkg_LegoCarFactoryRefactoringForSync.h"
// End of Include stereotype (header)
namespace statemachine {

// Types defined within the package
/**
 * 
 */
enum ThreadFunctions {
	/**
	 * 
	 */
	TF_CHANGE_EVENT,
	/**
	 * 
	 */
	TF_TIME_EVENT,
	/**
	 * 
	 */
	TF_DO_ACTIVITY,
	/**
	 * 
	 */
	TF_ENTER_REGION,
	/**
	 * 
	 */
	TF_EXIT_REGION,
	/**
	 * 
	 */
	TF_TRANSITION,
	/**
	 * 
	 */
	TF_STATE_MACHINE_TYPE
};
/**
 * 
 */
enum SystemStateEnum_t {
	/**
	 * 
	 */
	IDLE,
	/**
	 * 
	 */
	EVENT_PROCESSING,
	/**
	 * 
	 */
	EVENT_DEFERRED,
	/**
	 * 
	 */
	EVENT_CONSUMED,
	/**
	 * 
	 */
	STOPPED
};
/**
 * 
 */
enum EventPriority_t {
	/**
	 * 
	 */
	PRIORITY_1,
	/**
	 * 
	 */
	PRIORITY_2,
	/**
	 * 
	 */
	PRIORITY_3,
	/**
	 * 
	 */
	PRIORITY_4,
	/**
	 * 
	 */
	PRIORITY_5
};
/**
 * 
 */
enum EventType_t {
	/**
	 * 
	 */
	SIGNAL_EVENT,
	/**
	 * 
	 */
	CALL_EVENT,
	/**
	 * 
	 */
	TIME_EVENT,
	/**
	 * 
	 */
	CHANGE_EVENT,
	/**
	 * 
	 */
	COMPLETION_EVENT
};
} // of namespace statemachine

/************************************************************
 End of Pkg_statemachine package header
 ************************************************************/

#endif
