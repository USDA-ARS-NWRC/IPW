################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bin/export/ipw2ps/main.c \
../src/bin/export/ipw2ps/pspic.c \
../src/bin/export/ipw2ps/pspicx.c 

OBJS += \
./src/bin/export/ipw2ps/main.o \
./src/bin/export/ipw2ps/pspic.o \
./src/bin/export/ipw2ps/pspicx.o 

C_DEPS += \
./src/bin/export/ipw2ps/main.d \
./src/bin/export/ipw2ps/pspic.d \
./src/bin/export/ipw2ps/pspicx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/export/ipw2ps/%.o: ../src/bin/export/ipw2ps/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


