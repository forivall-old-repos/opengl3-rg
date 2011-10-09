################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/ShaderManager.o \
../src/math3d.o 

CPP_SRCS += \
../src/Aggregate.cpp \
../src/Item.cpp \
../src/ShaderManager.cpp \
../src/math3d.cpp 

OBJS += \
./src/Aggregate.o \
./src/Item.o \
./src/ShaderManager.o \
./src/math3d.o 

CPP_DEPS += \
./src/Aggregate.d \
./src/Item.d \
./src/ShaderManager.d \
./src/math3d.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I/usr/include -I../include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


