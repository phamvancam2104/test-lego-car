################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/CppTouchSensor.cpp 

OBJS += \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/CppTouchSensor.o 

CPP_DEPS += \
./src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/CppTouchSensor.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/%.o: ../src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11 -D_GLIBCXX_USE_CXX11_ABI=0    -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

