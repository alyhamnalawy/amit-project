################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/steppermotor/steppermotor.c 

OBJS += \
./HAL/steppermotor/steppermotor.o 

C_DEPS += \
./HAL/steppermotor/steppermotor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/steppermotor/%.o: ../HAL/steppermotor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


