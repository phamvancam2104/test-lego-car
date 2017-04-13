// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define CarFactoryLibrary_Module_BODY

/************************************************************
 Module class body
 ************************************************************/

// Include from Include stereotype (pre-body)
#include <string>
#include <sstream>
using namespace std;
// End of Include stereotype (pre-body)

// include associated header file
#include "CarFactoryLibrary/Module.h"

// Derived includes directives
#include "CarFactoryLibrary/IModule.h"
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "EV3PapyrusLibrary/Interfaces/EV3Brick/ILcd.h"

namespace CarFactoryLibrary {

// static attributes (if any)
/**
 * Stock the name of the bluetooth_device
 */
::EV3PapyrusLibrary::Types::LocalString Module::bluetooth_name[] = {
		"CEA_master", "CEA_front", "CEA_back", "CEA_roof" };
/**
 * the order of modules (back can be before front)
 */
ModuleName Module::sequence_module[] = { MASTER_MODULE, FRONT_MODULE,
		BACK_MODULE, ROOF_MODULE };
/**
 * 
 */
const ::PrimitiveTypes::String Module::ColorsEnumToString[] = { "none", "blue",
		"white", "red" };

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
Module::Module(::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_muxPort,
		::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_mux_type1,
		::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_mux_type2,
		::EV3PapyrusLibrary::Types::LocalString /*in*/sensor_mux_type3,
		::EV3PapyrusLibrary::Types::LocalString /*in*/emergency_stopPort,
		::EV3PapyrusLibrary::Types::LocalString /*in*/nxt_servoSensorPort,
		::EV3PapyrusLibrary::Types::LocalString /*in*/nxt_servoMotorPort,
		::EV3PapyrusLibrary::Types::LocalString /*in*/status_led_redPort,
		::EV3PapyrusLibrary::Types::LocalString /*in*/status_led_orangePort,
		::EV3PapyrusLibrary::Types::LocalString /*in*/status_led_greenPort) :
		emergency_button(emergency_stopPort), nxt_servo(nxt_servoMotorPort,
				nxt_servoSensorPort), led_status(status_led_redPort,
				status_led_orangePort, status_led_greenPort), is_stop(false), is_misplace(
				true) {
	std::vector < EV3PapyrusLibrary::Types::LocalString > tmp = std::vector
			< EV3PapyrusLibrary::Types::LocalString
			> ( {	sensor_mux_type1, sensor_mux_type2, sensor_mux_type3});
	sensor_mux = ::MindsensorsPapyrusLibrary::ConcreteClasses::CppSensorMux(
			sensor_muxPort, tmp);
}

/**
 * turn on red lights
 */
void Module::manageRedLights() {
	ev3Brick.allLedOff();
	ev3Brick.leftRedLed.on();
	ev3Brick.rightRedLed.on();
	led_status.red_led();
}

/**
 * turn on green lights
 */
void Module::manageGreenLights() {
	ev3Brick.allLedOff();
	ev3Brick.leftGreenLed.on();
	ev3Brick.rightGreenLed.on();
	led_status.green_led();
}

/**
 * turn on green lights
 */
void Module::manageOrangeLights() {
	ev3Brick.allLedOn();
	led_status.orange_led();
}

/**
 * show a pop up massage
 * @param text 
 * @param size 
 */
void Module::showPopUpMessage(
		::EV3PapyrusLibrary::Types::LocalString /*in*/text,
		::EV3PapyrusLibrary::Types::TextSize /*in*/size) {
	int text_width = 0;
	int text_height = 0;
	switch (size) {
	case lcd::LARGE:
		text_width = ev3Brick.lcdScreen.LARGE_LETTER_WIDTH * text.size();
		text_height = ev3Brick.lcdScreen.LARGE_LETTER_HEIGHT;
		break;
	case lcd::NORMAL:
		text_width = ev3Brick.lcdScreen.NORMAL_LETTER_WIDTH * text.size();
		text_height = ev3Brick.lcdScreen.NORMAL_LETTER_HEIGHT;
		break;
	case lcd::SMALL:
		text_width = ev3Brick.lcdScreen.SMALL_LETTER_WIDTH * text.size();
		text_height = ev3Brick.lcdScreen.SMALL_LETTER_HEIGHT;
		break;
	case lcd::TINY:
		text_width = ev3Brick.lcdScreen.TINY_LETTER_WIDTH * text.size();
		text_height = ev3Brick.lcdScreen.TINY_LETTER_HEIGHT;
		break;
	}
	int x_position = (ev3Brick.lcdScreen.LCD_SCREEN_WIDTH - text_width) / 2;
	int y_position = (ev3Brick.lcdScreen.LCD_SCREEN_HEIGHT - text_height) / 2;
	ev3Brick.lcdScreen.draw_empty_rectangle(x_position, y_position,
			text_width + 6, text_height + 6, true);
	ev3Brick.lcdScreen.draw_full_rectangle(x_position + 1, y_position + 1,
			text_width + 4, text_height + 4, false);
	ev3Brick.lcdScreen.write_text(x_position + 3, y_position + 3, text, size);
}

/**
 * turn on red lights and display message on screen 
 */
void Module::showStopGUI() {
	ev3Brick.lcdScreen.clear();
	ev3Brick.lcdScreen.write_text(5, 20, "Press enter", lcd::TextSize::LARGE);
	ev3Brick.lcdScreen.write_text(5, 40, "When ready", lcd::TextSize::LARGE);
	manageRedLights();
}

/**
 * turn on red lights and display message on screen 
 */
void Module::showMisplacePartGUI() {
	ev3Brick.lcdScreen.clear();
	ev3Brick.lcdScreen.write_text(5, 10, "PLACEMENT", lcd::TextSize::LARGE);
	ev3Brick.lcdScreen.write_text(5, 30, "ERROR!", lcd::TextSize::LARGE);
	ev3Brick.lcdScreen.write_text(5, 50, "Press enter", lcd::TextSize::NORMAL);
	ev3Brick.lcdScreen.write_text(5, 65, "When ready", lcd::TextSize::NORMAL);
	manageRedLights();
}

/**
 * turn on red lights and display message on screen 
 * @param color 
 */
void Module::showEmptyRackGUI(Colors /*in*/color) {
	ev3Brick.lcdScreen.clear();
	ev3Brick.lcdScreen.write_text(5, 20, "EMPTY RACK!", lcd::TextSize::LARGE);
	std::string which_rack("");
	which_rack += std::string("(") + ColorsEnumToString[color]
			+ std::string(")");
	ev3Brick.lcdScreen.write_text(5, 65, which_rack, lcd::TextSize::NORMAL);
	ev3Brick.lcdScreen.write_text(5, 50, "Refill & press Enter",
			lcd::TextSize::NORMAL);
	manageRedLights();
}

/**
 * send a bluetooth message (BluetoothMasterEnum) with the value as a string, then it wait an answer
 * @param name name of the receiver
 * @param value the command to transmit
 * @param extraValue an optional string to add information to the command (e.g. give color)
 * @return ret the answer of the slave
 */
BluetoothSlaveEnum Module::writeWaitReply(ModuleName /*in*/name,
		BluetoothMasterEnum /*in*/value,
		::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue) {
	stringstream convert;
	int int_value = static_cast<int>(value);
	convert << int_value;

	string tmp = convert.str();
	if (extraValue != "") {
		tmp += "-" + extraValue;
	}
	ev3Brick.bluetoothDevice.write(bluetooth_name[name], tmp);

	return readFromSlave(name);
}

/**
 * send a bluetooth message (BluetoothMasterEnum) with the value as a string, then it wait an answer
 * @param index the index of the receiver in the table sequence_module
 * @param value the command to transmit
 * @param extraValue an optional string to add information to the command (e.g. give color)
 * @return ret the answer of the slave
 */
BluetoothSlaveEnum Module::writeWaitReply(int /*in*/index,
		BluetoothMasterEnum /*in*/value,
		::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue) {
	ModuleName module_name = sequence_module[index];
	return writeWaitReply(module_name, value, extraValue);
}

/**
 * send a bluetooth message (BluetoothSlaveEnum) with the value as a string
 * @param name name of the receiver
 * @param value the command to transmit
 * @param extraValue an optional string to add information to the command (e.g. give color)
 */
void Module::write(ModuleName /*in*/name, BluetoothSlaveEnum /*in*/value,
		::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue) {
	stringstream convert;
	int int_value = static_cast<int>(value);
	convert << int_value;

	string tmp = convert.str();
	if (extraValue != "") {
		tmp += tmp + "-" + extraValue;
	}
	ev3Brick.bluetoothDevice.write(bluetooth_name[name], tmp);
}

/**
 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
 * @param name name of the receiver
 * @param value the command to transmit
 * @param extraValue an optional string to add information to the command (e.g. give color)
 */
void Module::write(ModuleName /*in*/name, BluetoothMasterEnum /*in*/value,
		::EV3PapyrusLibrary::Types::LocalString /*in*/extraValue) {
	stringstream convert;
	int int_value = static_cast<int>(value);
	convert << int_value;

	string tmp = convert.str();
	if (extraValue != "") {
		tmp += tmp + "-" + extraValue;
	}
	ev3Brick.bluetoothDevice.write(bluetooth_name[name], tmp);
}

/**
 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString Module::readFromMaster() {
	std::string buf = std::string();
	ev3Brick.bluetoothDevice.read(bluetooth_name[MASTER_MODULE], &buf);
	return buf;
}

/**
 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
 * @param name 
 * @return ret 
 */
BluetoothSlaveEnum Module::readFromSlave(ModuleName /*in*/name) {
	std::string buf = std::string();
	ev3Brick.bluetoothDevice.read(bluetooth_name[name], &buf);
	if (buf.compare("") != 0) {
		int tmp = std::stoi(buf);
		BluetoothSlaveEnum msg = static_cast<BluetoothSlaveEnum>(tmp);
		return msg;
	}
	return NO_SLAVE_MSG;
}

/**
 * send a bluetooth message (BluetoothMasterEnum) with the value as a string
 * @param value 
 * @return ret 
 */
BluetoothMasterEnum Module::parseMasterMessage(
		::EV3PapyrusLibrary::Types::LocalString /*in*/value) {
	if (value.compare("") != 0) {
		int tmp = std::stoi(value);
		BluetoothMasterEnum msg = static_cast<BluetoothMasterEnum>(tmp);
		return msg;
	}
	return NO_MASTER_MSG;
}

/**
 * 
 * @return ret 
 */
BluetoothSlaveEnum Module::getStatus() {
	return this->status;
}

/**
 * 
 * @param status 
 */
void Module::setStatus(BluetoothSlaveEnum /*in*/status) {
	this->status = status;
}

/**
 * 
 * @return ret 
 */
int Module::getCurrentModule() {
	return this->current_module;
}

/**
 * 
 * @return ret 
 */
::EV3PapyrusLibrary::Types::LocalString& Module::getBluetoothName() {
	return (::EV3PapyrusLibrary::Types::LocalString&) (this->bluetooth_name);
}

/**
 * 
 * @param sig 
 * @return ret 
 */
void Module::sendErrorDetection(
		::CarFactoryLibrary::events::ErrorDetection& /*in*/sig) {
}

/**
 * 
 * @param sig 
 * @return ret 
 */
void Module::sendEndOfModule(
		::CarFactoryLibrary::events::EndOfModule& /*in*/sig) {
}

} // of namespace CarFactoryLibrary

/************************************************************
 End of Module class body
 ************************************************************/
