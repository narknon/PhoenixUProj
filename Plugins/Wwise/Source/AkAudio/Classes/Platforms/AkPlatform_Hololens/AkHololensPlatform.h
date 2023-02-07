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

#ifdef PLATFORM_HOLOLENS

#include "Platforms/AkPlatformBase.h"
#include "AkHololensInitializationSettings.h"

#define TCHAR_TO_AK(Text) (const WIDECHAR*)(Text)

using UAkInitializationSettings = UAkHololensInitializationSettings;

struct FAkHololensPlatform : FAkPlatformBase
{
	static const UAkInitializationSettings* GetInitializationSettings()
	{
		return GetDefault<UAkHololensInitializationSettings>();
	}

	static const FString GetPlatformBasePath()
	{
		return FString("Hololens");
	}
};

using FAkPlatform = FAkHololensPlatform;

#endif
