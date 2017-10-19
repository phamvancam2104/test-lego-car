// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define CarFactoryLibrary_Press_BODY

/************************************************************
              Press class body
 ************************************************************/

// Include from Include stereotype (pre-body)
#include "unistd.h"
// End of Include stereotype (pre-body)

// include associated header file
#include "CarFactoryLibrary/Press.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/PressAssemble.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"


namespace CarFactoryLibrary {

// static attributes (if any)

/**
 * assemble the last part put on the car
 */
void Press::assemble() {
	motor.set_duty_cycle_sp(50);
			motor.set_stop_command("brake");
			motor.run_forever();
	
			//Wait press is in stop position
			while (motor.speed() == 0) {
			}
			while (motor.speed() != 0) {
			}
			motor.set_duty_cycle_sp(100);
			usleep(300 * 1000);
			motor.stop();
}

/**
 * assemble the last part put on the car
 */
void Press::go_top() {
	motor.set_duty_cycle_sp(-50);
		motor.set_stop_command("coast");
		motor.run_forever();
	
		while (motor.speed() == 0) {
		}
		while (motor.speed() != 0) {
		}
		motor.stop();
}

/**
 * assemble the last part put on the car
 */
void Press::lift_up() {
	motor.set_duty_cycle_sp(-40);
	motor.run_forever();
	usleep(400 * 1000);
	motor.stop();
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 * @return ret true if the chassis is present and false otherwise
 */
 BluetoothSlaveEnum Press::get_status() {
	return pModule.requiredIntf->getStatus();
}

/**
 * check the presence of the chassis on the conveyor (check the sequence : white - unknown color - white)
 * @param status true if the chassis is present and false otherwise
 */
void Press::set_status(BluetoothSlaveEnum /*in*/ status) {
	pModule.requiredIntf->setStatus(status);
}

/**
 * the press constructor
 * @param motorPort the motor port name
 */
Press::Press(::EV3PapyrusLibrary::Types::LocalString /*in*/ motorPort): motor(motorPort) {
}

/**
 * 
 * @param sig 
 * @return ret 
 */
 void Press::sendPressAssemble(::CarFactoryLibrary::events::PressAssemble& /*in*/ sig) {
}

/**
 * 
 * @param sig 
 * @return ret 
 */
 void Press::sendEndOfModule(::CarFactoryLibrary::events::EndOfModule& /*in*/ sig) {
}

/**
 * 
 */
void Press::connectorConfiguration() {
	bindPorts(this->motor_port, motor.largeMotorPort);
}



} // of namespace CarFactoryLibrary

/************************************************************
              End of Press class body
 ************************************************************/
