################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bin/transform/skew/main.c \
../src/bin/transform/skew/skew.c 

OBJS += \
./src/bin/transform/skew/main.o \
./src/bin/transform/skew/skew.o 

C_DEPS += \
./src/bin/transform/skew/main.d \
./src/bin/transform/skew/skew.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/transform/skew/%.o: ../src/bin/transform/skew/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


