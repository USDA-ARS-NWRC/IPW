################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bin/rad.pt/trad_can/exp_int3.c \
../src/bin/rad.pt/trad_can/main.c 

OBJS += \
./src/bin/rad.pt/trad_can/exp_int3.o \
./src/bin/rad.pt/trad_can/main.o 

C_DEPS += \
./src/bin/rad.pt/trad_can/exp_int3.d \
./src/bin/rad.pt/trad_can/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/rad.pt/trad_can/%.o: ../src/bin/rad.pt/trad_can/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


