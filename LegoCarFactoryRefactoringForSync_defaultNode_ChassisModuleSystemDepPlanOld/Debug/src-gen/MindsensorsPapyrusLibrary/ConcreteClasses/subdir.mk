################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/CppNumericPad.cpp \
../src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/CppSensorMux.cpp 

OBJS += \
./src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/CppNumericPad.o \
./src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/CppSensorMux.o 

CPP_DEPS += \
./src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/CppNumericPad.d \
./src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/CppSensorMux.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/%.o: ../src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11 -D_GLIBCXX_USE_CXX11_ABI=0    -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


