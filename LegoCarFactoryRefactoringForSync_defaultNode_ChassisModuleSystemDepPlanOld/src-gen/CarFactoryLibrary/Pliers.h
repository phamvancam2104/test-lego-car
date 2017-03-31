// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef CARFACTORYLIBRARY_PLIERS_H
#define CARFACTORYLIBRARY_PLIERS_H

/************************************************************
 Pliers class header
 ************************************************************/

#include "CarFactoryLibrary/Pkg_CarFactoryLibrary.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/CppServoMotor.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/CarFactoryLibraryPliers__Controller.h"

// Include from Include stereotype (header)
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Actuators {
class IServoMotor;
}
}
}

// End of Include stereotype (header)

namespace CarFactoryLibrary {

/************************************************************/
/**
 * pliers of the robotic arm
 */
class Pliers {
public:
	/**
	 * the servo motor of the pliers
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Actuators::CppServoMotor motor;
	/**
	 * the command to send to the pliers to go to the open position
	 */
	int open_position;
	/**
	 * the command to send to the pliers to go to the close position
	 */
	int close_position;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::CarFactoryLibraryPliers__Controller pliersController;
	/**
	 * 
	 */
	ProvidedPort<EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor> plierMotor;
	/**
	 * open the pliers
	 */
	void open();
	/**
	 * close the pliers
	 */
	void close();
	/**
	 * constructor of the Pliers
	 * @param motorPort the servo motor port name
	 * @param open_motor_position the command to send to the pliers to go to the open position
	 * @param close_motor_position the command to send to the pliers to go to the close position
	 */
	Pliers(::EV3PapyrusLibrary::Types::LocalString /*in*/motorPort = "outA",
			int /*in*/open_motor_position = 0, int /*in*/close_motor_position =
					0);
	/**
	 * 
	 */
	void connectorConfiguration();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace CarFactoryLibrary

/************************************************************
 End of Pliers class header
 ************************************************************/

#endif
