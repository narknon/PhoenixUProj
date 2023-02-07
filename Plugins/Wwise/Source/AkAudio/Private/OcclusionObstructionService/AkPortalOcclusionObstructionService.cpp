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
AkOcclusionObstructionService.cpp:
=============================================================================*/

#include "OcclusionObstructionService/AkPortalOcclusionObstructionService.h"
#include "OcclusionObstructionService/AkOcclusionObstructionService.h"
#include "AkAudioDevice.h"
#include "AkAcousticPortal.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Components/PrimitiveComponent.h"


void AkPortalOcclusionObstructionService::Init(UAkPortalComponent* in_portal, float in_refreshInterval)
{
	_Init(in_portal->GetWorld(), in_refreshInterval);
	AssociatedPortal = in_portal;
}
void AkPortalOcclusionObstructionService::SetOcclusionObstruction(AkGameObjectID ListenerId, float Value)
{
	AK::SpatialAudio::SetPortalObstructionAndOcclusion(AssociatedPortal->GetPortalID(), Value, 0.0f);
}
