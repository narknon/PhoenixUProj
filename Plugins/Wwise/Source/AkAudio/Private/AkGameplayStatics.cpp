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
	AkAudioClasses.cpp:
=============================================================================*/
#include "AkGameplayStatics.h"

#include "AkAmbientSound.h"
#include "AkAudioBank.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkAudioType.h"
#include "AkComponent.h"
#include "IntegrationBehavior/AkIntegrationBehavior.h"
#include "AkMediaAsset.h"
#include "AkRtpc.h"
#include "AkStateValue.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "AkUnrealHelper.h"
#include "Engine/GameEngine.h"
#include "EngineUtils.h"
#include "Misc/ScopeLock.h"
#include "Model.h"
#include "UObject/UObjectIterator.h"
#include "AkAcousticPortal.h"

bool UAkGameplayStatics::m_bSoundEngineRecording = false;
float UAkGameplayStatics::OcclusionScalingFactor = 1.0f;

/*-----------------------------------------------------------------------------
	UAkGameplayStatics.
-----------------------------------------------------------------------------*/

UAkGameplayStatics::UAkGameplayStatics(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Property initialization
}

class UAkComponent * UAkGameplayStatics::GetAkComponent( class USceneComponent* AttachToComponent, bool& ComponentCreated, FName AttachPointName, FVector Location, EAttachLocation::Type LocationType )
{
	if ( AttachToComponent == NULL )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::GetAkComponent: NULL AttachToComponent specified!"));
		return NULL;
	}

	FAkAudioDevice * AkAudioDevice = FAkAudioDevice::Get();
	if( AkAudioDevice )
	{
		return AkAudioDevice->GetAkComponent( AttachToComponent, AttachPointName, &Location, LocationType, ComponentCreated );
	}

	return NULL;
}

bool UAkGameplayStatics::IsEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}

bool UAkGameplayStatics::IsGame(UObject* WorldContextObject)
{
	EWorldType::Type WorldType = EWorldType::None;
	if (WorldContextObject)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
		if(World)
			WorldType = World->WorldType;
	}

	return WorldType == EWorldType::Game || WorldType == EWorldType::GamePreview || WorldType == EWorldType::PIE;
}

int32 UAkGameplayStatics::PostEventAttached(
	  class UAkAudioEvent* in_pAkEvent
	, class AActor* in_pActor
	, FName in_attachPointName
	, bool in_stopWhenAttachedToDestroyed
	, FString EventName
)
{
	if (in_pAkEvent == NULL && EventName.IsEmpty())
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEventAttached: No Event specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	if ( in_pActor == NULL )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEventAttached: NULL Actor specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	AkDeviceAndWorld DeviceAndWorld(in_pActor);
	if (DeviceAndWorld.IsValid())
	{
		AkPlayingID playingID = DeviceAndWorld.AkAudioDevice->PostEvent(GET_AK_EVENT_NAME(in_pAkEvent, EventName), in_pActor, 0, NULL, NULL, in_stopWhenAttachedToDestroyed);
		if (in_pAkEvent && playingID != AK_INVALID_PLAYING_ID)
		{
			in_pAkEvent->PinInGarbageCollector(playingID);
		}
		return playingID;
	}

	return AK_INVALID_PLAYING_ID;
}

int32 UAkGameplayStatics::PostEvent(
	  class UAkAudioEvent* AkEvent
	, class AActor* Actor
	, int32 CallbackMask
	, const FOnAkPostEventCallback& PostEventCallback
	, const TArray<FAkExternalSourceInfo>& ExternalSources
	, bool bStopWhenAttachedToDestroyed
	, FString EventName
)
{
	if (AkEvent == NULL && EventName.IsEmpty())
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEvent: No Event specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	if (Actor == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEvent: NULL Actor specified!"));
		return AK_INVALID_PLAYING_ID;
	}
	UE_LOG(LogScript, VeryVerbose, TEXT("UAkGameplayStatics::PostEvent: Posting Event %s"), *AkEvent->GetName());

	int32 PlayingID = AK_INVALID_PLAYING_ID;
	AkDeviceAndWorld DeviceAndWorld(Actor);
	if (DeviceAndWorld.IsValid())
	{
		AkCallbackType AkCallbackMask = AkCallbackTypeHelpers::GetCallbackMaskFromBlueprintMask(CallbackMask);
		if (ExternalSources.Num() > 0)
		{
			FAkSDKExternalSourceArray SDKExternalSrcInfo(ExternalSources);
			PlayingID = DeviceAndWorld.AkAudioDevice->PostEvent(GET_AK_EVENT_NAME(AkEvent, EventName), Actor, PostEventCallback, AkCallbackMask, bStopWhenAttachedToDestroyed, SDKExternalSrcInfo.ExternalSourceArray);
			if (PlayingID != AK_INVALID_PLAYING_ID)
			{
				for (auto ExtSrc : ExternalSources)
				{
					if (ExtSrc.ExternalSourceAsset)
					{
						ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(GET_AK_EVENT_NAME(AkEvent, EventName)), PlayingID);
						if (!bStopWhenAttachedToDestroyed)
						{
							ExtSrc.ExternalSourceAsset->PinInGarbageCollector(PlayingID);
						}
					}
				}
			}
		}
		else
		{
			PlayingID = DeviceAndWorld.AkAudioDevice->PostEvent(GET_AK_EVENT_NAME(AkEvent, EventName), Actor, PostEventCallback, AkCallbackMask, bStopWhenAttachedToDestroyed);
		}
	}

	if (PlayingID != AK_INVALID_PLAYING_ID && AkEvent)
	{
		AkEvent->PinInGarbageCollector(PlayingID);
	}


	return PlayingID;
}

int32 UAkGameplayStatics::PostEvent(
	class UAkAudioEvent* AkEvent
	, class AActor* Actor
	, int32 CallbackMask
	, const FOnAkPostEventCallback& PostEventCallback
	, bool bStopWhenAttachedToDestroyed
	, FString EventName
)
{
	return PostEvent(AkEvent, Actor, CallbackMask, PostEventCallback, TArray<FAkExternalSourceInfo>(), bStopWhenAttachedToDestroyed, EventName);
}

int32 UAkGameplayStatics::PostAndWaitForEndOfEvent(class UAkAudioEvent* AkEvent,
	class AActor* Actor,
	bool bStopWhenAttachedToDestroyed,
	const TArray<FAkExternalSourceInfo>& ExternalSources,
	FString EventName,
	FLatentActionInfo LatentInfo)
{
	if (AkEvent == NULL && EventName.IsEmpty())
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEvent: No Event specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	if (Actor == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEvent: NULL Actor specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	AkPlayingID PlayingID = AK_INVALID_PLAYING_ID;
	AkDeviceAndWorld DeviceAndWorld(Actor);
	if (DeviceAndWorld.IsValid())
	{
		FLatentActionManager& LatentActionManager = DeviceAndWorld.CurrentWorld->GetLatentActionManager();
		FWaitEndOfEventAction* NewAction = new FWaitEndOfEventAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);

		if (ExternalSources.Num() > 0)
		{
			FAkSDKExternalSourceArray SDKExternalSrcInfo(ExternalSources);
			PlayingID = DeviceAndWorld.AkAudioDevice->PostEventLatentAction(GET_AK_EVENT_NAME(AkEvent, EventName), Actor, bStopWhenAttachedToDestroyed, NewAction, SDKExternalSrcInfo.ExternalSourceArray);
			if (PlayingID != AK_INVALID_PLAYING_ID)
			{
				for (auto ExtSrc : ExternalSources)
				{
					if (ExtSrc.ExternalSourceAsset)
					{
						ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(GET_AK_EVENT_NAME(AkEvent, EventName)), PlayingID);
						if (ExtSrc.ExternalSourceAsset)
						{
							ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(GET_AK_EVENT_NAME(AkEvent, EventName)), PlayingID);
							if (!bStopWhenAttachedToDestroyed)
							{
								ExtSrc.ExternalSourceAsset->PinInGarbageCollector(PlayingID);
							}
						}
					}
				}
			}
		}
		else
		{ 
			PlayingID = DeviceAndWorld.AkAudioDevice->PostEventLatentAction(GET_AK_EVENT_NAME(AkEvent, EventName), Actor, bStopWhenAttachedToDestroyed, NewAction); 
		}

		if (PlayingID == AK_INVALID_PLAYING_ID)
		{
			NewAction->EventFinished = true;
		}
		else if (AkEvent)
		{
			AkEvent->PinInGarbageCollector(PlayingID);
		}
	}

	return PlayingID;
}

void UAkGameplayStatics::PostAndWaitForEndOfEventAsync(class UAkAudioEvent* AkEvent,
	class AActor* Actor,
	int32& PlayingID,
	bool bStopWhenAttachedToDestroyed,
	const TArray<FAkExternalSourceInfo>& ExternalSources,
	FLatentActionInfo LatentInfo
	)
{
	if (!AkEvent)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostAndWaitForEndOfEventAsync: No Event specified!"));
		PlayingID = AK_INVALID_PLAYING_ID;
		return;
	}

	if (!Actor)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostAndWaitForEndOfEventAsync: NULL Actor specified!"));
		PlayingID = AK_INVALID_PLAYING_ID;
		return;
	}

	AkDeviceAndWorld DeviceAndWorld(Actor);
	if (DeviceAndWorld.IsValid())
	{
		FLatentActionManager& LatentActionManager = DeviceAndWorld.CurrentWorld->GetLatentActionManager();
		FWaitEndOfEventAsyncAction* NewAction = LatentActionManager.FindExistingAction<FWaitEndOfEventAsyncAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if (!NewAction)
		{
			NewAction = new FWaitEndOfEventAsyncAction(LatentInfo, &PlayingID, ExternalSources, AkEvent, bStopWhenAttachedToDestroyed);
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);

			if (ExternalSources.Num() > 0)
			{
				TSharedPtr<FAkSDKExternalSourceArray, ESPMode::ThreadSafe> SDKExternalSrcInfo = MakeShared<FAkSDKExternalSourceArray, ESPMode::ThreadSafe>(ExternalSources);		
				NewAction->FuturePlayingID = DeviceAndWorld.AkAudioDevice->PostEventLatentActionAsync(AkEvent, Actor, bStopWhenAttachedToDestroyed, NewAction, SDKExternalSrcInfo);
			}
			else
			{
				NewAction->FuturePlayingID = DeviceAndWorld.AkAudioDevice->PostEventLatentActionAsync(AkEvent, Actor, bStopWhenAttachedToDestroyed, NewAction);
			}
		}
	}
	else
	{
		PlayingID = AK_INVALID_PLAYING_ID;
	}
}

void UAkGameplayStatics::PostEventByName(const FString& EventName, class AActor* in_pActor, bool in_stopWhenAttachedToDestroyed)
{
	PostEvent(NULL, in_pActor, 0, FOnAkPostEventCallback(), TArray<FAkExternalSourceInfo>(), in_stopWhenAttachedToDestroyed, EventName);
}

int32 UAkGameplayStatics::PostEventAtLocation(class UAkAudioEvent* in_pAkEvent, FVector Location, FRotator Orientation, const FString& EventName, UObject* WorldContextObject)
{
	if ( in_pAkEvent == NULL && EventName.IsEmpty() )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostEventAtLocation: No Event specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	if (DeviceAndWorld.IsValid())
	{
		AkPlayingID playingID = DeviceAndWorld.AkAudioDevice->PostEventAtLocation(GET_AK_EVENT_NAME(in_pAkEvent, EventName), Location, Orientation, DeviceAndWorld.CurrentWorld);
		if (in_pAkEvent && playingID != AK_INVALID_PLAYING_ID)
		{
			in_pAkEvent->PinInGarbageCollector(playingID);
		}
		return playingID;
	}

	return AK_INVALID_PLAYING_ID;
}

void UAkGameplayStatics::PostEventAtLocationByName(const FString& EventName, FVector Location, FRotator Orientation, UObject* WorldContextObject)
{
	PostEventAtLocation(NULL, Location, Orientation, EventName, WorldContextObject);
}

UAkComponent* UAkGameplayStatics::SpawnAkComponentAtLocation(UObject* WorldContextObject, class UAkAudioEvent* AkEvent, FVector Location, FRotator Orientation, bool AutoPost, const FString& EventName, bool AutoDestroy /* = true*/)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	if (DeviceAndWorld.IsValid())
	{
		return DeviceAndWorld.AkAudioDevice->SpawnAkComponentAtLocation(AkEvent, Location, Orientation, AutoPost, EventName, AutoDestroy, DeviceAndWorld.CurrentWorld);
	}

	return nullptr;
}

void UAkGameplayStatics::ExecuteActionOnEvent(class UAkAudioEvent* AkEvent, AkActionOnEventType ActionType, class AActor* Actor, int32 TransitionDuration, EAkCurveInterpolation FadeCurve, int32 PlayingID)
{
	if (AkEvent == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ExecuteActionOnEvent: No Event specified!"));
		return;
	}

	if (Actor == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ExecuteActionOnEvent: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->ExecuteActionOnEvent(AkEvent->GetName(), ActionType, Actor, TransitionDuration, FadeCurve, PlayingID);
	}
}

void UAkGameplayStatics::ExecuteActionOnPlayingID(AkActionOnEventType ActionType, int32 PlayingID, int32 TransitionDuration, EAkCurveInterpolation FadeCurve)
{
	if (PlayingID == AK_INVALID_PLAYING_ID)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ExecuteActionOnPlayingID: Invalid Playing ID!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->ExecuteActionOnPlayingID(ActionType, PlayingID, TransitionDuration, FadeCurve);
	}
}

void UAkGameplayStatics::SetRTPCValue(const UAkRtpc* RTPCValue, float Value, int32 InterpolationTimeMs, AActor* Actor, FName RTPC)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (RTPCValue)
		{
			AudioDevice->SetRTPCValue(RTPCValue, Value, InterpolationTimeMs, Actor);
		}
		else if (RTPC.IsValid())
		{
			AudioDevice->SetRTPCValue(*RTPC.ToString(), Value, InterpolationTimeMs, Actor);
		}
	}
}

void UAkGameplayStatics::GetRTPCValue(const UAkRtpc* RTPCValue, int32 PlayingID, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, AActor* Actor, FName RTPC)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AK::SoundEngine::Query::RTPCValue_type RTPCType = (AK::SoundEngine::Query::RTPCValue_type)InputValueType;

		AkGameObjectID IdToGet = AK_INVALID_GAME_OBJECT;
		if (Actor != nullptr)
		{
			UAkComponent * ComponentToGet = AudioDevice->GetAkComponent(Actor->GetRootComponent(), FName(), NULL, EAttachLocation::KeepRelativeOffset);
			IdToGet = ComponentToGet->GetAkGameObjectID();
		}

		if (RTPCValue)
		{
			AudioDevice->GetRTPCValue(RTPCValue, IdToGet, PlayingID, Value, RTPCType);
		}
		else if (RTPC.IsValid())
		{
			AudioDevice->GetRTPCValue(*RTPC.ToString(), IdToGet, PlayingID, Value, RTPCType);
		}

		OutputValueType = (ERTPCValueType)RTPCType;
	}
}

void UAkGameplayStatics::ResetRTPCValue(UAkRtpc const* RTPCValue, int32 InterpolationTimeMs, AActor* Actor, FName RTPC)
{

	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AkGameObjectID IdToGet = AK_INVALID_GAME_OBJECT;
		if (Actor != nullptr)
		{
			UAkComponent* ComponentToGet = AudioDevice->GetAkComponent(Actor->GetRootComponent(), FName(), NULL, EAttachLocation::KeepRelativeOffset);
			IdToGet = ComponentToGet->GetAkGameObjectID();
		}

		if (RTPCValue == NULL && RTPC.IsNone())
		{
			UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ResetRTPCValue: No parameter specified!"));
			return;
		}


		AKRESULT Result = AK_Success;

		if (RTPCValue)
		{
			Result = AudioDevice->ResetRTPCValue(RTPCValue, IdToGet, InterpolationTimeMs);
		}
		else if (RTPC.IsValid())
		{
			Result = AudioDevice->ResetRTPCValue(*RTPC.ToString(), IdToGet, InterpolationTimeMs);
		}
		else
		{
			UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ResetRTPCValue: Could not reset RTPC value, valid RTPC value not provided"));
		}

		if (Result == AK_IDNotFound)
		{
			UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ResetRTPCValue: Could not reset RTPC value, RTPC %s not found"), *RTPC.ToString());
		}
		else if (Result != AK_Success)
		{
			UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::ResetRTPCValue: Could not reset RTPC value!"));
		}
	}
}

void UAkGameplayStatics::SetState(const UAkStateValue* StateValue, FName stateGroup, FName state)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice && stateGroup.IsValid() && state.IsValid() )
	{
		if (StateValue)
		{
			AudioDevice->SetState(StateValue);
		}
		else if (stateGroup.IsValid() && state.IsValid())
		{
			AudioDevice->SetState(*stateGroup.ToString(), *state.ToString());
		}
	}
}

void UAkGameplayStatics::PostTrigger(const UAkTrigger* TriggerValue, AActor* Actor, FName Trigger)
{
	if ( Actor == NULL )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::PostTrigger: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice)
	{
		if (TriggerValue)
		{
			AudioDevice->PostTrigger(TriggerValue, Actor);
		}
		else if (Trigger.IsValid())
		{
			AudioDevice->PostTrigger(*Trigger.ToString(), Actor);
		}
	}
}

void UAkGameplayStatics::SetSwitch(const UAkSwitchValue* SwitchValue, AActor* Actor, FName SwitchGroup, FName SwitchState)
{
	if (Actor == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::SetSwitch: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (SwitchValue)
		{
			AudioDevice->SetSwitch(SwitchValue, Actor);
		}
		else if (SwitchGroup.IsValid() && SwitchState.IsValid())
		{
			AudioDevice->SetSwitch(*SwitchGroup.ToString(), *SwitchState.ToString(), Actor);
		}
	}
}

void UAkGameplayStatics::SetMultiplePositions(UAkComponent* GameObjectAkComponent, TArray<FTransform> Positions,
                                              AkMultiPositionType MultiPositionType /*= AkMultiPositionType::MultiPositionType_MultiDirections*/)
{
	if (GameObjectAkComponent == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::SetMultiplePositions: NULL Component specified!"));
		return;
	}

	FAkAudioDevice * pAudioDevice = FAkAudioDevice::Get();
    if (pAudioDevice)
    {
        pAudioDevice->SetMultiplePositions(GameObjectAkComponent, Positions, MultiPositionType);
    }
}

void UAkGameplayStatics::SetMultipleChannelEmitterPositions(UAkComponent* GameObjectAkComponent,
	TArray<AkChannelConfiguration> ChannelMasks,
	TArray<FTransform> Positions,
	AkMultiPositionType MultiPositionType
)
{
	if (GameObjectAkComponent == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::SetMultipleChannelEmitterPositions: NULL Component specified!"));
		return;
	}

	FAkAudioDevice * pAudioDevice = FAkAudioDevice::Get();
    if (pAudioDevice)
    {
        pAudioDevice->SetMultiplePositions(GameObjectAkComponent, ChannelMasks, Positions, MultiPositionType);
    }
}

void UAkGameplayStatics::SetMultipleChannelMaskEmitterPositions(UAkComponent* GameObjectAkComponent,
	TArray<FAkChannelMask> ChannelMasks,
	TArray<FTransform> Positions,
	AkMultiPositionType MultiPositionType
)
{
	if (GameObjectAkComponent == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::SetMultipleChannelMaskEmitterPositions: NULL Component specified!"));
		return;
	}

	FAkAudioDevice * pAudioDevice = FAkAudioDevice::Get();
	if (pAudioDevice)
	{
		pAudioDevice->SetMultiplePositions(GameObjectAkComponent, ChannelMasks, Positions, MultiPositionType);
	}
}

void UAkGameplayStatics::UseReverbVolumes(bool inUseReverbVolumes, class AActor* Actor )
{
	if ( Actor == NULL )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::UseReverbVolumes: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		UAkComponent * ComponentToSet = AudioDevice->GetAkComponent(Actor->GetRootComponent(), FName(), NULL, EAttachLocation::KeepRelativeOffset);
		if( ComponentToSet != NULL )
		{
			ComponentToSet->UseReverbVolumes(inUseReverbVolumes);
		}
	}
}

void UAkGameplayStatics::UseEarlyReflections(class AActor* Actor,
	class UAkAuxBus* AuxBus,
	int Order,
	float BusSendGain,
	float MaxPathLength,
	bool SpotReflectors,
	const FString& AuxBusName)
{
	// Deprecated
}

void UAkGameplayStatics::SetReflectionsOrder(int Order, bool RefreshPaths)
{
	if (Order > 4 || Order < 0)
	{
		Order = FMath::Clamp(Order, 0, 4);
		UE_LOG(LogAkAudio, Warning, TEXT("UAkGameplayStatics::SetReflectionsOrder: The order value is invalid. It was clamped to %d"), Order);
	}

	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->SetReflectionsOrder(Order, RefreshPaths);
	}
}

void UAkGameplayStatics::SetPortalObstructionAndOcclusion(UAkPortalComponent* PortalComponent, float ObstructionValue, float OcclusionValue)
{
	if (ObstructionValue > 1.f || ObstructionValue < 0.f)
	{
		ObstructionValue = FMath::Clamp(ObstructionValue, 0.f, 1.f);
		UE_LOG(LogAkAudio, Warning, TEXT("UAkGameplayStatics::SetPortalObstructionAndOcclusion: The obstruction value is invalid. It was clamped to %f"), ObstructionValue);
	}

	if (OcclusionValue > 1.f || OcclusionValue < 0.f)
	{
		OcclusionValue = FMath::Clamp(OcclusionValue, 0.f, 1.f);
		UE_LOG(LogAkAudio, Warning, TEXT("UAkGameplayStatics::SetPortalObstructionAndOcclusion: The occlusion value is invalid. It was clamped to %f"), OcclusionValue);
	}

	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->SetPortalObstructionAndOcclusion(PortalComponent, ObstructionValue, OcclusionValue);
	}
}

void UAkGameplayStatics::SetGameObjectToPortalObstruction(UAkComponent* GameObjectAkComponent, UAkPortalComponent* PortalComponent, float ObstructionValue)
{
	if (ObstructionValue > 1.f || ObstructionValue < 0.f)
	{
		ObstructionValue = FMath::Clamp(ObstructionValue, 0.f, 1.f);
		UE_LOG(LogAkAudio, Warning, TEXT("UAkGameplayStatics::SetGameObjectToPortalObstruction: The obstruction value is invalid. It was clamped to %f"), ObstructionValue);
	}

	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->SetGameObjectToPortalObstruction(GameObjectAkComponent, PortalComponent, ObstructionValue);
	}
}

void UAkGameplayStatics::SetPortalToPortalObstruction(UAkPortalComponent* PortalComponent0, UAkPortalComponent* PortalComponent1, float ObstructionValue)
{
	if (ObstructionValue > 1.f || ObstructionValue < 0.f)
	{
		ObstructionValue = FMath::Clamp(ObstructionValue, 0.f, 1.f);
		UE_LOG(LogAkAudio, Warning, TEXT("UAkGameplayStatics::SetGameObjectToPortalObstruction: The obstruction value is invalid. It was clamped to %f"), ObstructionValue);
	}

	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->SetPortalToPortalObstruction(PortalComponent0, PortalComponent1, ObstructionValue);
	}
}

void UAkGameplayStatics::SetOutputBusVolume(float BusVolume, class AActor* Actor)
{
	if (Actor == NULL)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::SetOutputBusVolume: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		UAkComponent * ComponentToSet = AudioDevice->GetAkComponent(Actor->GetRootComponent(), FName(), NULL, EAttachLocation::KeepRelativeOffset);
		if (ComponentToSet != NULL)
		{
			ComponentToSet->SetOutputBusVolume(BusVolume);
		}
	}
}

void UAkGameplayStatics::SetBusConfig(const FString& in_BusName, AkChannelConfiguration ChannelConfiguration)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AkChannelConfig config;
        FAkAudioDevice::GetChannelConfig(ChannelConfiguration, config);
		AudioDevice->SetBusConfig(in_BusName, config);
	}
}

void UAkGameplayStatics::SetPanningRule(PanningRule PanRule)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AkPanningRule AkPanRule = (PanRule == PanningRule::PanningRule_Headphones) ? AkPanningRule_Headphones : AkPanningRule_Speakers;
		AudioDevice->SetPanningRule(AkPanRule);
	}
}

void UAkGameplayStatics::ReplaceMainOutput(const FAkOutputSettings& MainOutputSettings)
{
	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AkOutputSettings OutSettings;
		OutSettings.audioDeviceShareset = FAkAudioDevice::GetIDFromString(MainOutputSettings.AudioDeviceSharesetName);
		OutSettings.idDevice = MainOutputSettings.IdDevice;
		OutSettings.ePanningRule = (MainOutputSettings.PanRule == PanningRule::PanningRule_Headphones) ? AkPanningRule_Headphones : AkPanningRule_Speakers;
		FAkAudioDevice::GetChannelConfig(MainOutputSettings.ChannelConfig, OutSettings.channelConfig);
		AudioDevice->ReplaceMainOutput(OutSettings);
	}
}

void UAkGameplayStatics::GetSpeakerAngles(TArray<float>& SpeakerAngles, float& HeightAngle, const FString& DeviceShareset)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AkOutputDeviceID DeviceID = DeviceShareset.IsEmpty() ? 0 : AudioDevice->GetOutputID(DeviceShareset);
		AudioDevice->GetSpeakerAngles(SpeakerAngles, HeightAngle, DeviceID);
	}
}

void UAkGameplayStatics::SetSpeakerAngles(const TArray<float>& SpeakerAngles, float HeightAngles, const FString& DeviceShareset)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AkOutputDeviceID DeviceID = DeviceShareset.IsEmpty() ? 0 : AudioDevice->GetOutputID(DeviceShareset);
		AudioDevice->SetSpeakerAngles(SpeakerAngles, HeightAngles, DeviceID);
	}
}

void UAkGameplayStatics::SetOcclusionRefreshInterval(float RefreshInterval, class AActor* Actor )
{
	if ( Actor == NULL )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::SetOcclusionRefreshInterval: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		UAkComponent * ComponentToSet = AudioDevice->GetAkComponent(Actor->GetRootComponent(), FName(), NULL, EAttachLocation::KeepRelativeOffset);
		if( ComponentToSet != NULL )
		{
			ComponentToSet->OcclusionRefreshInterval = RefreshInterval;
		}
	}
}

void UAkGameplayStatics::StopActor(class AActor* Actor)
{
	if ( Actor == NULL )
	{
		UE_LOG(LogScript, Warning, TEXT("UAkGameplayStatics::StopActor: NULL Actor specified!"));
		return;
	}

	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		AudioDevice->StopGameObject(AudioDevice->GetAkComponent(Actor->GetRootComponent(), FName(), NULL, EAttachLocation::KeepRelativeOffset));
	}
}

void UAkGameplayStatics::StopAll()
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		AudioDevice->StopAllSounds();
	}
}

void UAkGameplayStatics::CancelEventCallback(const FOnAkPostEventCallback& PostEventCallback)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->CancelEventCallbackDelegate(PostEventCallback);
	}
}

void UAkGameplayStatics::StartAllAmbientSounds(UObject* WorldContextObject)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	if (DeviceAndWorld.IsValid())
	{
		for (FActorIterator It(DeviceAndWorld.CurrentWorld);It;++It)
		{
			AAkAmbientSound* pAmbientSound = Cast<AAkAmbientSound>(*It);
			if (pAmbientSound != NULL)
			{
				UAkComponent* pComponent = pAmbientSound->AkComponent;
				if (pComponent && GWorld->Scene == pComponent->GetScene())
				{
					pAmbientSound->StartPlaying();
				}
			}
		}
	}
}

void UAkGameplayStatics::StopAllAmbientSounds(UObject* WorldContextObject)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	if (DeviceAndWorld.IsValid())
	{
		for (FActorIterator It(DeviceAndWorld.CurrentWorld);It;++It)
		{
			AAkAmbientSound* pAmbientSound = Cast<AAkAmbientSound>(*It);
			if (pAmbientSound != NULL)
			{
				UAkComponent* pComponent = pAmbientSound->AkComponent;
				if (pComponent && GWorld->Scene == pComponent->GetScene())
				{
					pAmbientSound->StopPlaying();
				}
			}
		}
	}
}

void UAkGameplayStatics::ClearBanks()
{
	if (auto* akAudioDevice = FAkAudioDevice::Get())
	{
		akAudioDevice->ClearBanks();
	}
}

void UAkGameplayStatics::LoadBank(UAkAudioBank* bank, const FString& BankName, FLatentActionInfo LatentInfo, UObject* WorldContextObject)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	FLatentActionManager& LatentActionManager = DeviceAndWorld.CurrentWorld->GetLatentActionManager();
	FWaitEndBankAction* NewAction = LatentActionManager.FindExistingAction<FWaitEndBankAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
	if (!NewAction)
	{
		NewAction = new FWaitEndBankAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);
	}

	AkIntegrationBehavior::Get()->AkGameplayStatics_LoadBank(bank, BankName, NewAction);
}

void UAkGameplayStatics::LoadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankLoadedCallback)
{
	AkIntegrationBehavior::Get()->AkGameplayStatics_LoadBankAsync(Bank, BankLoadedCallback);
}

void UAkGameplayStatics::LoadBankByName(const FString& BankName)
{
	AkIntegrationBehavior::Get()->AkGameplayStatics_LoadBankByName(BankName);
}

void UAkGameplayStatics::LoadBanks(const TArray<UAkAudioBank*>& SoundBanks, bool SynchronizeSoundBanks)
{
	AkIntegrationBehavior::Get()->AkGameplayStatics_LoadBanks(SoundBanks, SynchronizeSoundBanks);
}

void UAkGameplayStatics::LoadInitBank()
{
	if (FAkAudioDevice* AudioDevice = FAkAudioDevice::Get())
	{
		AudioDevice->LoadInitBank();
	}
}

void UAkGameplayStatics::UnloadBank(class UAkAudioBank* Bank, const FString& BankName, FLatentActionInfo LatentInfo, UObject* WorldContextObject)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	FLatentActionManager& LatentActionManager = DeviceAndWorld.CurrentWorld->GetLatentActionManager();
	FWaitEndBankAction* NewAction = LatentActionManager.FindExistingAction<FWaitEndBankAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
	if (!NewAction)
	{
		NewAction = new FWaitEndBankAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);
	}

	AkIntegrationBehavior::Get()->AkGameplayStatics_UnloadBank(Bank, BankName, NewAction);
}

void UAkGameplayStatics::UnloadBankAsync(UAkAudioBank* Bank, const FOnAkBankCallback& BankUnloadedCallback)
{
	AkIntegrationBehavior::Get()->AkGameplayStatics_UnloadBankAsync(Bank, BankUnloadedCallback);
}

void UAkGameplayStatics::UnloadBankByName(const FString& BankName)
{
	AkIntegrationBehavior::Get()->AkGameplayStatics_UnloadBankByName(BankName);
}

void UAkGameplayStatics::StartOutputCapture(const FString& Filename)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		FString name = Filename;
		if( !name.EndsWith(".wav") )
		{
			name += ".wav";
		}
		AudioDevice->StartOutputCapture(name);
	} 
}

void UAkGameplayStatics::AddOutputCaptureMarker(const FString& MarkerText)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		AudioDevice->AddOutputCaptureMarker(MarkerText);
	} 
}

void UAkGameplayStatics::StopOutputCapture()
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		AudioDevice->StopOutputCapture();
	}
}

void UAkGameplayStatics::StartProfilerCapture(const FString& Filename)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		FString name = Filename;
		if( !name.EndsWith(".prof") )
		{
			name += ".prof";
		}
		AudioDevice->StartProfilerCapture(name);
	} 
}

void UAkGameplayStatics::StopProfilerCapture()
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if( AudioDevice )
	{
		AudioDevice->StopProfilerCapture();
	}
}

FString UAkGameplayStatics::GetCurrentAudioCulture()
{
	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		return AudioDevice->GetCurrentAudioCulture();
	}

	return FString();
}

TArray<FString> UAkGameplayStatics::GetAvailableAudioCultures()
{
	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		return AudioDevice->GetAvailableAudioCultures();
	}

	return TArray<FString>();
}

void UAkGameplayStatics::SetCurrentAudioCulture(const FString& AudioCulture, FLatentActionInfo LatentInfo, UObject* WorldContextObject)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	FLatentActionManager& LatentActionManager = DeviceAndWorld.CurrentWorld->GetLatentActionManager();
	FSetCurrentAudioCultureAction* NewAction = LatentActionManager.FindExistingAction<FSetCurrentAudioCultureAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
	if (!NewAction)
	{
		NewAction = new FSetCurrentAudioCultureAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);
	}

	if (FAkAudioDevice* AudioDevice = FAkAudioDevice::Get())
	{
		AudioDevice->SetCurrentAudioCultureAsync(AudioCulture, NewAction);
	}
	else
	{
		NewAction->ActionDone = true;
	}
}

void UAkGameplayStatics::SetCurrentAudioCultureAsync(const FString& AudioCulture, const FOnSetCurrentAudioCultureCallback& Completed)
{
	if (FAkAudioDevice* AudioDevice = FAkAudioDevice::Get())
	{
		AudioDevice->SetCurrentAudioCultureAsync(AudioCulture, FOnSetCurrentAudioCultureCompleted::CreateLambda([Completed](bool Succeeded) {
			Completed.ExecuteIfBound(Succeeded);
		}));
	}
}

UObject* UAkGameplayStatics::GetAkAudioTypeUserData(const UAkAudioType* Instance, const UClass* Type)
{
	for (auto entry : Instance->UserData)
	{
		if (entry && entry->GetClass()->IsChildOf(Type))
		{
			return entry;
		}
	}

	return nullptr;
}

UObject* UAkGameplayStatics::GetAkMediaAssetUserData(const UAkMediaAsset* Instance, const UClass* Type)
{
	for (auto entry : Instance->UserData)
	{
		if (entry && entry->GetClass()->IsChildOf(Type))
		{
			return entry;
		}
	}

	return nullptr;
}
