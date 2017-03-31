// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_ACTUATORS_ABSTRACTLARGEMOTOR_H
#define EV3PAPYRUSLIBRARY_ABSTRACTCLASSES_ACTUATORS_ABSTRACTLARGEMOTOR_H

/************************************************************
 AbstractLargeMotor class header
 ************************************************************/

#include "EV3PapyrusLibrary/AbstractClasses/Actuators/Pkg_Actuators.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractMotor.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/ActuatorsAbstractLargeMotor__Controller.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

// Include from Include stereotype (header)
#include <stdint.h>
// End of Include stereotype (header)

namespace EV3PapyrusLibrary {
namespace AbstractClasses {
namespace Actuators {

/************************************************************/
/**
 * 
 */
class AbstractLargeMotor: public AbstractMotor {
public:
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::ActuatorsAbstractLargeMotor__Controller abstractlargemotorController;
	/**
	 * 
	 * @param v 
	 */
	void set_command(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet commands();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer count_per_rot();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString driver_name();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer duty_cycle();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer duty_cycle_sp();
	/**
	 * 
	 * @param v 
	 */
	void set_duty_cycle_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString encoder_polarity();
	/**
	 * 
	 * @param v 
	 */
	void set_encoder_polarity(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString polarity();
	/**
	 * 
	 * @param v 
	 */
	void set_polarity(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString port_name();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position();
	/**
	 * 
	 * @param v 
	 */
	void set_position(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_p();
	/**
	 * 
	 * @param v 
	 */
	void set_position_p(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_i();
	/**
	 * 
	 * @param v 
	 */
	void set_position_i(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_d();
	/**
	 * 
	 * @param v 
	 */
	void set_position_d(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer position_sp();
	/**
	 * 
	 * @param v 
	 */
	void set_position_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_sp();
	/**
	 * 
	 * @param v 
	 */
	void set_speed_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer ramp_up_sp();
	/**
	 * 
	 * @param v 
	 */
	void set_ramp_up_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer ramp_down_sp();
	/**
	 * 
	 * @param v 
	 */
	void set_ramp_down_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString speed_regulation_enabled();
	/**
	 * 
	 * @param v 
	 */
	void set_speed_regulation_enabled(
			::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_regulation_p();
	/**
	 * 
	 * @param v 
	 */
	void set_speed_regulation_p(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_regulation_i();
	/**
	 * 
	 * @param v 
	 */
	void set_speed_regulation_i(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer speed_regulation_d();
	/**
	 * 
	 * @param v 
	 */
	void set_speed_regulation_d(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet state();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString stop_command();
	/**
	 * 
	 * @param v 
	 */
	void set_stop_command(::EV3PapyrusLibrary::Types::LocalString /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::ModeSet stop_commands();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer time_sp();
	/**
	 * 
	 * @param v 
	 */
	void set_time_sp(::PrimitiveTypes::Integer /*in*/v);
	/**
	 * 
	 * @return ret 
	 */
	void run_forever();
	/**
	 * 
	 * @return ret 
	 */
	void run_to_abs_pos();
	/**
	 * 
	 * @return ret 
	 */
	void run_to_rel_pos();
	/**
	 * 
	 * @return ret 
	 */
	void run_timed();
	/**
	 * 
	 * @return ret 
	 */
	void run_direct();
	/**
	 * 
	 * @return ret 
	 */
	void stop();
	/**
	 * 
	 * @return ret 
	 */
	void reset();
	/**
	 * 
	 * @return ret 
	 * @param arg0 
	 */
	::PrimitiveTypes::Boolean connect(
			::EV3PapyrusLibrary::Types::MapStringSetString& /*in*/arg0);
	/**
	 * 
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
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Boolean connected();
	/**
	 * 
	 * @return ret 
	 */
	::PrimitiveTypes::Integer device_index();
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	::PrimitiveTypes::Integer get_attr_int(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_int(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::PrimitiveTypes::Integer /*in*/value);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_string(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param value 
	 */
	void set_attr_string(::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString& /*in*/value);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 */
	::EV3PapyrusLibrary::Types::LocalString get_attr_line(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name);
	/**
	 * 
	 * @return ret 
	 * @param name 
	 * @param pCur 
	 */
	::EV3PapyrusLibrary::Types::ModeSet get_attr_set(
			::EV3PapyrusLibrary::Types::LocalString& /*in*/name,
			::EV3PapyrusLibrary::Types::LocalString* /*in*/pCur);
	/**
	 * 
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
	virtual void run_for_second(int /*in*/power, int /*in*/second,
			bool /*in*/brake, bool /*in*/invert_sens = false) = 0;
	/**
	 * run the motor for a number of degres
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param degres the number of degres the motor run
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	virtual void run_for_degres(int /*in*/power, int /*in*/degres,
			bool /*in*/brake, bool /*in*/invert_sens = false) = 0;
	/**
	 * run the motor for a number of turn
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param nb_turn the number of turn
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	virtual void run_for_turn(int /*in*/power, int /*in*/nb_turn,
			bool /*in*/brake, bool /*in*/invert_sens = false) = 0;
	/**
	 * run the motor still there is a stop command
	 * @param power The power give to the motor (equivalent to the speed)
	 * @param invert_sens true is the rotation is inverted, false otherwise
	 * @return  
	 */
	virtual void start(int /*in*/power, bool /*in*/invert_sens = false) = 0;
	/**
	 * stop the motor
	 * @param brake true if there is a brake at the end of the movement, false otherwise
	 * @return  
	 */
	virtual void stop(bool /*in*/brake) = 0;
	/**
	 * 
	 */
	AbstractLargeMotor();

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Actuators
} // of namespace AbstractClasses
} // of namespace EV3PapyrusLibrary

/************************************************************
 End of AbstractLargeMotor class header
 ************************************************************/

#endif
