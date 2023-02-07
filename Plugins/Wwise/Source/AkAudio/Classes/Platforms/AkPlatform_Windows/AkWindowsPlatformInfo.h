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

#pragma once

#include "Platforms/AkPlatformInfo.h"
#include "AkAudioDevice.h"
#include "AkWindowsPlatformInfo.generated.h"

UCLASS()
class UAkWin32PlatformInfo : public UAkPlatformInfo
{
	GENERATED_BODY()

public:
	UAkWin32PlatformInfo()
	{
		WwisePlatform = "Windows";

#ifdef AK_WINDOWS_VS_VERSION
		Architecture = "Win32_" AK_WINDOWS_VS_VERSION;
#else
		Architecture = "Win32_vc150";
#endif

		LibraryFileNameFormat = "{0}.dll";
		DebugFileNameFormat = "{0}.pdb";
#if WITH_EDITORONLY_DATA
		UAkPlatformInfo::UnrealNameToPlatformInfo.Add("Win32", this);
#endif
	}
};

UCLASS()
class UAkWin64PlatformInfo : public UAkPlatformInfo
{
	GENERATED_BODY()

public:
	UAkWin64PlatformInfo()
	{
		WwisePlatform = "Windows";

#ifdef AK_WINDOWS_VS_VERSION
		Architecture = "x64_" AK_WINDOWS_VS_VERSION;
#else
		Architecture = "x64_vc150";
#endif

		LibraryFileNameFormat = "{0}.dll";
		DebugFileNameFormat = "{0}.pdb";

#if WITH_EDITORONLY_DATA
		UAkPlatformInfo::UnrealNameToPlatformInfo.Add("Win64", this);
#endif
	}
};

UCLASS()
class UAkWindowsPlatformInfo : public UAkWin64PlatformInfo
{
	GENERATED_BODY()
	UAkWindowsPlatformInfo()
	{
#if WITH_EDITORONLY_DATA
		UAkPlatformInfo::UnrealNameToPlatformInfo.Add("Windows", this);
#endif
	}
};
