################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractLargeMotor.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractMotor.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractServoMotor.cpp 

OBJS += \
./src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractLargeMotor.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractMotor.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractServoMotor.o 

CPP_DEPS += \
./src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractLargeMotor.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractMotor.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/AbstractServoMotor.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/%.o: ../src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11  -D_GLIBCXX_USE_CXX11_ABI=0  -O2 -s -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


