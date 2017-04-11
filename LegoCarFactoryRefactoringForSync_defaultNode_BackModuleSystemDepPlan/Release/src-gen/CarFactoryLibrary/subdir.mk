################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/CarFactoryLibrary/Conveyor.cpp \
../src-gen/CarFactoryLibrary/Module.cpp \
../src-gen/CarFactoryLibrary/Pliers.cpp \
../src-gen/CarFactoryLibrary/Press.cpp \
../src-gen/CarFactoryLibrary/Rack.cpp \
../src-gen/CarFactoryLibrary/RoboticArm.cpp \
../src-gen/CarFactoryLibrary/Shelf.cpp 

OBJS += \
./src-gen/CarFactoryLibrary/Conveyor.o \
./src-gen/CarFactoryLibrary/Module.o \
./src-gen/CarFactoryLibrary/Pliers.o \
./src-gen/CarFactoryLibrary/Press.o \
./src-gen/CarFactoryLibrary/Rack.o \
./src-gen/CarFactoryLibrary/RoboticArm.o \
./src-gen/CarFactoryLibrary/Shelf.o 

CPP_DEPS += \
./src-gen/CarFactoryLibrary/Conveyor.d \
./src-gen/CarFactoryLibrary/Module.d \
./src-gen/CarFactoryLibrary/Pliers.d \
./src-gen/CarFactoryLibrary/Press.d \
./src-gen/CarFactoryLibrary/Rack.d \
./src-gen/CarFactoryLibrary/RoboticArm.d \
./src-gen/CarFactoryLibrary/Shelf.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/CarFactoryLibrary/%.o: ../src-gen/CarFactoryLibrary/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11  -D_GLIBCXX_USE_CXX11_ABI=0  -O2 -s   -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_BackModuleSystemDepPlan/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


