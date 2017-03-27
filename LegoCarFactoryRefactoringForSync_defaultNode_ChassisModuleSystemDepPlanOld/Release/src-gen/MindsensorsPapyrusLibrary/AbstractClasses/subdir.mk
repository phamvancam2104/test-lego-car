################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src-gen/MindsensorsPapyrusLibrary/AbstractClasses/AbstractNumericPad.cpp \
../src-gen/MindsensorsPapyrusLibrary/AbstractClasses/AbstractSensorMux.cpp 

OBJS += \
./src-gen/MindsensorsPapyrusLibrary/AbstractClasses/AbstractNumericPad.o \
./src-gen/MindsensorsPapyrusLibrary/AbstractClasses/AbstractSensorMux.o 

CPP_DEPS += \
./src-gen/MindsensorsPapyrusLibrary/AbstractClasses/AbstractNumericPad.d \
./src-gen/MindsensorsPapyrusLibrary/AbstractClasses/AbstractSensorMux.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/MindsensorsPapyrusLibrary/AbstractClasses/%.o: ../src-gen/MindsensorsPapyrusLibrary/AbstractClasses/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-linux-gnueabi-g++ -std=gnu++11  -D_GLIBCXX_USE_CXX11_ABI=0  -O2 -s -mcpu=arm9 -marm -O2  -g -I"/home/campv/generatedcode/test-lego-car/LegoCarFactoryRefactoringForSync_defaultNode_ChassisModuleSystemDepPlanOld/src-gen" -I"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


