################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/bin/phys.pt/mse/main.o 

C_SRCS += \
../src/bin/phys.pt/mse/main.c 

OBJS += \
./src/bin/phys.pt/mse/main.o 

C_DEPS += \
./src/bin/phys.pt/mse/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/phys.pt/mse/%.o: ../src/bin/phys.pt/mse/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gccgcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


