################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/bin/phys.spat/indvi/headers.o \
../src/bin/phys.spat/indvi/indvi.o \
../src/bin/phys.spat/indvi/main.o \
../src/bin/phys.spat/indvi/output.o \
../src/bin/phys.spat/indvi/parm.o 

C_SRCS += \
../src/bin/phys.spat/indvi/headers.c \
../src/bin/phys.spat/indvi/indvi.c \
../src/bin/phys.spat/indvi/main.c \
../src/bin/phys.spat/indvi/output.c \
../src/bin/phys.spat/indvi/parm.c 

OBJS += \
./src/bin/phys.spat/indvi/headers.o \
./src/bin/phys.spat/indvi/indvi.o \
./src/bin/phys.spat/indvi/main.o \
./src/bin/phys.spat/indvi/output.o \
./src/bin/phys.spat/indvi/parm.o 

C_DEPS += \
./src/bin/phys.spat/indvi/headers.d \
./src/bin/phys.spat/indvi/indvi.d \
./src/bin/phys.spat/indvi/main.d \
./src/bin/phys.spat/indvi/output.d \
./src/bin/phys.spat/indvi/parm.d 


# Each subdirectory must supply rules for building sources it contributes
src/bin/phys.spat/indvi/%.o: ../src/bin/phys.spat/indvi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gccgcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


