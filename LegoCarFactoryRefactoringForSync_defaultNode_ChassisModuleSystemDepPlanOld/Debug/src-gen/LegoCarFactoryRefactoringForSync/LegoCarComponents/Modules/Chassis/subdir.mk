################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisControlComponent.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisConvoyer.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisModuleSystem.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisRoboticArm.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisShelf.cpp 

OBJS += \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisControlComponent.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisConvoyer.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisModuleSystem.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisRoboticArm.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisShelf.o 

CPP_DEPS += \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisControlComponent.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisConvoyer.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisModuleSystem.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisRoboticArm.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/ChassisShelf.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/%.o: ../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Chassis/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11 -D_GLIBCXX_USE_CXX11_ABI=0    -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


