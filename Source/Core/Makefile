include ../../ThirdParty/PSCommon/BuildSystem/CommonDefs.mak

BIN_DIR = ../../Bin

INC_DIRS = \
	../../Include \
	../../ThirdParty/PSCommon/XnLib/Include \
	../Drivers/OniFile/Formats \
	../../ThirdParty/LibJPEG


SRC_FILES = \
	*.cpp \
	../Drivers/OniFile/Formats/XnCodec.cpp \
	../Drivers/OniFile/Formats/XnStreamCompression.cpp \
	../../ThirdParty/LibJPEG/*.c \

ifeq ("$(OSTYPE)","Darwin")
	INC_DIRS += /opt/local/include
	LIB_DIRS += /opt/local/lib
	INC_DIRS += /Users/malc/opt/vis/sixense/include
	LDFLAGS += -L/Users/malc/opt/vis/sixense/lib/osx_x64/release_dll
	LDFLAGs += -L/Users/malc/opt/vis/sixense/lib/osx/release_dll
	LDFLAGS += -framework CoreFoundation -framework IOKit
	LDFLAGS += -lsixense -lsixense_utils -lsixense_x64 -lsixense_utils_x64
endif

LIB_NAME = OpenNI2

LIB_DIRS += ../../ThirdParty/PSCommon/XnLib/Bin/$(PLATFORM)-$(CFG)
USED_LIBS = XnLib dl pthread
ifneq ("$(OSTYPE)","Darwin")
        USED_LIBS += rt
endif

DEFINES += OPENNI2_EXPORT

CFLAGS += -Wall

include ../../ThirdParty/PSCommon/BuildSystem/CommonCppMakefile
