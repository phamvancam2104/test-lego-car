// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef CARFACTORYLIBRARY_MODULE_H
#define CARFACTORYLIBRARY_MODULE_H

/************************************************************
 Module class header
 ************************************************************/

#include "CarFactoryLibrary/Pkg_CarFactoryLibrary.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "CarFactoryLibrary/IModule.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/CppNxtServo.h"
#include "EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/CppTouchSensor.h"
#include "EV3PapyrusLibrary/EV3BrickPackage/CppEV3Brick.h"
#include "EV3PapyrusLibrary/Types/Pkg_Types.h"
#include "LegoCarFactoryRefactoringForSync/__Architecture__Controller/CarFactoryLibraryModule__Controller.h"
#include "MindsensorsPapyrusLibrary/ConcreteClasses/CppSensorMux.h"
#include "OtherComponentsPapyrusLibrary/ConcreteClasses/CppLedStatus.h"
#include "PrimitiveTypes/Pkg_PrimitiveTypes.h"

namespace CarFactoryLibrary {
namespace events {
class EndOfModule;
}
}
namespace CarFactoryLibrary {
namespace events {
class ErrorDetection;
}
}

namespace CarFactoryLibrary {

/************************************************************/
/**
 * module of the factory
 */
class Module: public IModule {
public:
	/**
	 * the Brick on which the program will be launch
	 */
	::EV3PapyrusLibrary::EV3BrickPackage::CppEV3Brick ev3Brick;
	/**
	 * the multiplexer of sensors
	 */
	::MindsensorsPapyrusLibrary::ConcreteClasses::CppSensorMux sensor_mux;
	/**
	 * the touch sensor represented the emergency stop
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::Sensors::CppTouchSensor emergency_button;
	/**
	 * the led status corresponding to the traffic light
	 */
	::OtherComponentsPapyrusLibrary::ConcreteClasses::CppLedStatus led_status;
	/**
	 * is true if the conveyor sensor detect that the piece is misplace
	 */
	bool is_misplace;
	/**
	 * is true if the program is stop (due to error detection or emergency stop)
	 */
	bool is_stop;
	/**
	 * the nxt servo of the chassis module (which is a sort of multiplexer of motor)
	 */
	::EV3PapyrusLibrary::ConcreteClasses::ev3devCpp::CppNxtServo nxt_servo;
	/**
	 * Stock the name of the bluetooth_device
	 */
	static ::EV3PapyrusLibrary::Types::LocalString bluetooth_name[];
	/**
	 * the module whiwh is actualy running
	 */
	int current_module;
	/**
	 * the order of modules (back can be before front)
	 */
	static ModuleName sequence_module[];
	/**
	 * if this is the master module, status is for status of the running slave module
	 * if this is a stave module, status is for current status
	 */
	BluetoothSlaveEnum status;
	/**
	 * 
	 */
	static const ::PrimitiveTypes::String ColorsEnumToString[];
	/**
	 * is true if the error_detection signal receive is du to misplace error else it is false
	 */
	bool error_detection_is_misplace;
	/**
	 * 
	 */
	::LegoCarFactoryRefactoringForSync::__Architecture__Controller::CarFactoryLibraryModule__Controller moduleController;
	/**
	 * constructor of the Module
	 * @param sensor_muxPort host port name of the multiplexer of sensor
	 * @param sensor_mux_type1 C1 port name of the multiplexer of sensor
	 * @param sensor_mux_type2 C2 port name of the multiplexer of sensor
	 * @param sensor_mux_type3 C3 port name of the multiplexer of sensor
	 * @param emergency_stopPort port name of the emergency stop
	 * @param nxt_servoSensorPort sensor port name nxt servo
	 * @param nxt_servoMotorPort motor port name nxt servo
	 * @param status_led_redPort port name of the red led of the status led
	 * @param status_led_orangePort port name of the orange led of the status led
	 * @param status_led_greenPort port name of the green led of the status led
	 */
	Module(::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_muxPort,
			::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_mux_type1,
			::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_mux_type2,
			::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_mux_type3,
			::EV3PapyrusLibrary::Types::LocalString /*in*/emergency_stopPort,
			::EV3PapyrusLibrary::Types::LocalString /*in*/nxt_servoSensorPort,
			::EV3PapyrusLibrary::Types::LocalString /*in*/nxt_servoMotorPort,
			::EV3PapyrusLibrary::Types::LocalString /*in*/status_led_redPort,
			::EV3PapyrusLibrary::Types::LocalString /*in*/status_led_orangePort,
			::EV3PapyrusLibrary::Types::LocalString /*in*/status_led_greenPort);
	/**
	 * turn on red lights
	 */
	void manageRedLights();
	/**
	 * turn on green lights
	 */
	void manageGreenLights();
	/**
	 * turn on green lights
	 */
	void manageOrangeLights();
	/**
	 * show a pop up massage
	 * @param text 
	 * @param size 
	 */
	void showPopUpMessage(::EV3PapyrusLibrary::Types::LocalString /*in*/text,
			::EV3PapyrusLibrary::Types::TextSize /*in*/size);
	/**
	 * turn on red lights and display message on screen 
	 */
	void showStopGUI();
	/**
	 * turn on red lights and display message on screen 
	 */
	void showMisplacePartGUI();
	/**
	 * turn on red lights and display message on screen 
	 * @param color 
	 */
	void showEmptyRackGUI(Colors /*in*/color);
	/**
	 * send a bluetooth message (BluetoothMasterEnum) with the value as a string, then it wait an answer
	 * @param name name of the receiver
	 * @param value the command to transmit
	 * @param extraValue an optional string to add information to the command (e.g. give color)
	 * @return ret the answer of the slave
	 */
	BluetoothSlaveEnum writeWaitReply(ModuleName /*in*/name,
			BluetoothMasterEnum /*in*/value,
			::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue = "");
	/**
	 * send a bluetooth message (BluetoothMasterEnum) with the value as a string, then it wait an answer
	 * @param index the index of the receiver in the table sequence_module
	 * @param value the command to transmit
	 * @param extraValue an optional string to add information to the command (e.g. give color)
	 * @return ret the answer of the slave
	 */
	BluetoothSlaveEnum writeWaitReply(int /*in*/index,
			BluetoothMasterEnum /*in*/value,
			::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue = "");
	/**
	 * send a bluetooth message (BluetoothSlaveEnum) with the value as a string
	 * @param name name of the receiver
	 * @param value the command to transmit
	 * @param extraValue an optional string to add information to the command (e.g. give color)
	 */
	void write(ModuleName /*in*/name, BluetoothSlaveEnum /*in*/value,
			::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue = "");
	/**
	 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
	 * @param name name of the receiver
	 * @param value the command to transmit
	 * @param extraValue an optional string to add information to the command (e.g. give color)
	 */
	void write(ModuleName /*in*/name, BluetoothMasterEnum /*in*/value,
			::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue = "");
	/**
	 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString readFromMaster();
	/**
	 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
	 * @param name 
	 * @return ret 
	 */
	BluetoothSlaveEnum readFromSlave(ModuleName /*in*/name);
	/**
	 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
	 * @param value 
	 * @return ret 
	 */
	BluetoothMasterEnum parseMasterMessage(
			::EV3PapyrusLibrary::Types::LocalString /*in*/value);
	/**
	 * 
	 * @return ret 
	 */
	BluetoothSlaveEnum getStatus();
	/**
	 * 
	 * @param status 
	 */
	void setStatus(BluetoothSlaveEnum /*in*/status);
	/**
	 * 
	 * @return ret 
	 */
	int getCurrentModule();
	/**
	 * 
	 * @return ret 
	 */
	::EV3PapyrusLibrary::Types::LocalString& getBluetoothName();
	/**
	 * 
	 * @param sig 
	 * @return ret 
	 */
	void sendErrorDetection(
			::CarFactoryLibrary::events::ErrorDetection& /*in*/sig);
	/**
	 * 
	 * @param sig 
	 * @return ret 
	 */
	void sendEndOfModule(::CarFactoryLibrary::events::EndOfModule& /*in*/sig);

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace CarFactoryLibrary

/************************************************************
 End of Module class header
 ************************************************************/

#endif
