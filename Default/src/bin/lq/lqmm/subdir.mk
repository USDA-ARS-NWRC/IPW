################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bin/lq/lqmm/main.c 

OBJS += \
./src/bin/lq/lqmm/main.o 

C_DEPS += \
./src/bin/lq/lqmm/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/lq/lqmm/%.o: ../src/bin/lq/lqmm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


