################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src-gen/statemachine/subdir.mk
-include src-gen/OtherComponentsPapyrusLibrary/ConcreteClasses/subdir.mk
-include src-gen/OtherComponentsPapyrusLibrary/AbstractClasses/subdir.mk
-include src-gen/MindsensorsPapyrusLibrary/ConcreteClasses/subdir.mk
-include src-gen/MindsensorsPapyrusLibrary/AbstractClasses/subdir.mk
-include src-gen/LegoCarFactoryRefactoringForSync/__Architecture__Controller/subdir.mk
-include src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Slaves/subdir.mk
-include src-gen/LegoCarFactoryRefactoringForSync/LegoCarComponents/Modules/Front/subdir.mk
-include src-gen/EV3PapyrusLibrary/EV3BrickPackage/subdir.mk
-include src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Sensors/subdir.mk
-include src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/EV3Brick/subdir.mk
-include src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/Actuators/subdir.mk
-include src-gen/EV3PapyrusLibrary/ConcreteClasses/ev3devCpp/subdir.mk
-include src-gen/EV3PapyrusLibrary/AbstractClasses/Sensors/subdir.mk
-include src-gen/EV3PapyrusLibrary/AbstractClasses/EV3Brick/subdir.mk
-include src-gen/EV3PapyrusLibrary/AbstractClasses/Actuators/subdir.mk
-include src-gen/EV3PapyrusLibrary/AbstractClasses/subdir.mk
-include src-gen/EV3PapyrusLibrary/subdir.mk
-include src-gen/CarFactoryLibrary/subdir.mk
-include src-gen/BootLoaderCpp/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.hex \

SECONDARY_SIZE += \
LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.siz \


# All Target
all: LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe

# Tool invocations
LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C++ Linker'
	arm-linux-gnueabi-g++ -std=gnu++11 -O2 -s -mcpu=arm9 -marm -O2  -g -Xlinker --gc-sections -L"/home/campv/Documents/lego/papyrus4Lego/official/externalLibraries/org.eclipse.papyrus.lego.library.ev3dev-lang.cpp/lib" -Wl,-Map,"LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.map" -o "LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.hex: LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-linux-gnueabi-objcopy -O ihex "LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe"  "LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.hex"
	@echo 'Finished building: $@'
	@echo ' '

LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.siz: LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-linux-gnueabi-size --format=berkeley "LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) LegoCarFactoryRefactoringForSync_defaultNode_FrontModuleSystemDepPlan.exe
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
