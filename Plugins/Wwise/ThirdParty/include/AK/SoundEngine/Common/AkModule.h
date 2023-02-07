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

/// \file
/// Audiokinetic's definitions and factory of overridable Memory Manager module.

#pragma once

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/SoundEngine/Common/AkMemoryMgr.h>

/// \name Audiokinetic Memory Manager's implementation-specific definitions.
//@{

typedef void ( AKSOUNDENGINE_CALL *AkMemInitForThread ) (
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemTermForThread ) (
	);

typedef void* ( AKSOUNDENGINE_CALL *AkMemMalloc ) (
	AkMemPoolId poolId,
	size_t uSize
	);

typedef void* ( AKSOUNDENGINE_CALL *AkMemMalign ) (
	AkMemPoolId poolId,
	size_t uSize,
	AkUInt32 uAlignment
	);

typedef void* ( AKSOUNDENGINE_CALL *AkMemRealloc ) (
	AkMemPoolId poolId,
	void* pAddress,
	size_t uSize
	);


typedef void* ( AKSOUNDENGINE_CALL *AkMemReallocAligned ) (
	AkMemPoolId poolId,
	void* pAddress,
	size_t uSize,
	AkUInt32 uAlignment
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemFree ) (
	AkMemPoolId poolId,
	void* pAddress
	);

typedef size_t ( AKSOUNDENGINE_CALL *AkMemTotalReservedMemorySize ) (
	);

typedef size_t ( AKSOUNDENGINE_CALL *AkMemSizeOfMemory ) (
	AkMemPoolId poolId,
	void* pAddress
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemDebugMalloc ) (
	AkMemPoolId poolId,
	size_t uSize,
	void* pAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemDebugMalign ) (
	AkMemPoolId poolId,
	size_t uSize,
	AkUInt32 uAlignment,
	void* pAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemDebugRealloc ) (
	AkMemPoolId poolId,
	void* pOldAddress,
	size_t uSize,
	void* pNewAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemDebugReallocAligned ) (
	AkMemPoolId poolId,
	void* pOldAddress,
	size_t uSize,
	AkUInt32 uAlignment,
	void* pNewAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

typedef void ( AKSOUNDENGINE_CALL *AkMemDebugFree ) (
	AkMemPoolId poolId,
	void* pAddress
	);

typedef void* ( *AkMemAllocVM ) (
	size_t size,
	size_t* extra
	);

typedef void ( *AkMemFreeVM ) (
	void* address,
	size_t size,
	size_t extra,
	size_t release
	);

/// Initialization settings for the default implementation of the Memory Manager. For more details, see \ref memorymanager_init.
/// \sa AK::MemoryMgr
struct AkMemSettings
{
	/// @name High-level memory allocation hooks. When not NULL, redirect allocations normally forwarded to rpmalloc.
	//@{
	AkMemInitForThread				pfInitForThread;				///< (Optional) Thread-specific allocator initialization hook.
	AkMemTermForThread				pfTermForThread;				///< (Optional) Thread-specific allocator termination hook.
	AkMemMalloc						pfMalloc;						///< (Optional) Memory allocation hook.
	AkMemMalign						pfMalign;						///< (Optional) Memory allocation hook.
	AkMemRealloc					pfRealloc;						///< (Optional) Memory allocation hook.
	AkMemReallocAligned				pfReallocAligned;				///< (Optional) Memory allocation hook.
	AkMemFree						pfFree;							///< (Optional) Memory allocation hook.
	AkMemTotalReservedMemorySize	pfTotalReservedMemorySize;		///< (Optional) Memory allocation statistics hook.
	AkMemSizeOfMemory				pfSizeOfMemory;					///< (Optional) Memory allocation statistics hook.
	//@}

	/// @name Configuration.
	//@{
	AkUInt64						uMemAllocationSizeLimit;		///< When non-zero, limits the total amount of virtual and device memory allocated by AK::MemoryMgr.
	//@}

	/// @name Page allocation hooks, used by rpmalloc. Default to AKPLATFORM::AllocVM et al.
	//@{
	AkMemAllocVM					pfAllocVM;						///< Virtual page allocation hook.
	AkMemFreeVM						pfFreeVM;						///< Virtual page allocation hook.
	AkMemAllocVM					pfAllocDevice;					///< Device page allocation hook.
	AkMemFreeVM						pfFreeDevice;					///< Device page allocation hook.
	AkUInt32						uVMPageSize;					///< Virtual memory page size. Defaults to 0 which means auto-detect.
	AkUInt32						uDevicePageSize;				///< Device memory page size. Defaults to 0 which means auto-detect.
	//@}

	/// @name Memory allocation debugging.
	//@{
	AkMemDebugMalloc				pfDebugMalloc;					///< (Optional) Memory allocation debugging hook. Used for tracking calls to pfMalloc.
	AkMemDebugMalign				pfDebugMalign;					///< (Optional) Memory allocation debugging hook. Used for tracking calls to pfMalign.
	AkMemDebugRealloc				pfDebugRealloc;					///< (Optional) Memory allocation debugging hook. Used for tracking calls to pfRealloc.
	AkMemDebugReallocAligned		pfDebugReallocAligned;			///< (Optional) Memory allocation debugging hook. Used for tracking calls to pfReallocAligned.
	AkMemDebugFree					pfDebugFree;					///< (Optional) Memory allocation debugging hook. Used for tracking calls to pfFree.
	AkUInt32						uMemoryDebugLevel;				///< Default 0 disabled. 1 debug enabled. 2 stomp allocator enabled. 3 stomp allocator and debug enabled. User implementations may use multiple non-zero values to offer different features.
	//@}
};
//@}

namespace AK
{

namespace MemoryMgr
{

/// Initialize the default implementation of the Memory Manager.
/// \sa AK::MemoryMgr
AK_EXTERNAPIFUNC( AKRESULT, Init ) (
	AkMemSettings * in_pSettings        ///< Memory manager initialization settings.
	);

/// Obtain the default initialization settings for the default implementation of the Memory Manager.
AK_EXTERNAPIFUNC( void, GetDefaultSettings ) (
	AkMemSettings & out_pMemSettings	///< Memory manager default initialization settings.
	);

}

}

#if defined AK_WIN || defined AK_LINUX || defined AK_SONY || defined AK_XBOX || defined AK_APPLE
#define AK_CRT_ALLOCATOR
#endif

#ifdef AK_CRT_ALLOCATOR
/// \name C runtime allocator functions for AkMemoryMgr
//@{

namespace AK
{

namespace MemoryMgr
{

AK_EXTERNAPIFUNC( void, AkCrtAllocatorInitForThread )();

AK_EXTERNAPIFUNC( void, AkCrtAllocatorTermForThread )();

AK_EXTERNAPIFUNC( void*, AkCrtAllocatorMalloc )(
	AkMemPoolId poolId,
	size_t uSize
	);

AK_EXTERNAPIFUNC( void*, AkCrtAllocatorMalign )(
	AkMemPoolId poolId,
	size_t uSize,
	AkUInt32 uAlignment
	);

AK_EXTERNAPIFUNC( void*, AkCrtAllocatorRealloc )(
	AkMemPoolId poolId,
	void* pAddress,
	size_t uSize
	);

AK_EXTERNAPIFUNC( void*, AkCrtAllocatorReallocAligned )(
	AkMemPoolId poolId,
	void* pAddress,
	size_t uSize,
	AkUInt32 uAlignment
	);

AK_EXTERNAPIFUNC( void, AkCrtAllocatorFree )(
	AkMemPoolId poolId,
	void* pAddress
	);

AK_EXTERNAPIFUNC( size_t, AkCrtAllocatorTotalReservedMemorySize )();

AK_EXTERNAPIFUNC( size_t, AkCrtAllocatorSizeOfMemory )(
	AkMemPoolId poolID,
	void* pAddress
	);

}

}

//@}
#endif // AK_CRT_ALLOCATOR

/// \name stomp allocator functions for AkMemoryMgr
//@{

namespace AK
{

namespace MemoryMgr
{

AK_EXTERNAPIFUNC( void, AkStompAllocatorInitForThread )();

AK_EXTERNAPIFUNC( void, AkStompAllocatorTermForThread )();

AK_EXTERNAPIFUNC( void*, AkStompAllocatorMalloc )(
	AkMemPoolId poolId,
	size_t uSize
	);

AK_EXTERNAPIFUNC( void*, AkStompAllocatorMalign )(
	AkMemPoolId poolId,
	size_t uSize,
	AkUInt32 uAlignment
	);

AK_EXTERNAPIFUNC( void*, AkStompAllocatorRealloc )(
	AkMemPoolId poolId,
	void* pAddress,
	size_t uSize
	);

AK_EXTERNAPIFUNC( void*, AkStompAllocatorReallocAligned )(
	AkMemPoolId poolId,
	void* pAddress,
	size_t uSize,
	AkUInt32 uAlignment
	);

AK_EXTERNAPIFUNC( void, AkStompAllocatorFree )(
	AkMemPoolId poolId,
	void* pAddress
	);

AK_EXTERNAPIFUNC( size_t, AkStompAllocatorTotalReservedMemorySize )();

AK_EXTERNAPIFUNC( size_t, AkStompAllocatorSizeOfMemory )(
	AkMemPoolId poolID,
	void* pAddress
	);

}

}

namespace AK
{

namespace MemoryMgr
{

/// debug tool hooks AkMemoryMgr

AK_EXTERNAPIFUNC( AKRESULT, AkMemDebugToolInit )();

AK_EXTERNAPIFUNC( void, AkMemDebugToolTerm )();

AK_EXTERNAPIFUNC( void, AkMemDebugToolMalloc ) (
	AkMemPoolId poolId,
	size_t uSize,
	void* pAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

AK_EXTERNAPIFUNC( void, AkMemDebugToolMalign ) (
	AkMemPoolId poolId,
	size_t uSize,
	AkUInt32 uAlignment,
	void* pAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

AK_EXTERNAPIFUNC( void, AkMemDebugToolRealloc ) (
	AkMemPoolId poolId,
	void* pOldAddress,
	size_t uSize,
	void* pNewAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

AK_EXTERNAPIFUNC( void, AkMemDebugToolReallocAligned ) (
	AkMemPoolId poolId,
	void* pOldAddress,
	size_t uSize,
	AkUInt32 uAlignment,
	void* pNewAddress,
	char const* pszFile,
	AkUInt32 uLine
	);

AK_EXTERNAPIFUNC( void, AkMemDebugToolFree ) (
	AkMemPoolId poolId,
	void* pAddress
	);

}

}