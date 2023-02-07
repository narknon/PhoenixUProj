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

#include "AkSpatialAudioHelper.h"

#include "AkUEFeatures.h"
#include "AkSpatialAudioVolume.h"
#include "AkAcousticPortal.h"

namespace AkSpatialAudioHelper
{
	AActor* GetActorFromHitResult(const FHitResult& HitResult)
	{
		AActor* HitActor = nullptr;
#if UE_5_0_OR_LATER
		HitActor = HitResult.HitObjectHandle.FetchActor();
#else
		HitActor = HitResult.Actor.Get();
#endif

		return HitActor;
	}
	
	bool IsAkSpatialAudioActorClass(const AActor* Actor)
	{
		if (Actor == nullptr)
			return false;

		return
			Actor->GetClass() == AAkSpatialAudioVolume::StaticClass() ||
			Actor->GetClass() == AAkAcousticPortal::StaticClass();
	}

#if WITH_EDITOR
	UEditorEngine::FObjectsReplacedEvent* GetObjectReplacedEvent()
	{
#if UE_5_0_OR_LATER
		return &FCoreUObjectDelegates::OnObjectsReplaced;
#else
		if (GEditor)
		{
			return &GEditor->OnObjectsReplaced();
		}

		return nullptr;
#endif
	}
#endif

}
