################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aggregate.cpp \
../src/CloneItem.cpp \
../src/GeometryRepr.cpp \
../src/GeometryReprImplGlrgShader.cpp \
../src/Guard.cpp \
../src/IndependantItem.cpp \
../src/ShaderInfo.cpp \
../src/ShaderManager.cpp \
../src/ShaderRepr.cpp \
../src/math3d.cpp 

OBJS += \
./src/Aggregate.o \
./src/CloneItem.o \
./src/GeometryRepr.o \
./src/GeometryReprImplGlrgShader.o \
./src/Guard.o \
./src/IndependantItem.o \
./src/ShaderInfo.o \
./src/ShaderManager.o \
./src/ShaderRepr.o \
./src/math3d.o 

CPP_DEPS += \
./src/Aggregate.d \
./src/CloneItem.d \
./src/GeometryRepr.d \
./src/GeometryReprImplGlrgShader.d \
./src/Guard.d \
./src/IndependantItem.d \
./src/ShaderInfo.d \
./src/ShaderManager.d \
./src/ShaderRepr.d \
./src/math3d.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


