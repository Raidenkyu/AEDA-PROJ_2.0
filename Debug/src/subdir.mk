################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cruise.cpp \
<<<<<<< Updated upstream
../src/extras.cpp \
=======
>>>>>>> Stashed changes
../src/main.cpp 

OBJS += \
./src/cruise.o \
<<<<<<< Updated upstream
./src/extras.o \
=======
>>>>>>> Stashed changes
./src/main.o 

CPP_DEPS += \
./src/cruise.d \
<<<<<<< Updated upstream
./src/extras.d \
=======
>>>>>>> Stashed changes
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


