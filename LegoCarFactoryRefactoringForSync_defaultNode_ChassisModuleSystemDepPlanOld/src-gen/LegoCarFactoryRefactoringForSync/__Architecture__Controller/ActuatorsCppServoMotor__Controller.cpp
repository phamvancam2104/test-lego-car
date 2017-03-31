// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync___Architecture__Controller_ActuatorsCppServoMotor__Controller_BODY

/************************************************************
 ActuatorsCppServoMotor__Controller class body
 ************************************************************/

// include associated header file
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ActuatorsCppServoMotor__Controller.h"

// Derived includes directives
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/CppServoMotor.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/IServoMotor.h"

namespace LegoCarFactoryRefactoringForSync {
namespace __Architecture__Controller {

// static attributes (if any)

/**
 * 
 * @param origin 
 */
ActuatorsCppServoMotor__Controller::ActuatorsCppServoMotor__Controller(
		::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Actuators::CppServoMotor* /*in*/origin) :
		p_origin(origin) {
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Interfaces::Actuators::IServoMotor* ActuatorsCppServoMotor__Controller::get_servoMotorPort() {
	p_origin->servoMotorPort.providedIntf = p_origin;
	return p_origin->servoMotorPort.providedIntf;
}

} // of namespace __Architecture__Controller
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
 End of ActuatorsCppServoMotor__Controller class body
 ************************************************************/
