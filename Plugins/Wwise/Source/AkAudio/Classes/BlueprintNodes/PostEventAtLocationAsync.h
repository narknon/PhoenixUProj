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

#include "AkAudioDevice.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "PostEventAtLocationAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostEventAtLocationAsyncOutputPin, int32, PlayingID);

UCLASS()
class AKAUDIO_API UPostEventAtLocationAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FPostEventAtLocationAsyncOutputPin Completed;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static UPostEventAtLocationAsync* PostEventAtLocationAsync(const UObject* WorldContextObject, class UAkAudioEvent* AkEvent, FVector Location, FRotator Orientation);

public:
	void Activate() override;

private:
	UFUNCTION()
	void PollPostEventFuture();

private:
	const UObject* WorldContextObject = nullptr;
	class UAkAudioEvent* AkEvent = nullptr;
	FVector Location;
	FRotator Orientation;
	TFuture<AkPlayingID> playingIDFuture;
	FTimerHandle Timer;
};
