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
#include "PostEventAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostEventAsyncOutputPin, int32, PlayingID);

UCLASS()
class AKAUDIO_API UPostEventAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FPostEventAsyncOutputPin Completed;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|Actor", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", AdvancedDisplay = "3", AutoCreateRefTerm = "PostEventCallback,ExternalSources"))
	static UPostEventAsync* PostEventAsync(const UObject* WorldContextObject, 
			class UAkAudioEvent* AkEvent,
			class AActor* Actor,
			UPARAM(meta = (Bitmask, BitmaskEnum = EAkCallbackType)) int32 CallbackMask,
			const FOnAkPostEventCallback& PostEventCallback,
			const TArray<FAkExternalSourceInfo>& ExternalSources,
			bool bStopWhenAttachedToDestroyed = false
		);

public:
	void Activate() override;

private:
	UFUNCTION()
	void PollPostEventFuture();

private:
	const UObject* WorldContextObject = nullptr;
	UAkAudioEvent* AkEvent = nullptr;
	AActor* Actor = nullptr;
	int32 CallbackMask = 0;
	FOnAkPostEventCallback PostEventCallback;
	TArray<FAkExternalSourceInfo> ExternalSources;
	bool bStopWhenAttachedToDestroyed = false;
	TFuture<AkPlayingID> PlayingIDFuture;
	FTimerHandle Timer;
};
