################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bin/rad.pt/twostream/main.c 

OBJS += \
./src/bin/rad.pt/twostream/main.o 

C_DEPS += \
./src/bin/rad.pt/twostream/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/rad.pt/twostream/%.o: ../src/bin/rad.pt/twostream/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


