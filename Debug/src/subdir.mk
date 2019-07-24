################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CFieldsQueue.cpp \
../src/CFormField.cpp \
../src/CNotesApi.cpp \
../src/CReloj.cpp \
../src/creTicketWtoCgd.cpp 

OBJS += \
./src/CFieldsQueue.o \
./src/CFormField.o \
./src/CNotesApi.o \
./src/CReloj.o \
./src/creTicketWtoCgd.o 

CPP_DEPS += \
./src/CFieldsQueue.d \
./src/CFormField.d \
./src/CNotesApi.d \
./src/CReloj.d \
./src/creTicketWtoCgd.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DLINUX -DHANDLE_IS_32BITS -I/opt/ibm/notes -I/home/ptstf093/Documents/notescpp/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


