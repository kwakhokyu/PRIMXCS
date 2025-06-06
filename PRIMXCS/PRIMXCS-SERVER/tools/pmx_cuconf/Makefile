###############################################################################
#                                                                             #
# Theme  : Makefile for 'pmx_cuconf'                                          #
# Author : Park Sungsoo                                                       #
# Date   : 2023. 06. 03                                                       #
#                                                                             #
###############################################################################

include version.info

###############################################################################
#macro definitions

BUILD_DATE=$(shell date +"%Y-%m-%d")
BUILD_TIME=$(shell date +"%H:%M:%S")

VERSION_DEFINE=-DPROJECT_NAME=${PROJECT_NAME} \
			   -DMAJOR_VER=${MAJOR_VER} \
			   -DMINOR1_VER=${MINOR1_VER} \
			   -DMINOR2_VER=${MINOR2_VER} \
			   -DBUILD_NO_VER=${BUILD_NO} \
			   -DADD_TAG=\"${ADD_TAG}\" \
			   -DBIN_STR=\"${PROJECT_NAME}\" \
			   -DBUILD_DATE_STR=\"${BUILD_DATE}\" \
			   -DBUILD_TIME_STR=\"${BUILD_TIME}\"

###############################################################################
# compile mode (DEBUG / RELEASE)
COMPILE_MODE=DEBUG

###############################################################################
#set rule
.SUFFIXES : .cpp .o

###############################################################################
#dynamic linker definition
DYN_LINK= 

###############################################################################
#Compiler Define
CC = g++

###############################################################################
#Complie Option
CFLAGS_64 = -g -Wall -O2 -m64 -O0 -static \
            -D_REENTRANT \
            -DUNIX64 \
			${VERSION_DEFINE}
CFLAGS_32 = -g -Wall -O2 -O0 -static \
            -D_REENTRANT \
			${VERSION_DEFINE}

###############################################################################
#Macro Definition
OS_ARCH:=$(shell getconf LONG_BIT)

###############################################################################
#Directory
SRC_DIR      = ./src/
SRC_BASE_DIR = ../../common/base/src/

###############################################################################
#Include Directory
INC = -I ./include/ \
      -I ../../common/base/include/ \
      -I ../../common/crypto/include/ \
	  -I ../../common/swc/include/ \
	  -I ../../common/markup/include/ \
	  -I ../../common/logger/include

###############################################################################
#Library Path
LIBPATH_64 = -L /usr/lib64 -L ../../lib
LIBPATH_32 = -L /usr/lib 

###############################################################################
#Sub-Path

###############################################################################
#Target Archive

###############################################################################
#Libraries
LIBS = -lssl \
       -lcrypto \
	   -lpmxcrypto \
	   -lpmxswc \
	   -lpmxmarkup \
	   -lpmxlogger

###############################################################################
#Object Files
OBJECT      = $(patsubst ${SRC_DIR}%.cpp, ${SRC_DIR}%.o, $(wildcard ${SRC_DIR}*.cpp))
OBJECT_BASE = ${SRC_BASE_DIR}pmx_conf_mgr.o ${SRC_BASE_DIR}pmx_xml.o

###############################################################################
#Target
TARGET = ${PROJECT_NAME}

###############################################################################
#Make
${TARGET} : ${OBJECT} ${OBJECT_BASE}
	@echo
	@echo ==============================================================================
	@echo Make ${TARGET} [${OS_ARCH} bit mode] ...........
	@echo ==============================================================================
	@echo
ifeq (${OS_ARCH},64)
	${CC} -o ${TARGET} ${OBJECT} ${OBJECT_BASE} ${LIBPATH_64} ${LIBS} ${DYN_LINK}
	mv -f $(TARGET) ./bin
else
	${CC} -o ${TARGET} ${OBJECT} ${OBJECT_BASE} ${LIBPATH_32} ${LIBS} ${DYN_LINK}
	mv -f $(TARGET) ./bin
endif

#Rule
${SRC_DIR}%.o : ${SRC_DIR}%.cpp
ifeq (${OS_ARCH},64)
	${CC} ${INC} ${CFLAGS_64} -o $@ -c $<
else
	${CC} ${INC} ${CFLAGS_32} -o $@ -c $<
endif
${SRC_BASE_DIR}pmx_conf_mgr.o : ${SRC_BASE_DIR}pmx_conf_mgr.cpp
ifeq (${OS_ARCH},64)
	${CC} ${INC} ${CFLAGS_64} -o $@ -c $<
else
	${CC} ${INC} ${CFLAGS_32} -o $@ -c $<
endif
${SRC_BASE_DIR}pmx_xml.o : ${SRC_BASE_DIR}pmx_xml.cpp
ifeq (${OS_ARCH},64)
	${CC} ${INC} ${CFLAGS_64} -o $@ -c $<
else
	${CC} ${INC} ${CFLAGS_32} -o $@ -c $<
endif

###############################################################################
#Clean
clean : 
	@echo
	@echo ==============================================================================
	@echo Clean  Objects and Binaries ...                   
	@echo ==============================================================================
	@echo
	rm -rf ${OBJECT} ${OBJECT_BASE} 

###############################################################################
#All 

print_compile :
	@echo
	@echo -e "\E[1m==============================================================================\E[0m"
	@echo -e "\E[1mMake ${TARGET} [${OS_ARCH} bit, ${COMPILE_MODE} mode] ...\E[0m"
	@echo -e "\E[1m==============================================================================\E[0m"
	@echo

all : clean print_compile ${TARGET} 
	cp -f ./bin/${TARGET} ../../bin/
	cp -f ./bin/${TARGET} /PRIMX/PRIMXSYSTEM/BIN/

###############################################################################

