################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bin/datetime/cmptime/main.c 

OBJS += \
./src/bin/datetime/cmptime/main.o 

C_DEPS += \
./src/bin/datetime/cmptime/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/datetime/cmptime/%.o: ../src/bin/datetime/cmptime/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


