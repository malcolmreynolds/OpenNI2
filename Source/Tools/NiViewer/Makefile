include ../../../ThirdParty/PSCommon/BuildSystem/CommonDefs.mak

BIN_DIR = ../../../Bin

INC_DIRS = \
	../../../Include \
	../../../ThirdParty/PSCommon/XnLib/Include \
	../../../ThirdParty/GL/ \
	/Users/malc/opt/vis/sixense/include

SRC_FILES = \
	Device.cpp  \
	Draw.cpp  \
	Keyboard.cpp  \
	Menu.cpp  \
	MouseInput.cpp  \
	NiViewer.cpp  \
	Statistics.cpp \
	Capture.cpp

ifeq ("$(OSTYPE)","Darwin")
	CFLAGS += -DMACOS -Wno-deprecated
	LDFLAGS += -framework OpenGL -framework GLUT -L/opt/local/lib -lsixense -lsixense_x64 -lsixense_utils -lsixense_utils_x64
else
	CFLAGS += -DUNIX -DGLX_GLXEXT_LEGACY
	USED_LIBS += glut GL
endif

LIB_DIRS  += ../../../ThirdParty/PSCommon/XnLib/Bin/$(PLATFORM)-$(CFG)
USED_LIBS += OpenNI2 XnLib

EXE_NAME = NiViewer

CFLAGS += -Wall

include ../../../ThirdParty/PSCommon/BuildSystem/CommonCppMakefile
