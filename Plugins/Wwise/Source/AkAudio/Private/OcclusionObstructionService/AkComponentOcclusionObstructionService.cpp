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


/*=============================================================================
IAkOcclusionObstructionService.cpp:
=============================================================================*/

#include "OcclusionObstructionService/AkComponentOcclusionObstructionService.h"
#include "OcclusionObstructionService/AkOcclusionObstructionService.h"
#include "AkAudioDevice.h"
#include "AkComponent.h"
#include "Engine/World.h"

void AkComponentOcclusionObstructionService::Init(UAkComponent* in_akComponent, float in_refreshInterval)
{
	_Init(in_akComponent->GetWorld(), in_refreshInterval);
	AssociatedComponent = in_akComponent;
}

void AkComponentOcclusionObstructionService::SetOcclusionObstruction(AkGameObjectID ListenerId, float Value)
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice)
	{
		AkGameObjectID gameObjId = AssociatedComponent->GetAkGameObjectID();
		bool bUsingRooms = AkAudioDevice->UsingSpatialAudioRooms(AssociatedComponent->GetWorld());

		if (bUsingRooms)
		{
			AK::SoundEngine::SetObjectObstructionAndOcclusion(gameObjId, ListenerId, Value, 0.0f);
		}
		else // if (!bUsingRooms)
		{
			AK::SoundEngine::SetObjectObstructionAndOcclusion(gameObjId, ListenerId, 0.0f, Value);
		}
	}
}