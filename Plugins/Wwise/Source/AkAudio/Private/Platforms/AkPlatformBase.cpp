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


#include "Platforms/AkPlatformBase.h"
#include "AkAudioDevice.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "AkUnrealHelper.h"

FString FAkPlatformBase::GetWwisePluginDirectory()
{
	return FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("Wwise"))->GetBaseDir());
}

FString FAkPlatformBase::GetDSPPluginsDirectory(const FString& PlatformArchitecture)
{
#if UE_BUILD_SHIPPING
	auto* Configuration = "Release";
#elif UE_BUILD_DEBUG
	auto* Configuration = "Debug";
#else
	auto* Configuration = "Profile";
#endif

	return AkUnrealHelper::GetThirdPartyDirectory() / PlatformArchitecture / Configuration / "bin" / "";
}
