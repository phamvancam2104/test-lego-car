################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.cpp \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppButton.cpp \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppDevice.cpp \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLcd.cpp \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLed.cpp \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppSound.cpp 

OBJS += \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.o \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppButton.o \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppDevice.o \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLcd.o \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLed.o \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppSound.o 

CPP_DEPS += \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppBlutooth.d \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppButton.d \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppDevice.d \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLcd.d \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppLed.d \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/CppSound.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/%.o: ../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11  -D_GLIBCXX_USE_CXX11_ABI=0  -O2 -s   -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_BackModuleSystemDepPlan/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


