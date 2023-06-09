#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-USBASP.mk)" "nbproject/Makefile-local-USBASP.mk"
include nbproject/Makefile-local-USBASP.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=USBASP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ecual/ultrasonic_sensor/ultrasonic_sensor.c ecual/push_button/push_button.c ecual/led/led.c ecual/lcd/lcd.c ecual/keypad/keypad.c ecual/buzzer/buzzer.c mcal/timer/timer.c mcal/spi/spi.c mcal/gpio/gpio.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ${OBJECTDIR}/ecual/push_button/push_button.o ${OBJECTDIR}/ecual/led/led.o ${OBJECTDIR}/ecual/lcd/lcd.o ${OBJECTDIR}/ecual/keypad/keypad.o ${OBJECTDIR}/ecual/buzzer/buzzer.o ${OBJECTDIR}/mcal/timer/timer.o ${OBJECTDIR}/mcal/spi/spi.o ${OBJECTDIR}/mcal/gpio/gpio.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d ${OBJECTDIR}/ecual/push_button/push_button.o.d ${OBJECTDIR}/ecual/led/led.o.d ${OBJECTDIR}/ecual/lcd/lcd.o.d ${OBJECTDIR}/ecual/keypad/keypad.o.d ${OBJECTDIR}/ecual/buzzer/buzzer.o.d ${OBJECTDIR}/mcal/timer/timer.o.d ${OBJECTDIR}/mcal/spi/spi.o.d ${OBJECTDIR}/mcal/gpio/gpio.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ${OBJECTDIR}/ecual/push_button/push_button.o ${OBJECTDIR}/ecual/led/led.o ${OBJECTDIR}/ecual/lcd/lcd.o ${OBJECTDIR}/ecual/keypad/keypad.o ${OBJECTDIR}/ecual/buzzer/buzzer.o ${OBJECTDIR}/mcal/timer/timer.o ${OBJECTDIR}/mcal/spi/spi.o ${OBJECTDIR}/mcal/gpio/gpio.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=ecual/ultrasonic_sensor/ultrasonic_sensor.c ecual/push_button/push_button.c ecual/led/led.c ecual/lcd/lcd.c ecual/keypad/keypad.c ecual/buzzer/buzzer.c mcal/timer/timer.c mcal/spi/spi.c mcal/gpio/gpio.c main.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega32"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
_/_=/
ShExtension=.sh
Device=ATmega32
ProjectDir=/home/khaled/projects/avr-drivers/avr-drivers.X
ProjectName=avr-drivers
ConfName=USBASP
ImagePath=dist/USBASP/${IMAGE_TYPE}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ImageDir=dist/USBASP/${IMAGE_TYPE}
ImageName=avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-USBASP.mk ${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [avrdude -c usbasp -p m32 -U flash:w:${ProjectDir}/${ImagePath}]"
	@avrdude -c usbasp -p m32 -U flash:w:${ProjectDir}/${ImagePath}
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o: ecual/ultrasonic_sensor/ultrasonic_sensor.c  .generated_files/flags/USBASP/6afcc026a85ca8313ef771d90cefe1cd724509b8 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/ultrasonic_sensor" 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o  -o ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ecual/ultrasonic_sensor/ultrasonic_sensor.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/push_button/push_button.o: ecual/push_button/push_button.c  .generated_files/flags/USBASP/cf1ee248107dec219f75860a5182a654117381d3 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/push_button" 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o.d 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT ${OBJECTDIR}/ecual/push_button/push_button.o  -o ${OBJECTDIR}/ecual/push_button/push_button.o ecual/push_button/push_button.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/led/led.o: ecual/led/led.c  .generated_files/flags/USBASP/ad889b15bc5647148aa03a92c0703f5162d6264a .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/led" 
	@${RM} ${OBJECTDIR}/ecual/led/led.o.d 
	@${RM} ${OBJECTDIR}/ecual/led/led.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/led/led.o.d" -MT "${OBJECTDIR}/ecual/led/led.o.d" -MT ${OBJECTDIR}/ecual/led/led.o  -o ${OBJECTDIR}/ecual/led/led.o ecual/led/led.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/lcd/lcd.o: ecual/lcd/lcd.c  .generated_files/flags/USBASP/aa1ed45d96eb3cceac6737c4c831bd50b3e0980a .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/lcd" 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT ${OBJECTDIR}/ecual/lcd/lcd.o  -o ${OBJECTDIR}/ecual/lcd/lcd.o ecual/lcd/lcd.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/keypad/keypad.o: ecual/keypad/keypad.c  .generated_files/flags/USBASP/e4c1bf86fa186cff476167a05a4ba17f200a9150 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/keypad" 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o.d 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT ${OBJECTDIR}/ecual/keypad/keypad.o  -o ${OBJECTDIR}/ecual/keypad/keypad.o ecual/keypad/keypad.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/buzzer/buzzer.o: ecual/buzzer/buzzer.c  .generated_files/flags/USBASP/596c21579054885d6551578669c52afa5cde57b4 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/buzzer" 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o.d 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT ${OBJECTDIR}/ecual/buzzer/buzzer.o  -o ${OBJECTDIR}/ecual/buzzer/buzzer.o ecual/buzzer/buzzer.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/timer/timer.o: mcal/timer/timer.c  .generated_files/flags/USBASP/336f895c100831a5609d5228ba23db5e0b3ad66c .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/timer" 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/timer/timer.o.d" -MT "${OBJECTDIR}/mcal/timer/timer.o.d" -MT ${OBJECTDIR}/mcal/timer/timer.o  -o ${OBJECTDIR}/mcal/timer/timer.o mcal/timer/timer.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/spi/spi.o: mcal/spi/spi.c  .generated_files/flags/USBASP/5e8e6472d0fac32f9f2e3cc3b5e6035cb7f18c40 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/spi" 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o.d 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/spi/spi.o.d" -MT "${OBJECTDIR}/mcal/spi/spi.o.d" -MT ${OBJECTDIR}/mcal/spi/spi.o  -o ${OBJECTDIR}/mcal/spi/spi.o mcal/spi/spi.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/gpio/gpio.o: mcal/gpio/gpio.c  .generated_files/flags/USBASP/6d60fbef4d0fc4a2e92512ffa5fdbcbbb5409298 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/gpio" 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o.d 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT ${OBJECTDIR}/mcal/gpio/gpio.o  -o ${OBJECTDIR}/mcal/gpio/gpio.o mcal/gpio/gpio.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/USBASP/d23403ec71a2c57d63311da0d8a6ad48d6852ea2 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o: ecual/ultrasonic_sensor/ultrasonic_sensor.c  .generated_files/flags/USBASP/f46f6ebfbd3794691b7e550fac8c32b615cc7e09 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/ultrasonic_sensor" 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d 
	@${RM} ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT "${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o.d" -MT ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o  -o ${OBJECTDIR}/ecual/ultrasonic_sensor/ultrasonic_sensor.o ecual/ultrasonic_sensor/ultrasonic_sensor.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/push_button/push_button.o: ecual/push_button/push_button.c  .generated_files/flags/USBASP/203af6ebccc2b46aa7ebb6de5490f7348a4fed2f .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/push_button" 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o.d 
	@${RM} ${OBJECTDIR}/ecual/push_button/push_button.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT "${OBJECTDIR}/ecual/push_button/push_button.o.d" -MT ${OBJECTDIR}/ecual/push_button/push_button.o  -o ${OBJECTDIR}/ecual/push_button/push_button.o ecual/push_button/push_button.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/led/led.o: ecual/led/led.c  .generated_files/flags/USBASP/8495ec24152e2b9013fc6930979dacf2a3e32fba .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/led" 
	@${RM} ${OBJECTDIR}/ecual/led/led.o.d 
	@${RM} ${OBJECTDIR}/ecual/led/led.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/led/led.o.d" -MT "${OBJECTDIR}/ecual/led/led.o.d" -MT ${OBJECTDIR}/ecual/led/led.o  -o ${OBJECTDIR}/ecual/led/led.o ecual/led/led.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/lcd/lcd.o: ecual/lcd/lcd.c  .generated_files/flags/USBASP/3f10925e315f72c4f1319a0487495d2f7730f126 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/lcd" 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o.d 
	@${RM} ${OBJECTDIR}/ecual/lcd/lcd.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT "${OBJECTDIR}/ecual/lcd/lcd.o.d" -MT ${OBJECTDIR}/ecual/lcd/lcd.o  -o ${OBJECTDIR}/ecual/lcd/lcd.o ecual/lcd/lcd.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/keypad/keypad.o: ecual/keypad/keypad.c  .generated_files/flags/USBASP/922d6ca8b169bfd61f53126b80856437c694f9e2 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/keypad" 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o.d 
	@${RM} ${OBJECTDIR}/ecual/keypad/keypad.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT "${OBJECTDIR}/ecual/keypad/keypad.o.d" -MT ${OBJECTDIR}/ecual/keypad/keypad.o  -o ${OBJECTDIR}/ecual/keypad/keypad.o ecual/keypad/keypad.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/ecual/buzzer/buzzer.o: ecual/buzzer/buzzer.c  .generated_files/flags/USBASP/502e3780c67722d6b21dd90554d23502a7d9414b .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ecual/buzzer" 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o.d 
	@${RM} ${OBJECTDIR}/ecual/buzzer/buzzer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT "${OBJECTDIR}/ecual/buzzer/buzzer.o.d" -MT ${OBJECTDIR}/ecual/buzzer/buzzer.o  -o ${OBJECTDIR}/ecual/buzzer/buzzer.o ecual/buzzer/buzzer.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/timer/timer.o: mcal/timer/timer.c  .generated_files/flags/USBASP/3bf3c7dc601db81207fcd428801fa9e734979609 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/timer" 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/mcal/timer/timer.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/timer/timer.o.d" -MT "${OBJECTDIR}/mcal/timer/timer.o.d" -MT ${OBJECTDIR}/mcal/timer/timer.o  -o ${OBJECTDIR}/mcal/timer/timer.o mcal/timer/timer.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/spi/spi.o: mcal/spi/spi.c  .generated_files/flags/USBASP/ec1de41ff429c6a2f3f2d46655aa5fc7ef22b2e1 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/spi" 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o.d 
	@${RM} ${OBJECTDIR}/mcal/spi/spi.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/spi/spi.o.d" -MT "${OBJECTDIR}/mcal/spi/spi.o.d" -MT ${OBJECTDIR}/mcal/spi/spi.o  -o ${OBJECTDIR}/mcal/spi/spi.o mcal/spi/spi.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcal/gpio/gpio.o: mcal/gpio/gpio.c  .generated_files/flags/USBASP/a5a3133f431228dc8d3af911b1b228d28e02af91 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcal/gpio" 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o.d 
	@${RM} ${OBJECTDIR}/mcal/gpio/gpio.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT "${OBJECTDIR}/mcal/gpio/gpio.o.d" -MT ${OBJECTDIR}/mcal/gpio/gpio.o  -o ${OBJECTDIR}/mcal/gpio/gpio.o mcal/gpio/gpio.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/USBASP/56b4a8fc171a604250a2d568b1ba6171dff4d983 .generated_files/flags/USBASP/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_USBASP=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/avr-drivers.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
