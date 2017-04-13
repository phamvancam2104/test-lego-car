// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define CarFactoryLibrary_Pliers_BODY

/************************************************************
 Pliers class body
 ************************************************************/

// Include from Include stereotype (pre-body)
#include "unistd.h"
// End of Include stereotype (pre-body)

// include associated header file
#include "CarFactoryLibrary/Pliers.h"

// Derived includes directives
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"

namespace CarFactoryLibrary {

// static attributes (if any)

/**
 * close the pliers
 */
void Pliers::close() {
	motor.set_position_sp(close_position);
	usleep(200 * 1000);
}

/**
 * open the pliers
 */
void Pliers::open() {
	motor.set_position_sp(open_position);
	usleep(200 * 1000);
}

/**
 * constructor of the Pliers
 * @param motorPort the servo motor port name
 * @param open_motor_position the command to send to the pliers to go to the open position
 * @param close_motor_position the command to send to the pliers to go to the close position
 */
Pliers::Pliers(::EV3PapyrusLibrary::Types::LocalString /*in*/motorPort,
		int /*in*/open_motor_position, int /*in*/close_motor_position) :
		motor(motorPort), open_position(open_motor_position), close_position(
				close_motor_position), pliersController(this) {
}

/**
 * 
 */
void Pliers::connectorConfiguration() {
	bindPorts(plierMotor, motor.servoMotorPort);
}

} // of namespace CarFactoryLibrary

/************************************************************
 End of Pliers class body
 ************************************************************/
