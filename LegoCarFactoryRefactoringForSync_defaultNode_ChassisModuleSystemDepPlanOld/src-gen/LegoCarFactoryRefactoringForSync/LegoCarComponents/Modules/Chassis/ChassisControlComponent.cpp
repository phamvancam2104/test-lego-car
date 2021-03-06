// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define LegoCarFactoryRefactoringForSync_LegoCarComponents_Modules_Chassis_ChassisControlComponent_BODY

/************************************************************
              ChassisControlComponent class body
 ************************************************************/


// include associated header file
#include "LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisControlComponent.h"

// Derived includes directives
#include "CarFactoryLibrary/events/EndOfModule.h"
#include "CarFactoryLibrary/events/ErrorDetection.h"
#include "LegoCarFactoryRefactoringForSync/signals/PrepareConveyor.h"
#include "LegoCarFactoryRefactoringForSync/signals/RestartAfterEmergencyStop.h"
#include "LegoCarFactoryRefactoringForSync/signals/StopProcess.h"
#include "MindsensorsPapyrusLibrary/ConcreteClasses/CppNumericPad.h"

// Include from Include declaration (body)
void bindPorts(Port& p1, Port& p2) {
}
// End of Include declaration (body)

namespace LegoCarFactoryRefactoringForSync {
namespace LegoCarComponents {
namespace Modules {
namespace Chassis {

// static attributes (if any)

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoice4toSendRestartEventGuard() {
	return ev3Brick.topButton.pressed();
}

/**
 * 
 */
ChassisControlComponent::ChassisControlComponent(): ::CarFactoryLibrary::Module("in2", "lego-ev3-color", "lego-ev3-color",
				"lego-ev3-color", "in4", "in3:i2c88", "outB", "in3:i2c88:sv6",
				"in3:i2c88:sv7", "in3:i2c88:sv8"), keypad("in1") {
}

/**
 * 
 * @return ret 
 */
 int ChassisControlComponent::wait_key_pad_release() {
	int key = keypad.read_next_touched_key();
		string speak_text = "";
		switch (key) {
		//Front
		case 1:
			front_color = CarFactoryLibrary::RED;
			speak_text = "red front";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 4:
			front_color = CarFactoryLibrary::WHITE;
			speak_text = "white front";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 7:
			front_color = CarFactoryLibrary::BLUE;
			speak_text = "blue front";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
			//Roof
		case 2:
			roof_color = CarFactoryLibrary::RED;
			speak_text = "red roof";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 5:
			roof_color = CarFactoryLibrary::WHITE;
			speak_text = "white roof";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 8:
			roof_color = CarFactoryLibrary::BLUE;
			speak_text = "blue roof";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 0:
			roof_color = CarFactoryLibrary::NONE;
			speak_text = "no roof";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
			//Back
		case 3:
			back_color = CarFactoryLibrary::RED;
			speak_text = "red back";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 6:
			back_color = CarFactoryLibrary::WHITE;
			speak_text = "white back";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
		case 9:
			back_color = CarFactoryLibrary::BLUE;
			speak_text = "blue back";
			ev3Brick.soundDevice.speak(speak_text, false);
			break;
			//Cancel
		case 10:
			sleep(1);
			return 1;
			break;
			//Validate
		case 11:
			sleep(1);
			return 2;
			break;
		default:
			break;
		}
		usleep(50000);
		return 0;
}

/**
 * 
 */
void ChassisControlComponent::show_car_configuration() {
	ev3Brick.lcdScreen.clear();
		ev3Brick.lcdScreen.draw_bmp_image("./images/Car_side.bmp", 0, 0, false);
		ev3Brick.lcdScreen.write_text(100, 5, ColorsEnumToString[roof_color],
				::EV3PapyrusLibrary::Types::TextSize::NORMAL);
		ev3Brick.lcdScreen.write_text(45, 68, ColorsEnumToString[front_color],
				::EV3PapyrusLibrary::Types::TextSize::LARGE);
		ev3Brick.lcdScreen.write_text(135, 75, ColorsEnumToString[back_color],
				::EV3PapyrusLibrary::Types::TextSize::NORMAL);
}

/**
 * 
 */
void ChassisControlComponent::choose_colors() {
	bool isValidate = false;
		show_car_configuration();
		while (!isValidate) {
			int state = wait_key_pad_release();
			if (state == 2) { //Validate
				if (front_color != CarFactoryLibrary::NONE
						&& back_color != CarFactoryLibrary::NONE) { //Wait for validate or cancel
					isValidate = true;
					ev3Brick.soundDevice.tone(300, 50);
					usleep(60000);
					ev3Brick.soundDevice.tone(600, 50);
					showPopUpMessage("OK?", lcd::LARGE);
					int confirmation = wait_key_pad_release();
					if (confirmation == 2) {
						ev3Brick.soundDevice.tone(1000, 100);
						show_car_configuration();
						return;
					} else if (confirmation == 1) {
						ev3Brick.soundDevice.tone(600, 50);
						usleep(60000);
						ev3Brick.soundDevice.tone(300, 50);
						show_car_configuration();
					}
				} else { //Car configuration is not complete
					ev3Brick.soundDevice.tone(100, 100);
					ev3Brick.lcdScreen.clear();
					ev3Brick.lcdScreen.write_text(40, 35, "Setup",
							::EV3PapyrusLibrary::Types::TextSize::NORMAL);
					ev3Brick.lcdScreen.write_text(5, 55, "incomplete",
							::EV3PapyrusLibrary::Types::TextSize::NORMAL);
					sleep(1);
				}
			}
			show_car_configuration();
		}
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::init_bluetooth_communication() {
	bool ret = true;
	
		CarFactoryLibrary::ModuleName device_name = CarFactoryLibrary::ROOF_MODULE;
		if (!ev3Brick.bluetoothDevice.connect(bluetooth_name[device_name])) {
			ret = false;
		}
	
		if (ret && readFromSlave(device_name) != CarFactoryLibrary::RESULT_OK) {
			ret = false;
		}
	
		if (!ret) {
			ev3Brick.lcdScreen.clear();
			ev3Brick.lcdScreen.write_text(0, 20, "COMM ERROR!",
					::EV3PapyrusLibrary::Types::TextSize::LARGE);
			ev3Brick.lcdScreen.write_text(0, 40, bluetooth_name[device_name],
					::EV3PapyrusLibrary::Types::TextSize::NORMAL);
			sleep(2);
			return ret;
		}
	
		device_name = CarFactoryLibrary::BACK_MODULE;
		if (!ev3Brick.bluetoothDevice.connect(bluetooth_name[device_name])) {
			ret = false;
		}
	
		if (ret && readFromSlave(device_name) != CarFactoryLibrary::RESULT_OK) {
			ret = false;
		}
	
		if (!ret) {
			ev3Brick.lcdScreen.clear();
			ev3Brick.lcdScreen.write_text(0, 20, "COMM ERROR!",
					::EV3PapyrusLibrary::Types::TextSize::LARGE);
			ev3Brick.lcdScreen.write_text(0, 40, bluetooth_name[device_name],
					::EV3PapyrusLibrary::Types::TextSize::NORMAL);
			sleep(2);
			return ret;
		}
	
		device_name = CarFactoryLibrary::FRONT_MODULE;
		if (!ev3Brick.bluetoothDevice.connect(bluetooth_name[device_name])) {
			ret = false;
		}
	
		if (ret && readFromSlave(device_name) != CarFactoryLibrary::RESULT_OK) {
			ret = false;
		}
	
		if (!ret) {
			ev3Brick.lcdScreen.clear();
			ev3Brick.lcdScreen.write_text(0, 20, "COMM ERROR!",
					::EV3PapyrusLibrary::Types::TextSize::LARGE);
			ev3Brick.lcdScreen.write_text(0, 40, bluetooth_name[device_name],
					::EV3PapyrusLibrary::Types::TextSize::NORMAL);
			sleep(2);
			return ret;
		}
	
		return ret;
}

/**
 * 
 */
void ChassisControlComponent::send_stop_to_slave() {
	sleep(2);
		write(CarFactoryLibrary::FRONT_MODULE, CarFactoryLibrary::CMD_STOP);
		write(CarFactoryLibrary::BACK_MODULE, CarFactoryLibrary::CMD_STOP);
		write(CarFactoryLibrary::ROOF_MODULE, CarFactoryLibrary::CMD_STOP);
}

/**
 * 
 */
void ChassisControlComponent::choose_back_front_order() {
	bool buttonIsPresses = false;
	
		ev3Brick.lcdScreen.clear();
		ev3Brick.lcdScreen.write_text(0, 10, "Select",
				::EV3PapyrusLibrary::Types::TextSize::NORMAL);
		ev3Brick.lcdScreen.write_text(0, 30, "order:",
				::EV3PapyrusLibrary::Types::TextSize::NORMAL);
		ev3Brick.lcdScreen.write_text(0, 80, "Back->Front",
				::EV3PapyrusLibrary::Types::TextSize::NORMAL);
		ev3Brick.lcdScreen.write_text(0, 95, "           Front->Back",
				::EV3PapyrusLibrary::Types::TextSize::NORMAL);
	
		while (!buttonIsPresses) {
			if (ev3Brick.leftButton.pressed()) {
				buttonIsPresses = true;
				showPopUpMessage("Back>Front",
						::EV3PapyrusLibrary::Types::TextSize::LARGE);
				sequence_module[1] = CarFactoryLibrary::BACK_MODULE;
				sequence_module[2] = CarFactoryLibrary::FRONT_MODULE;
			}
			if (ev3Brick.rightButton.pressed()) {
				buttonIsPresses = true;
				showPopUpMessage("Front>Back",
						::EV3PapyrusLibrary::Types::TextSize::LARGE);
				sequence_module[1] = CarFactoryLibrary::FRONT_MODULE;
				sequence_module[2] = CarFactoryLibrary::BACK_MODULE;
			}
		}
		sleep(1);
}

/**
 * 
 * @param sig 
 */
void ChassisControlComponent::effectFromEmergencyStopStatetoMisplace(::CarFactoryLibrary::events::ErrorDetection& /*in*/ sig) {
	error_detection_is_misplace = sig.is_misplace;
}

/**
 * 
 */
void ChassisControlComponent::choice0toSendRestartEventEffect() {
	if (current_module != CarFactoryLibrary::FRONT_MODULE)
			writeWaitReply(CarFactoryLibrary::FRONT_MODULE,
					CarFactoryLibrary::CMD_RESET);
		if (current_module != CarFactoryLibrary::BACK_MODULE)
			writeWaitReply(CarFactoryLibrary::BACK_MODULE,
					CarFactoryLibrary::CMD_RESET);
		if (current_module != ROOF_MODULE)
			writeWaitReply(CarFactoryLibrary::ROOF_MODULE,
					CarFactoryLibrary::CMD_RESET);
	
		current_module = 0;
}

/**
 * 
 */
void ChassisControlComponent::rewind_last_module() {
	writeWaitReply(CarFactoryLibrary::ROOF_MODULE,
				CarFactoryLibrary::CMD_REWIND);
}

/**
 * 
 */
void ChassisControlComponent::fromChoice2toPrepareConvoyerEffect() {
	current_module++;
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoice2toPrepareConveyorGuard() {
	return current_module != 3;
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoice1toStopMotorsGuard() {
	return emergency_button.value(0)
				&& current_module == CarFactoryLibrary::MASTER_MODULE;
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoice0toSendRestartEventGuard() {
	return true;
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoicetoSendRestartEventGuard() {
	return ev3Brick.topButton.pressed();
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoice13toChooseBackFrontOrderGuard() {
	return init_bluetooth_communication();
}

/**
 * 
 * @return ret 
 */
 bool ChassisControlComponent::fromChoice5toSendRestartEventGuard() {
	return current_module != CarFactoryLibrary::MASTER_MODULE;
}



} // of namespace Chassis
} // of namespace Modules
} // of namespace LegoCarComponents
} // of namespace LegoCarFactoryRefactoringForSync

/************************************************************
              End of ChassisControlComponent class body
 ************************************************************/
