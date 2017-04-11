################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackControlComponent.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackConvoyer.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackModuleSystem.cpp \
../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackRoboticArm.cpp 

OBJS += \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackControlComponent.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackConvoyer.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackModuleSystem.o \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackRoboticArm.o 

CPP_DEPS += \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackControlComponent.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackConvoyer.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackModuleSystem.d \
./src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/BackRoboticArm.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/%.o: ../src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Back/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11  -D_GLIBCXX_USE_CXX11_ABI=0  -O2 -s   -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_BackModuleSystemDepPlan/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


