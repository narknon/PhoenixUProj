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

#include "AkInitBank.h"

#if WITH_EDITOR
FOnInitBankChanged UAkInitBank::OnInitBankChanged;
#endif

UAkInitBank::UAkInitBank()
{
	bDelayLoadAssetData = true;
}

UAkAssetData* UAkInitBank::CreateAssetData(UObject* parent) const
{
	return NewObject<UAkInitBankAssetData>(parent);
}

void UAkInitBank::LoadBank()
{
	Super::LoadBank();
	bDelayLoadAssetData = false;
#if WITH_EDITOR
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice && AkAudioDevice->InitBank != this)
	{
		AkAudioDevice->InitBank = this;
		AddToRoot();
		OnInitBankChanged.ExecuteIfBound(this);
	}
#endif
}

#if WITH_EDITOR
void UAkInitBank::Reset(TArray<FAssetData>& InOutAssetsToDelete)
{
	if (AvailableAudioCultures.Num() > 0)
	{
		bChangedDuringReset = true;
	}
	AvailableAudioCultures.Empty();

	// ALWAYS call Super::Reset() last, since it will check if things have been modified
	// before marking as dirty.
	Super::Reset(InOutAssetsToDelete);
}
#endif
