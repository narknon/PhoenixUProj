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
	AkAmbientSound.cpp:
=============================================================================*/

#include "AkAmbientSound.h"
#include "AkAudioDevice.h"
#include "AkComponent.h"
#include "AkAudioEvent.h"

/*------------------------------------------------------------------------------------
	AAkAmbientSound
------------------------------------------------------------------------------------*/

AAkAmbientSound::AAkAmbientSound(const class FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	// Property initialization
	StopWhenOwnerIsDestroyed = true;
	CurrentlyPlaying = false;
	
	static const FName ComponentName = TEXT("AkAudioComponent0");
	AkComponent = ObjectInitializer.CreateDefaultSubobject<UAkComponent>(this, ComponentName);
	
	AkComponent->StopWhenOwnerDestroyed = StopWhenOwnerIsDestroyed;

	RootComponent = AkComponent;

	AkComponent->AttenuationScalingFactor = 1.f;

	//bNoDelete = true;
#if UE_4_24_OR_LATER
	SetHidden(true);
#else
	bHidden = false;
#endif
	AutoPost = false;
}

void AAkAmbientSound::PostLoad()
{
	Super::PostLoad();
#if WITH_EDITOR
	if( AkAudioEvent_DEPRECATED )
	{
		AkComponent->AkAudioEvent = AkAudioEvent_DEPRECATED;
	}
#endif
}

void AAkAmbientSound::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AkComponent->UpdateAkLateReverbComponentList(AkComponent->GetComponentLocation());
}

void AAkAmbientSound::BeginPlay()
{
	Super::BeginPlay();
	if (AutoPost)
	{
		StartAmbientSound();
	}
}


#if WITH_EDITOR
void AAkAmbientSound::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if( AkComponent )
	{
		// Reset audio component.
		if( IsCurrentlyPlaying() )
		{
			StartPlaying();
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AAkAmbientSound::StartAmbientSound()
{
	StartPlaying();
}

void AAkAmbientSound::StopAmbientSound()
{
	StopPlaying();
}

void AAkAmbientSound::StartPlaying()
{
	if( !IsCurrentlyPlaying() )
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
		{
			AkAudioDevice->SetAttenuationScalingFactor(this, AkComponent->AttenuationScalingFactor);
			AkPlayingID pID = AkAudioDevice->PostEvent(GET_AK_EVENT_NAME(AkComponent->AkAudioEvent, AkComponent->EventName), this, 0, NULL, NULL, StopWhenOwnerIsDestroyed);
			if (AkComponent->AkAudioEvent && pID != AK_INVALID_PLAYING_ID)
			{
				AkComponent->AkAudioEvent->PinInGarbageCollector(pID);
			}
		}
	}
}

void AAkAmbientSound::StopPlaying()
{
	if( IsCurrentlyPlaying() )
	{
		// State of CurrentlyPlaying gets updated in UAkComponent::Stop() through the EndOfEvent callback.
		AkComponent->Stop();
	}
}

bool AAkAmbientSound::IsCurrentlyPlaying()
{
	return AkComponent != nullptr && AkComponent->HasActiveEvents();
}
