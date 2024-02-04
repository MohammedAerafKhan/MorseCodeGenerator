################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/final_project.c \
../source/morseConverter.c \
../source/semihost_hardfault.c 

S_SRCS += \
../source/function.s 

C_DEPS += \
./source/final_project.d \
./source/morseConverter.d \
./source/semihost_hardfault.d 

OBJS += \
./source/final_project.o \
./source/function.o \
./source/morseConverter.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK66FN2M0VMD18 -DCPU_MK66FN2M0VMD18_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/rashidkhan/SEH500Files/final_project/board" -I"/Users/rashidkhan/SEH500Files/final_project/source" -I"/Users/rashidkhan/SEH500Files/final_project/drivers" -I"/Users/rashidkhan/SEH500Files/final_project/device" -I"/Users/rashidkhan/SEH500Files/final_project/CMSIS" -I"/Users/rashidkhan/SEH500Files/final_project/component/uart" -I"/Users/rashidkhan/SEH500Files/final_project/component/serial_manager" -I"/Users/rashidkhan/SEH500Files/final_project/utilities" -I"/Users/rashidkhan/SEH500Files/final_project/component/lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.s source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"/Users/rashidkhan/SEH500Files/final_project/board" -I"/Users/rashidkhan/SEH500Files/final_project/source" -g3 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/final_project.d ./source/final_project.o ./source/function.o ./source/morseConverter.d ./source/morseConverter.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

