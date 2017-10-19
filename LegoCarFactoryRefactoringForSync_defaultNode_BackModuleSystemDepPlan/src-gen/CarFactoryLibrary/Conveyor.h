// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef CARFACTORYLIBRARY_CONVEYOR_H
#define CARFACTORYLIBRARY_CONVEYOR_H

/************************************************************
              Conveyor class header
 ************************************************************/

#include "CarFactoryLibrary/Pkg_CarFactoryLibrary.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/CppLargeMotor.h"
#include "EV3PapyrusLibrary/CppColorSensor.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"

// Include from Include stereotype (header)
namespace EV3PapyrusLibrary {class IColorSensor;}
#include "EV3PapyrusLibrary/IColorSensor.h"
namespace EV3PapyrusLibrary {namespace Interfaces {namespace Actuators {class ILargeMotor;}}}
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"
#include "CarFactoryLibrary/IModule.h"

// End of Include stereotype (header)


namespace CarFactoryLibrary {

/************************************************************/
/**
 * 
 */
class Conveyor {
	public:
	/**
	 * the motor of the conveyor
	 */
	 ::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Actuators::CppLargeMotor motor;
	/**
	 * the color sensor of the conveyor
	 */
	 ::EV3PapyrusLibrary::CppColorSensor color_sensor;
	/**
	 * the command to send to the motor to go from the reference position to the position to wait the piece of the car
	  * reference position: the chassis is abutted below
	 */
	 int wait_offset;
	/**
	 * the command to send to the motor to go from wait position to check presence position
	 */
	 int check_presence_offset;
	/**
	 * the command to send to the motor to go from check presence position to delivered position
	 */
	 int delivered_car_offset;
	/**
	 * the motor of the conveyor
	 */
	 bool is_misplace;
	/**
	 * this is tested if it is the first time we enter on the state machine (if true reset the convyeyor: go to stop sposition else, juste go to the wait position 
	 */
	 bool first_time;
	/**
	 * 
	 */
	 ProvidedPort<EV3PapyrusLibrary::IColorSensor> sensor;
	/**
	 * 
	 */
	 ProvidedPort<EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor> pMotor;
	/**
	 * 
	 */
	 RequiredPort<EV3PapyrusLibrary::Interfaces::EV3Brick::ILcd> pLCD;
	/**
	 * 
	 */
	 RequiredPort<CarFactoryLibrary::IModule> pModule;
	/**
	 * go to the position to wait the piece of the car
	 */
	void go_wait_position();
	/**
	 * delivered the car
	 */
	void delivered_car();
	/**
	 * rewind the conveyor, go back to the wait position
	 */
	void rewind();
	/**
	 * rewind a little to replace the car if it is necessary 
	 */
	void replace_car();
	/**
	 * constructor of the conveyor
	 * @param motorPort the motor port name
	 * @param sensorPort the sensor port name
	 * @param wait_offset the command to send to the motor to go from the reference position to the position to wait the piece of the car
	  *    reference position: the chassis is abutted below
	 * @param check_presence_offset the command to send to the motor to go from wait position to check presence position
	 * @param delivered_car_offset the command to send to the motor to go from check presence position to delivered position
	 */
	Conveyor(::EV3PapyrusLibrary::Types::LocalString /*in*/ motorPort = "outA", ::EV3PapyrusLibrary::Types::LocalString /*in*/ sensorPort = "in1", int /*in*/ wait_offset = 0, int /*in*/ check_presence_offset = 0, int /*in*/ delivered_car_offset = 0);
	/**
	 * go to the position to wait the piece of the car
	 */
	void go_stop_position();
	/**
	 * delivered the car
	 * @return ret true if the added piece is not present and false otherwise 
	 */
	 bool go_check_presence_position();
	/**
	 * 
	 */
	void connectorConfiguration();


	private:
	/**
	 * check the presence of the added piece on the conveyor  
	 * @return ret 
	 */
	virtual  bool check_presence() = 0;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/


/* Inline functions                                         */


} // of namespace CarFactoryLibrary

/************************************************************
              End of Conveyor class header
 ************************************************************/

#endif
