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
#include "AkHololensPlatformInfo.generated.h"

UCLASS()
class UAkHololensPlatformInfo : public UAkPlatformInfo
{
	GENERATED_BODY()

public:
	UAkHololensPlatformInfo()
	{
		WwisePlatform = "Hololens";

#ifdef AK_HOLOLENS_VS_VERSION
		Architecture = "UWP_ARM64_" AK_HOLOLENS_VS_VERSION;
#else
		Architecture = "UWP_ARM64_vc150";
#endif

		LibraryFileNameFormat = "{0}.dll";
		DebugFileNameFormat = "{0}.pdb";
#if WITH_EDITORONLY_DATA
		UAkPlatformInfo::UnrealNameToPlatformInfo.Add("Hololens", this);
#endif
	}
};
