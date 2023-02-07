/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Version: v2021.1.9  Build: 7847
  Copyright (c) 2006-2022 Audiokinetic Inc.
*******************************************************************************/

// AkTypes.h

/// \file
/// Data type definitions.

#ifndef _AK_DATA_TYPES_PLATFORM_H_
#define _AK_DATA_TYPES_PLATFORM_H_

#include <stdint.h>
#include <limits.h>

#ifndef __cplusplus
	#include <wchar.h> // wchar_t not a built-in type in C
#endif

#define AK_WIN										///< Compiling for Windows

#if defined _M_IX86
	#define AK_CPU_X86								///< Compiling for 32-bit x86 CPU
#elif defined _M_AMD64
	#define AK_CPU_X86_64							///< Compiling for 64-bit x86 CPU
#elif defined _M_ARM
	#define AK_CPU_ARM
	#define AK_CPU_ARM_NEON
#elif defined _M_ARM64
	#define AK_CPU_ARM_64
	#define AK_CPU_ARM_NEON
#endif

#ifdef WINAPI_FAMILY
	#include <winapifamily.h>
	#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
		#define AK_USE_UWP_API
		#define AK_USE_METRO_API // deprecated
		#ifdef __cplusplus_winrt
			#define AK_UWP_CPP_CX // To test for UWP code which uses Microsoft's C++/CX extended language (not all projects do)
		#endif
		#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
			#define AK_WIN_UNIVERSAL_APP
		#endif
	#endif
#endif

#ifndef _WIN32_WINNT
	#ifdef AK_WIN_UNIVERSAL_APP
		#define _WIN32_WINNT 0x0A00 // _WIN32_WINNT_WIN10
	#else
		#define _WIN32_WINNT 0x0602
	#endif
#endif

#define AK_71FROMSTEREOMIXER
#define AK_51FROMSTEREOMIXER

#define AK_SUPPORT_WCHAR						///< Can support wchar
#define AK_OS_WCHAR								///< Use wchar natively

#define AK_SUPPORT_THREAD_LOCAL					///< Support thread_local C++11 keyword with no restrictions

#define AK_RESTRICT		__restrict				///< Refers to the __restrict compilation flag available on some platforms
#define AK_EXPECT_FALSE( _x )	(_x)
#define AkForceInline	__forceinline			///< Force inlining
#define AkNoInline		__declspec(noinline)	///< Disable inlining

#define AK_SIMD_ALIGNMENT	16					///< Platform-specific alignment requirement for SIMD data
#define AK_ALIGN_SIMD( _declaration_ )	AK_ALIGN( _declaration_, AK_SIMD_ALIGNMENT )	///< Platform-specific alignment requirement for SIMD data
#define AK_BUFFER_ALIGNMENT AK_SIMD_ALIGNMENT
#define AK_XAUDIO2_FLAGS 0

#ifdef AK_USE_UWP_API
#define AK_WINRT_DEVICENOTIFICATION
#else
#define AK_DEVICE_CACHE_SUPPORT					///< Supports output device notifications & cache
#endif

#if defined AK_CPU_X86 || defined AK_CPU_X86_64 || defined AK_CPU_ARM_NEON
#define AKSIMD_V4F32_SUPPORTED
#endif

/// These flags defined that a given class of SIMD extensions is available.
/// Note that runtime checks MUST be done before entering code that explicitly utilizes one of these classes
#if defined AK_CPU_X86_64
#define AKSIMD_AVX2_SUPPORTED
#define AKSIMD_AVX_SUPPORTED
#endif

#define AKSOUNDENGINE_CALL __cdecl				///< Calling convention for the Wwise API

#define AK_DLLEXPORT __declspec(dllexport)
#define AK_DLLIMPORT __declspec(dllimport)

typedef uint8_t			AkUInt8;				///< Unsigned 8-bit integer
typedef uint16_t		AkUInt16;				///< Unsigned 16-bit integer
typedef uint32_t		AkUInt32;				///< Unsigned 32-bit integer
typedef uint64_t		AkUInt64;				///< Unsigned 64-bit integer

typedef intptr_t		AkIntPtr;				///< Integer type for pointers
typedef uintptr_t		AkUIntPtr;				///< Integer (unsigned) type for pointers

typedef int8_t			AkInt8;					///< Signed 8-bit integer
typedef int16_t			AkInt16;				///< Signed 16-bit integer
typedef int32_t			AkInt32;				///< Signed 32-bit integer
typedef int64_t			AkInt64;				///< Signed 64-bit integer

typedef wchar_t			AkOSChar;				///< Generic character string

typedef float			AkReal32;				///< 32-bit floating point
typedef double			AkReal64;				///< 64-bit floating point

typedef void *					AkThread;		///< Thread handle
typedef AkUInt32				AkThreadID;		///< Thread ID
typedef unsigned long (__stdcall *AkThreadRoutine)(	void* lpThreadParameter	); ///< Thread routine

typedef void *					AkEvent;		///< Event handle
typedef void *					AkSemaphore;	///< Semaphore handle

typedef void *					AkFileHandle;	///< File handle
typedef wchar_t			AkUtf16;				///< Type for 2 byte chars. Used for communication
												///< with the authoring tool.

typedef void* AkStackTrace[ 64 ];

#define AK_UINT_MAX		UINT_MAX

// For strings.
#define AK_MAX_PATH     260						///< Maximum path length.

typedef AkUInt32			AkFourcc;			///< Riff chunk

/// Create Riff chunk
#define AkmmioFOURCC( ch0, ch1, ch2, ch3 )									    \
		( (AkFourcc)(AkUInt8)(ch0) | ( (AkFourcc)(AkUInt8)(ch1) << 8 ) |		\
		( (AkFourcc)(AkUInt8)(ch2) << 16 ) | ( (AkFourcc)(AkUInt8)(ch3) << 24 ) )

#define AK_BANK_PLATFORM_DATA_ALIGNMENT	(16)	///< Required memory alignment for bank loading by memory address (see LoadBank())

/// Format for printing AkOSChar string using OutputDebugMsgV
/// Corresponds to "%ls" if AK_OS_WCHAR, else "%s".		
/// \remark Usage: AKPLATFORM::OutputDebugMsgV(AKTEXT("Print this string: " AK_OSCHAR_FMT "\n", msg));
#define AK_OSCHAR_FMT "%ls"

/// Macro that takes a string litteral and changes it to an AkOSChar string at compile time
/// \remark This is similar to the TEXT() and _T() macros that can be used to turn string litterals into wchar_t strings
/// \remark Usage: AKTEXT( "Some Text" )
#define AKTEXT(x) L ## x

#endif //_AK_DATA_TYPES_PLATFORM_H_

