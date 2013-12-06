/*****************************************************************************
*                                                                            *
*  OpenNI 2.x Alpha                                                          *
*  Copyright (C) 2012 PrimeSense Ltd.                                        *
*                                                                            *
*  This file is part of OpenNI.                                              *
*                                                                            *
*  Licensed under the Apache License, Version 2.0 (the "License");           *
*  you may not use this file except in compliance with the License.          *
*  You may obtain a copy of the License at                                   *
*                                                                            *
*      http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*****************************************************************************/
#ifndef __CAPTURE_H__
#define __CAPTURE_H__

// --------------------------------
// Includes
// --------------------------------
#include "Device.h"
#include <iostream>
#include <fstream>

// --------------------------------
// Global Variables
// --------------------------------
extern DeviceParameter g_DepthCapturing;
extern DeviceParameter g_ColorCapturing;
extern DeviceParameter g_IRCapturing;


// --------------------------------
// Types - had to move these to the header
// because I'm doing something very silly.
// --------------------------------
typedef enum
{
	NOT_CAPTURING,
	SHOULD_CAPTURE,
	CAPTURING,
} CapturingState;

typedef enum
{
	CAPTURE_DEPTH_STREAM,
	CAPTURE_COLOR_STREAM,
	CAPTURE_IR_STREAM,
	CAPTURE_STREAM_COUNT
} CaptureSourceType;

typedef enum
{
	STREAM_CAPTURE_LOSSLESS = FALSE,
	STREAM_CAPTURE_LOSSY = TRUE,
	STREAM_DONT_CAPTURE,
} StreamCaptureType;

typedef struct StreamCapturingData
{
	StreamCaptureType captureType;
	const char* name;
	bool bRecording;
	openni::VideoFrameRef& (*getFrameFunc)();
	openni::VideoStream&  (*getStream)();	
	bool (*isStreamOn)();
	int startFrame;
} StreamCapturingData;

#define OUTPUT_FNAME_LENGTH 512

typedef struct CapturingData
{
	StreamCapturingData streams[CAPTURE_STREAM_COUNT];
	openni::Recorder recorder;
	char csFileName[OUTPUT_FNAME_LENGTH];
	char sixenseFileName[OUTPUT_FNAME_LENGTH];
	int nStartOn; // time to start, in seconds
	bool bSkipFirstFrame;
	CapturingState State;
	int nCapturedFrameUniqueID;
	char csDisplayMessage[500];
	// Handle for the file we are spitting Sixense Data into
	std::ofstream sixenseFileHandle;
} CapturingData;

// --------------------------------
// Function Declarations
// --------------------------------
void captureInit();
void captureBrowse(int);
void captureStart(int nDelay);
void captureRestart(int);
void captureStop(int);
bool isCapturing();

const CapturingData & getCapturingData();

void captureSetDepthFormat(int format);
void captureSetColorFormat(int format);
void captureSetIRFormat(int format);
const char* captureGetDepthFormatName();
const char* captureGetColorFormatName();
const char* captureGetIRFormatName();

void captureRun();
void outputSixenseFrame();
void captureSingleFrame(int);

void getCaptureMessage(char* pMessage);

#endif //__CAPTURE_H__