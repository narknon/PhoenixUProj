/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

// Defines which features of the Wwise-Unreal integration are supported in which version of UE.

#pragma once

#include "AK/AkWwiseSDKVersion.h"
#include "Runtime/Launch/Resources/Version.h"

#define UE_4_21_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 21) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_4_22_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 22) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_4_23_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 23) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_4_24_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 24) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_4_25_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 25) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_4_26_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 26) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_4_27_OR_LATER ((ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 27) || (ENGINE_MAJOR_VERSION >= 5))
#define UE_5_0_OR_LATER   (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 0)


#if UE_4_22_OR_LATER
#define AK_DEPRECATED UE_DEPRECATED
#else
#define AK_DEPRECATED DEPRECATED
#endif

// Audio Lab / Demo Features

#if (AK_WWISESDK_VERSION_MAJOR >= 2021 && AK_WWISESDK_VERSION_MINOR >=1 && AK_WWISESDK_VERSION_SUBMINOR >=3)
#define AK_OUTPUT_DEVICE_METERING_ENABLED 
#endif

/******** Bulk data defines */
#include "Serialization/BulkData.h"
// Bulk data IO request type changes depending on build settings.
#if !WITH_EDITOR
#if defined(USE_NEW_BULKDATA) && USE_NEW_BULKDATA
using BulkDataIORequest = IBulkDataIORequest;
#else
using BulkDataIORequest = FBulkDataIORequest;
#endif
#else
#if UE_4_25_OR_LATER
using BulkDataIORequest = IBulkDataIORequest;
#else
using BulkDataIORequest = FBulkDataIORequest;
#endif
#endif

// UE 4.25 changed the callback type when a bulk data IO request finishes
#if UE_4_25_OR_LATER
using BulkDataRequestCompletedCallback = FBulkDataIORequestCallBack;
using ReadRequestArgumentType = IBulkDataIORequest;
#else
using BulkDataRequestCompletedCallback = FAsyncFileCallBack;
using ReadRequestArgumentType = IAsyncReadRequest;
#endif

// UE 5.0 typedefs
#include "Containers/Ticker.h"
#if UE_5_0_OR_LATER
using FUnrealFloatVector = FVector3f;
using FUnrealFloatVector2D = FVector2f;
using FUnrealFloatPlane = FPlane4f;
using FTickerDelegateHandle = FTSTicker::FDelegateHandle;
using FCoreTickerType = FTSTicker;
#else
using FUnrealFloatVector = FVector;
using FUnrealFloatVector2D = FVector2D;
using FCoreTickerType = FTicker;
using FUnrealFloatPlane = FPlane;
using FTickerDelegateHandle = FDelegateHandle;
#endif


