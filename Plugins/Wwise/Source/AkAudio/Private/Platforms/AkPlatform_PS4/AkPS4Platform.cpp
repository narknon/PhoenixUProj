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

#if defined(PLATFORM_PS4) && PLATFORM_PS4

#include "Platforms/AkPlatform_PS4/AkPS4Platform.h"
#include "Misc/Paths.h"
#include "Interfaces/IPluginManager.h"

FString FAkPS4Platform::GetWwisePluginDirectory()
{
    // Is it not possible to get an absolute path on PS4, so we build it ourselves...
    FString BaseDirectory = TEXT("/app0");
    if (IPluginManager::Get().FindPlugin("Wwise")->GetType() == EPluginType::Engine)
    {
        BaseDirectory /= TEXT("engine");
    }
    else
    {
        BaseDirectory /= FApp::GetProjectName();
    }

    return BaseDirectory / TEXT("Plugins") / TEXT("Wwise");
}

FString FAkPS4Platform::GetDSPPluginsDirectory(const FString& PlatformArchitecture)
{
    return "/app0/prx/";
}

#endif