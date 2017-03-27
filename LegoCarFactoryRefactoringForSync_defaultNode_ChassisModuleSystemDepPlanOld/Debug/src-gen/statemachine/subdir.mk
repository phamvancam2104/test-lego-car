################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/statemachine/EventPriorityQueue.cpp \
../src-gen/statemachine/Event_t.cpp \
../src-gen/statemachine/StructForThread_t.cpp 

OBJS += \
./src-gen/statemachine/EventPriorityQueue.o \
./src-gen/statemachine/Event_t.o \
./src-gen/statemachine/StructForThread_t.o 

CPP_DEPS += \
./src-gen/statemachine/EventPriorityQueue.d \
./src-gen/statemachine/Event_t.d \
./src-gen/statemachine/StructForThread_t.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/statemachine/%.o: ../src-gen/statemachine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11 -D_GLIBCXX_USE_CXX11_ABI=0    -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


