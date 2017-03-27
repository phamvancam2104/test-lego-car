################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractBlutooth.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractButton.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractDevice.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLcd.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLed.cpp \
../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractSound.cpp 

OBJS += \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractBlutooth.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractButton.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractDevice.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLcd.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLed.o \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractSound.o 

CPP_DEPS += \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractBlutooth.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractButton.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractDevice.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLcd.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractLed.d \
./src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/AbstractSound.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/%.o: ../src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11 -D_GLIBCXX_USE_CXX11_ABI=0    -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


