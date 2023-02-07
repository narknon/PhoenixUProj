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
AkComponentOcclusionObstructionService.h:
=============================================================================*/

#pragma once

#include "AkInclude.h"
#include "AkAudioDevice.h"
#include "WorldCollision.h"
#include "HAL/ThreadSafeBool.h"
#include "OcclusionObstructionService/AkOcclusionObstructionService.h"

class UAkComponent;

class AkComponentOcclusionObstructionService : public AkOcclusionObstructionService
{
public:
	void Init(UAkComponent* in_akComponent, float in_refreshInterval);

	virtual void SetOcclusionObstruction(AkGameObjectID ListenerID, float Value);

	virtual ~AkComponentOcclusionObstructionService() {}

private:
	UAkComponent * AssociatedComponent;
};