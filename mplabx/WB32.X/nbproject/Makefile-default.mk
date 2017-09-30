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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.cpp ../src/A24LC512.cpp ../src/AConfigurationBits.cpp ../src/ACore.cpp ../src/ADateTime.cpp ../src/AErrorNotifier.cpp ../src/AI2CDriver.cpp ../src/AInterruptSource.cpp ../src/ALcd.cpp ../src/APCF8563.cpp ../src/APorts.cpp ../src/AString.cpp ../src/ATime.cpp ../src/ATimers.cpp ../src/AUARTDriver.cpp ../src/Ap32mx270f256d.S ../src/AESP8266.cpp ../src/MTemp.cpp ../src/AXbee.cpp ../../qt/MTempClient/MTempCommons.cpp ../src/ADht22.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/1360937237/A24LC512.o ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o ${OBJECTDIR}/_ext/1360937237/ACore.o ${OBJECTDIR}/_ext/1360937237/ADateTime.o ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o ${OBJECTDIR}/_ext/1360937237/ALcd.o ${OBJECTDIR}/_ext/1360937237/APCF8563.o ${OBJECTDIR}/_ext/1360937237/APorts.o ${OBJECTDIR}/_ext/1360937237/AString.o ${OBJECTDIR}/_ext/1360937237/ATime.o ${OBJECTDIR}/_ext/1360937237/ATimers.o ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o ${OBJECTDIR}/_ext/1360937237/AESP8266.o ${OBJECTDIR}/_ext/1360937237/MTemp.o ${OBJECTDIR}/_ext/1360937237/AXbee.o ${OBJECTDIR}/_ext/1470775136/MTempCommons.o ${OBJECTDIR}/_ext/1360937237/ADht22.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/1360937237/A24LC512.o.d ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d ${OBJECTDIR}/_ext/1360937237/ACore.o.d ${OBJECTDIR}/_ext/1360937237/ADateTime.o.d ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d ${OBJECTDIR}/_ext/1360937237/ALcd.o.d ${OBJECTDIR}/_ext/1360937237/APCF8563.o.d ${OBJECTDIR}/_ext/1360937237/APorts.o.d ${OBJECTDIR}/_ext/1360937237/AString.o.d ${OBJECTDIR}/_ext/1360937237/ATime.o.d ${OBJECTDIR}/_ext/1360937237/ATimers.o.d ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d ${OBJECTDIR}/_ext/1360937237/AESP8266.o.d ${OBJECTDIR}/_ext/1360937237/MTemp.o.d ${OBJECTDIR}/_ext/1360937237/AXbee.o.d ${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d ${OBJECTDIR}/_ext/1360937237/ADht22.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/1360937237/A24LC512.o ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o ${OBJECTDIR}/_ext/1360937237/ACore.o ${OBJECTDIR}/_ext/1360937237/ADateTime.o ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o ${OBJECTDIR}/_ext/1360937237/ALcd.o ${OBJECTDIR}/_ext/1360937237/APCF8563.o ${OBJECTDIR}/_ext/1360937237/APorts.o ${OBJECTDIR}/_ext/1360937237/AString.o ${OBJECTDIR}/_ext/1360937237/ATime.o ${OBJECTDIR}/_ext/1360937237/ATimers.o ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o ${OBJECTDIR}/_ext/1360937237/AESP8266.o ${OBJECTDIR}/_ext/1360937237/MTemp.o ${OBJECTDIR}/_ext/1360937237/AXbee.o ${OBJECTDIR}/_ext/1470775136/MTempCommons.o ${OBJECTDIR}/_ext/1360937237/ADht22.o

# Source Files
SOURCEFILES=main.cpp ../src/A24LC512.cpp ../src/AConfigurationBits.cpp ../src/ACore.cpp ../src/ADateTime.cpp ../src/AErrorNotifier.cpp ../src/AI2CDriver.cpp ../src/AInterruptSource.cpp ../src/ALcd.cpp ../src/APCF8563.cpp ../src/APorts.cpp ../src/AString.cpp ../src/ATime.cpp ../src/ATimers.cpp ../src/AUARTDriver.cpp ../src/Ap32mx270f256d.S ../src/AESP8266.cpp ../src/MTemp.cpp ../src/AXbee.cpp ../../qt/MTempClient/MTempCommons.cpp ../src/ADht22.cpp


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

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX270F256D
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o: ../src/Ap32mx270f256d.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.ok ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d" "${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d"  -o ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o ../src/Ap32mx270f256d.S  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-I"../include"
	
else
${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o: ../src/Ap32mx270f256d.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.ok ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d" "${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.d"  -o ${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o ../src/Ap32mx270f256d.S  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1360937237/Ap32mx270f256d.o.asm.d",--gdwarf-2,-I"../include"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/A24LC512.o: ../src/A24LC512.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/A24LC512.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/A24LC512.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/A24LC512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/A24LC512.o.d" -o ${OBJECTDIR}/_ext/1360937237/A24LC512.o ../src/A24LC512.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o: ../src/AConfigurationBits.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d" -o ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o ../src/AConfigurationBits.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ACore.o: ../src/ACore.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ACore.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ACore.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ACore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ACore.o.d" -o ${OBJECTDIR}/_ext/1360937237/ACore.o ../src/ACore.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ADateTime.o: ../src/ADateTime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADateTime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADateTime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ADateTime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ADateTime.o.d" -o ${OBJECTDIR}/_ext/1360937237/ADateTime.o ../src/ADateTime.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o: ../src/AErrorNotifier.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d" -o ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o ../src/AErrorNotifier.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AI2CDriver.o: ../src/AI2CDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d" -o ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o ../src/AI2CDriver.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AInterruptSource.o: ../src/AInterruptSource.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d" -o ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o ../src/AInterruptSource.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ALcd.o: ../src/ALcd.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ALcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ALcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ALcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ALcd.o.d" -o ${OBJECTDIR}/_ext/1360937237/ALcd.o ../src/ALcd.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/APCF8563.o: ../src/APCF8563.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APCF8563.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APCF8563.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/APCF8563.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/APCF8563.o.d" -o ${OBJECTDIR}/_ext/1360937237/APCF8563.o ../src/APCF8563.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/APorts.o: ../src/APorts.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APorts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APorts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/APorts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/APorts.o.d" -o ${OBJECTDIR}/_ext/1360937237/APorts.o ../src/APorts.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AString.o: ../src/AString.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AString.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AString.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AString.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AString.o.d" -o ${OBJECTDIR}/_ext/1360937237/AString.o ../src/AString.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ATime.o: ../src/ATime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ATime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ATime.o.d" -o ${OBJECTDIR}/_ext/1360937237/ATime.o ../src/ATime.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ATimers.o: ../src/ATimers.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATimers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATimers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ATimers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ATimers.o.d" -o ${OBJECTDIR}/_ext/1360937237/ATimers.o ../src/ATimers.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AUARTDriver.o: ../src/AUARTDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d" -o ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o ../src/AUARTDriver.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AESP8266.o: ../src/AESP8266.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AESP8266.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AESP8266.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AESP8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AESP8266.o.d" -o ${OBJECTDIR}/_ext/1360937237/AESP8266.o ../src/AESP8266.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/MTemp.o: ../src/MTemp.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MTemp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MTemp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/MTemp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/MTemp.o.d" -o ${OBJECTDIR}/_ext/1360937237/MTemp.o ../src/MTemp.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AXbee.o: ../src/AXbee.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AXbee.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AXbee.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AXbee.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AXbee.o.d" -o ${OBJECTDIR}/_ext/1360937237/AXbee.o ../src/AXbee.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1470775136/MTempCommons.o: ../../qt/MTempClient/MTempCommons.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1470775136" 
	@${RM} ${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1470775136/MTempCommons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d" -o ${OBJECTDIR}/_ext/1470775136/MTempCommons.o ../../qt/MTempClient/MTempCommons.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ADht22.o: ../src/ADht22.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADht22.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADht22.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ADht22.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ADht22.o.d" -o ${OBJECTDIR}/_ext/1360937237/ADht22.o ../src/ADht22.cpp   $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/main.o: main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/A24LC512.o: ../src/A24LC512.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/A24LC512.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/A24LC512.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/A24LC512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/A24LC512.o.d" -o ${OBJECTDIR}/_ext/1360937237/A24LC512.o ../src/A24LC512.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o: ../src/AConfigurationBits.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o.d" -o ${OBJECTDIR}/_ext/1360937237/AConfigurationBits.o ../src/AConfigurationBits.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ACore.o: ../src/ACore.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ACore.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ACore.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ACore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ACore.o.d" -o ${OBJECTDIR}/_ext/1360937237/ACore.o ../src/ACore.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ADateTime.o: ../src/ADateTime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADateTime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADateTime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ADateTime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ADateTime.o.d" -o ${OBJECTDIR}/_ext/1360937237/ADateTime.o ../src/ADateTime.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o: ../src/AErrorNotifier.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o.d" -o ${OBJECTDIR}/_ext/1360937237/AErrorNotifier.o ../src/AErrorNotifier.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AI2CDriver.o: ../src/AI2CDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AI2CDriver.o.d" -o ${OBJECTDIR}/_ext/1360937237/AI2CDriver.o ../src/AI2CDriver.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AInterruptSource.o: ../src/AInterruptSource.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AInterruptSource.o.d" -o ${OBJECTDIR}/_ext/1360937237/AInterruptSource.o ../src/AInterruptSource.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ALcd.o: ../src/ALcd.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ALcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ALcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ALcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ALcd.o.d" -o ${OBJECTDIR}/_ext/1360937237/ALcd.o ../src/ALcd.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/APCF8563.o: ../src/APCF8563.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APCF8563.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APCF8563.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/APCF8563.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/APCF8563.o.d" -o ${OBJECTDIR}/_ext/1360937237/APCF8563.o ../src/APCF8563.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/APorts.o: ../src/APorts.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APorts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/APorts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/APorts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/APorts.o.d" -o ${OBJECTDIR}/_ext/1360937237/APorts.o ../src/APorts.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AString.o: ../src/AString.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AString.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AString.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AString.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AString.o.d" -o ${OBJECTDIR}/_ext/1360937237/AString.o ../src/AString.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ATime.o: ../src/ATime.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ATime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ATime.o.d" -o ${OBJECTDIR}/_ext/1360937237/ATime.o ../src/ATime.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ATimers.o: ../src/ATimers.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATimers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ATimers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ATimers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ATimers.o.d" -o ${OBJECTDIR}/_ext/1360937237/ATimers.o ../src/ATimers.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AUARTDriver.o: ../src/AUARTDriver.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AUARTDriver.o.d" -o ${OBJECTDIR}/_ext/1360937237/AUARTDriver.o ../src/AUARTDriver.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AESP8266.o: ../src/AESP8266.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AESP8266.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AESP8266.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AESP8266.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AESP8266.o.d" -o ${OBJECTDIR}/_ext/1360937237/AESP8266.o ../src/AESP8266.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/MTemp.o: ../src/MTemp.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MTemp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MTemp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/MTemp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/MTemp.o.d" -o ${OBJECTDIR}/_ext/1360937237/MTemp.o ../src/MTemp.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/AXbee.o: ../src/AXbee.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AXbee.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/AXbee.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/AXbee.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/AXbee.o.d" -o ${OBJECTDIR}/_ext/1360937237/AXbee.o ../src/AXbee.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1470775136/MTempCommons.o: ../../qt/MTempClient/MTempCommons.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1470775136" 
	@${RM} ${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d 
	@${RM} ${OBJECTDIR}/_ext/1470775136/MTempCommons.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1470775136/MTempCommons.o.d" -o ${OBJECTDIR}/_ext/1470775136/MTempCommons.o ../../qt/MTempClient/MTempCommons.cpp   $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/ADht22.o: ../src/ADht22.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADht22.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ADht22.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/ADht22.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../include" -I"../../qt/MTempClient" -MMD -MF "${OBJECTDIR}/_ext/1360937237/ADht22.o.d" -o ${OBJECTDIR}/_ext/1360937237/ADht22.o ../src/ADht22.cpp   $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          $(COMPARISON_BUILD)    -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=16392,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=16392,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/WB32.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
