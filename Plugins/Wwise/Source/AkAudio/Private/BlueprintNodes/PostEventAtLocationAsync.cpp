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

#include "BlueprintNodes/PostEventAtLocationAsync.h"

#include "AkGameplayTypes.h"
#include "Engine/Public/TimerManager.h"

UPostEventAtLocationAsync* UPostEventAtLocationAsync::PostEventAtLocationAsync(const UObject* WorldContextObject, UAkAudioEvent* AkEvent, FVector Location, FRotator Orientation)
{
	UPostEventAtLocationAsync* newNode = NewObject<UPostEventAtLocationAsync>();
	newNode->WorldContextObject = WorldContextObject;
	newNode->AkEvent = AkEvent;
	newNode->Location = Location;
	newNode->Orientation = Orientation;
	return newNode;
}

void UPostEventAtLocationAsync::Activate()
{
	if (AkEvent == nullptr)
	{
		UE_LOG(LogScript, Warning, TEXT("PostEventAtLocationAsync: No Event specified!"));
		Completed.Broadcast(AK_INVALID_PLAYING_ID);
		return;
	}

	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	if (DeviceAndWorld.IsValid())
	{
		playingIDFuture = DeviceAndWorld.AkAudioDevice->PostEventAtLocationAsync(AkEvent, Location, Orientation, DeviceAndWorld.CurrentWorld);

		WorldContextObject->GetWorld()->GetTimerManager().SetTimer(Timer, this, &UPostEventAtLocationAsync::PollPostEventFuture, 1.f / 60.f, true);
	}
	else
	{
		Completed.Broadcast(AK_INVALID_PLAYING_ID);
	}
}

void UPostEventAtLocationAsync::PollPostEventFuture()
{
	if (playingIDFuture.IsReady())
	{
		WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Timer);
		Timer.Invalidate();
		Completed.Broadcast(playingIDFuture.Get());
	}
}