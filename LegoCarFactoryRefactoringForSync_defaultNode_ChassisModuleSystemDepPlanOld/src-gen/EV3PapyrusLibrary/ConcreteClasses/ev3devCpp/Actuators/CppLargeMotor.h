// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_ACTUATORS_CPPLARGEMOTOR_H
#define EV3PAPYRUSLIBRARY_CONCRETECLASSES_EV3DEVCPP_ACTUATORS_CPPLARGEMOTOR_H

/************************************************************
 CppLargeMotor class header
 ************************************************************/

#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/Pkg_Actuators.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractLargeMotor.h"
#include "EV3PapyrusLibrary/Interfaces/Actuators/ILargeMotor.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ActuatorsCppLargeMotor__Controller.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include "ev3dev.h"
using namespace ev3dev;
namespace EV3PapyrusLibrary {
namespace Interfaces {
namespace Actuators {
class ILargeMotor;
}
}
}

// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace ConcreteClasses {
namespace ev3devCpp {
namespace Actuators {

/************************************************************/
/**
 * 
 */
class CppLargeMotor: public ::EV3PapyrusLibrary::Interfaces::Actuators::ILargeMotor,
		public ::EV3PapyrusLibrary::AbstractClasses::Actuators::AbstractLargeMotor {
public:
	/**
	 * 
	 */
	large_motor referencedLarge_motor;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ActuatorsCppLargeMotor__Controller cpplargemotorController;
	/**
	 * generated comment
	 * @param v 
	 */
	void set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet commands();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer count_per_rot();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString driver_name();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer duty_cycle();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer duty_cycle_sp();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_duty_cycle_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString encoder_polarity();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_encoder_polarity(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString polarity();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_polarity(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString port_name();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_position(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_p();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_position_p(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_i();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_position_i(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_d();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_position_d(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_sp();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_position_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_sp();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_speed_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer ramp_up_sp();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_ramp_up_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer ramp_down_sp();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_ramp_down_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString speed_regulation_enabled();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_speed_regulation_enabled(
			::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_regulation_p();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_speed_regulation_p(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_regulation_i();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_speed_regulation_i(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_regulation_d();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_speed_regulation_d(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet state();
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString stop_command();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_stop_command(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet stop_commands();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer time_sp();
	/**
	 * generated comment
	 * @param v 
	 */
	void set_time_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * generated comment
	 * @return ret 
	 */
	void run_forever();
	/**
	 * generated comment
	 * @return ret 
	 */
	void run_to_abs_pos();
	/**
	 * generated comment
	 * @return ret 
	 */
	void run_to_rel_pos();
	/**
	 * generated comment
	 * @return ret 
	 */
	void run_timed();
	/**
	 * generated comment
	 * @return ret 
	 */
	void run_direct();
	/**
	 * generated comment
	 * @return ret 
	 */
	void stop();
	/**
	 * generated comment
	 * @return ret 
	 */
	void reset();
	/**
	 * generated comment
	 * @return ret 
	 * @param dir 
	 * @param pattern 
	 * @param match 
	 */
	::PrimitiveTypes::Boolean connect(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/dir,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/pattern,
			::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/match);
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean connected();
	/**
	 * generated comment
	 * @return ret 
	 */
	::PrimitiveTypes::Integer device_index();
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::PrimitiveTypes::Integer get_attr_int(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::PrimitiveTypes::Integer /*in*/value);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_string(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/value);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_line(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 * @param pCur 
	 */
	::EV3PapyrusLibrary::Types::ModeSet get_attr_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur = nullptr);
	/**
	 * generated comment
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_from_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * run the motor for a duration of "second" second
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param second the number of second the motor run
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	void run_for_second(int /*in*/power, int /*in*/second, bool /*in*/brake,
			bool /*in*/invert_sens = false);
	/**
	 * run the motor for a number of degres
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param degres the number of degres the motor run
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	void run_for_degres(int /*in*/power, int /*in*/degres, bool /*in*/brake,
			bool /*in*/invert_sens = false);
	/**
	 * run the motor for a number of turn
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param nb_turn the number of turn
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	void run_for_turn(int /*in*/power, int /*in*/nb_turn, bool /*in*/brake,
			bool /*in*/invert_sens = false);
	/**
	 * run the motor still there is a stop command
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	void start(int /*in*/power, bool /*in*/invert_sens = false);
	/**
	 * stop the motor
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @return  
	 */
	void stop(bool /*in*/brake);
	/**
	 * 
	 * @param portAdress 
	 */
	CppLargeMotor(::EV3PapyrusLibrary::Types::LocalString /*in*/portAdress =
			"outA");

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Actuators
} // of namespace ev3devCpp
} // of namespace ConcreteClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of CppLargeMotor class header
 ************************************************************/

#endif
