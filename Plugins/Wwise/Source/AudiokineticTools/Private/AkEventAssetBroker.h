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

#include "ComponentAssetBroker.h"

#include "AkAudioEvent.h"

//////////////////////////////////////////////////////////////////////////
// FAkEventAssetBroker

class FAkEventAssetBroker : public IComponentAssetBroker
{
public:
	UClass* GetSupportedAssetClass() override
	{
		return UAkAudioEvent::StaticClass();
	}

	virtual bool AssignAssetToComponent(UActorComponent* InComponent, UObject* InAsset) override
	{
		UAkComponent* AkComp = Cast<UAkComponent>(InComponent);
		UAkAudioEvent* AkEvent = Cast<UAkAudioEvent>(InAsset);
		
		if (AkComp && AkEvent)
		{
			AkComp->AkAudioEvent = AkEvent;
			return true;
		}

		return false;
	}

	virtual UObject* GetAssetFromComponent(UActorComponent* InComponent) override
	{
		UAkComponent* AkComp = Cast<UAkComponent>(InComponent);
		
		if (AkComp)
		{
			return AkComp->AkAudioEvent;
		}
		return NULL;
	}
};

