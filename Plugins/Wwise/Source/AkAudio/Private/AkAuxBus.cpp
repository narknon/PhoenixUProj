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

#include "AkAuxBus.h"

UAkAssetData* UAkAuxBus::CreateAssetData(UObject* Parent) const
{
	return NewObject<UAkAssetData>(Parent);
}

#if WITH_EDITOR
UAkAssetData* UAkAuxBus::FindOrAddAssetData(const FString& Platform, const FString& Language)
{
	{
		FScopeLock autoLock(&AssetDataLock);

		//Make sure this asset no can no longer reference aux bus media (which is already referenced by the Init bank)
		if (PlatformAssetData && PlatformAssetData->AssetDataPerPlatform.Contains(Platform))
		{
			if (auto* PlatformData = Cast<UAkAssetDataWithMedia>(PlatformAssetData->AssetDataPerPlatform[Platform]))
			{
				PlatformAssetData->AssetDataPerPlatform.Remove(Platform);
			}
		}
	}

	return UAkAssetBase::FindOrAddAssetData(Platform, Language);
}
#endif