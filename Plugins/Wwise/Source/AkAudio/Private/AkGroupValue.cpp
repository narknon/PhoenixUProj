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

#include "AkGroupValue.h"

#include "AkAudioDevice.h"
#include "AkMediaAsset.h"
#include "Core/Public/Modules/ModuleManager.h"


void UAkGroupValue::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	UE_LOG(LogAkAudio, Verbose, TEXT("UAkGroupValue::Serialize: %s"), *GetName());
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}
	for (auto& entry : MediaDependencies)
	{
		if (auto* media = entry.Get())
		{
			UE_LOG(LogAkAudio, Verbose, TEXT("UAkGroupValue::Serialize: %s: Media dependency %u is there. Its state is %s"), *GetName(), media->Id, *media->GetLoadStateString());
			LoadedMediaDependencies.Add(media);
			if(media->GetLoadState() == UAkMediaAssetData::LoadState::Loading)
			{
				FExternalReadCallback ExternalReadCallback = [this, entry](double RemainingTime)
				{
					return this->ExternalReadCallback(RemainingTime, entry);
				};
				Ar.AttachExternalReadDependency(ExternalReadCallback);
			}
			// Load media data that was waiting for this switch value to be loaded...
			else if (media->GetLoadState() == UAkMediaAssetData::LoadState::Unloaded)
			{
				media->LoadMedia(true);
			}
		}
	}

	if (!FModuleManager::Get().IsModuleLoaded(TEXT("AkAudio")))
	{
		FAkAudioDevice::DelaySwitchValueBroadcast(this);
	}
	else if (FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get())
	{
		AkAudioDevice->BroadcastOnSwitchValueLoaded(this);
	}
}

bool UAkGroupValue::ExternalReadCallback(double RemainingTime, TSoftObjectPtr<UAkMediaAsset> Media)
{
	if (Media && Media.IsValid())
	{
		if (auto* MediaPtr = Media.Get())
		{
			if (!MediaPtr->ExternalReadCallback(RemainingTime))
			{
				return false;
			}
		}
	}
	return true;
}

bool UAkGroupValue::IsReadyForAsyncPostLoad() const
{
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return true;
	}
	for (auto& entry : LoadedMediaDependencies)
	{
		if (entry.IsValid())
		{
			if (!entry->IsReadyForAsyncPostLoad())
			{
				return false;
			}
		}
	}

	return true;
}

void UAkGroupValue::PostLoad()
{
	Super::PostLoad();
	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}
	if (GroupShortID == 0)
	{
		FString GroupName;
		GetName().Split(TEXT("-"), &GroupName, nullptr);
		auto idFromName = FAkAudioDevice::GetIDFromString(GroupName);
		GroupShortID = idFromName;
	}
}

void UAkGroupValue::BeginDestroy()
{
	Super::BeginDestroy();

	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}
	for (auto& Entry : LoadedMediaDependencies)
	{
		if (Entry.IsValid(true))
		{
			Entry->UnloadMedia();
		}
	}
	LoadedMediaDependencies.Empty();
}


#if WITH_EDITOR
void UAkGroupValue::Reset(TArray<FAssetData>& InOutAssetsToDelete)
{
	if (MediaDependencies.Num() > 0)
	{
		bChangedDuringReset = true;
	}
	MediaDependencies.Empty();
	Super::Reset(InOutAssetsToDelete);
}
#endif

