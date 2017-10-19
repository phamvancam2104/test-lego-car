// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef CARFACTORYLIBRARY_COMMUNICATIONINTERFACES_IROBOTICARMFLOATMOTOR_H
#define CARFACTORYLIBRARY_COMMUNICATIONINTERFACES_IROBOTICARMFLOATMOTOR_H

/************************************************************
              IRoboticArmFloatMotor class header
 ************************************************************/

#include "CarFactoryLibrary/CommunicationInterfaces/Pkg_CommunicationInterfaces.h"




namespace CarFactoryLibrary {
namespace CommunicationInterfaces {

/************************************************************/
/**
 * 
 */
class IRoboticArmFloatMotor {
	public:
	/**
	 * stop motors
	 */
	virtual void float_motors() = 0;


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace CommunicationInterfaces
} // of namespace CarFactoryLibrary

/************************************************************
              End of IRoboticArmFloatMotor class header
 ************************************************************/

#endif
