################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c \
../pruLoader.c \
../testGpioArm.c \
../timeAnalysis.c 

OBJS += \
./main.o \
./pruLoader.o \
./testGpioArm.o \
./timeAnalysis.o 

C_DEPS += \
./main.d \
./pruLoader.d \
./testGpioArm.d \
./timeAnalysis.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"C:\Users\Kim\GitHub\BeagleBone\pruPackage\pru_sw\app_loader\include" -I"C:\Users\Kim\GitHub\BeagleBone\pruPackage\pru_sw\app_loader\interface" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


