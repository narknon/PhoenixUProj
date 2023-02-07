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

#if PLATFORM_WINDOWS

#include "Platforms/AkPlatformBase.h"
#include "AkWindowsInitializationSettings.h"

#define TCHAR_TO_AK(Text) (const WIDECHAR*)(Text)

using UAkInitializationSettings = UAkWindowsInitializationSettings;

struct AKAUDIO_API FAkWindowsPlatform : FAkPlatformBase
{
	static const UAkInitializationSettings* GetInitializationSettings()
	{
		return GetDefault<UAkWindowsInitializationSettings>();
	}

	static const FString GetPlatformBasePath()
	{
		return FString("Windows");
	}
};

using FAkPlatform = FAkWindowsPlatform;

#endif
