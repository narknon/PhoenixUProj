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
	AkComponent.cpp:
=============================================================================*/

#include "AkComponent.h"

#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkAuxBus.h"
#include "AkMediaAsset.h"
#include "AkComponentCallbackManager.h"
#include "AkLateReverbComponent.h"
#include "AkRoomComponent.h"
#include "AkGameplayTypes.h"
#include "AkMediaAsset.h"
#include "AkRtpc.h"
#include "AkSettings.h"
#include "AkSpotReflector.h"
#include "AkSwitchValue.h"
#include "AkTrigger.h"
#include "Components/BillboardComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Platforms/AkUEPlatform.h"

#if WITH_EDITOR
#include "LevelEditorViewport.h"
#include "CameraController.h"
#include "Editor.h"
#endif

/*------------------------------------------------------------------------------------
Component Helpers
------------------------------------------------------------------------------------*/
namespace UAkComponentUtils
{
	APlayerController* GetAPlayerController(const UActorComponent* Component)
	{
		const APlayerCameraManager* AsPlayerCameraManager = Cast<APlayerCameraManager>(Component->GetOwner());
		return AsPlayerCameraManager ? AsPlayerCameraManager->GetOwningPlayerController() : nullptr;
	}

	void GetListenerPosition(const UAkComponent* Component, FVector& Location, FVector& Front, FVector& Up)
	{
		APlayerController* pPlayerController = GetAPlayerController(Component);
		if (pPlayerController != nullptr)
		{
			FVector Right;
			pPlayerController->GetAudioListenerPosition(Location, Front, Right);
			Up = FVector::CrossProduct(Front, Right);
			return;
		}

#if WITH_EDITORONLY_DATA
#if UE_4_22_OR_LATER
		auto& Clients = GEditor->GetAllViewportClients();
#else
		auto& Clients = GEditor->AllViewportClients;
#endif
		static FTransform LastKnownEditorTransform;
		for (int i = 0; i < Clients.Num(); i++)
		{
			FEditorViewportClient* ViewportClient = Clients[i];
			UWorld* World = ViewportClient->GetWorld();
			if (ViewportClient->Viewport && ViewportClient->Viewport->HasFocus() && World->AllowAudioPlayback())
			{
				EWorldType::Type WorldType = World->WorldType;
				if (WorldType == EWorldType::Editor || WorldType == EWorldType::PIE)
				{
					LastKnownEditorTransform = FAkAudioDevice::Get()->GetEditorListenerPosition(i);
					Location = LastKnownEditorTransform.GetLocation();
					Front = LastKnownEditorTransform.GetRotation().GetForwardVector();
					Up = LastKnownEditorTransform.GetRotation().GetUpVector();
					return;
				}
				else if (WorldType != EWorldType::Game && WorldType != EWorldType::GamePreview)
				{
					Location = ViewportClient->GetViewLocation();
					Front = ViewportClient->GetViewRotation().Quaternion().GetForwardVector();
					Up = ViewportClient->GetViewRotation().Quaternion().GetUpVector();
					LastKnownEditorTransform.SetLocation(Location);
					LastKnownEditorTransform.SetRotation(ViewportClient->GetViewRotation().Quaternion());
					return;
				}
			}
		}

		Location = LastKnownEditorTransform.GetLocation();
		Front = LastKnownEditorTransform.GetRotation().GetForwardVector();
		Up = LastKnownEditorTransform.GetRotation().GetUpVector();
#endif
	}

	void GetLocationFrontUp(const UAkComponent* Component, FVector& Location, FVector& Front, FVector& Up)
	{
		if (Component->IsDefaultListener)
		{
			GetListenerPosition(Component, Location, Front, Up);
		}
		else
		{
			auto& Transform = Component->GetComponentTransform();
			Location = Transform.GetTranslation();
			Front = Transform.GetUnitAxis(EAxis::X);
			Up = Transform.GetUnitAxis(EAxis::Z);
		}
	}
}

AkReverbFadeControl::AkReverbFadeControl(const UAkLateReverbComponent& LateReverbComponent)
	: AuxBusId(LateReverbComponent.GetAuxBusId())
	, bIsFadingOut(false)
	, FadeControlUniqueId((void*)&LateReverbComponent)
	, CurrentControlValue(0.f)
	, TargetControlValue(LateReverbComponent.SendLevel)
	, FadeRate(LateReverbComponent.FadeRate)
	, Priority(LateReverbComponent.Priority)
{}

void AkReverbFadeControl::UpdateValues(const UAkLateReverbComponent& LateReverbComponent)
{
	AuxBusId = LateReverbComponent.GetAuxBusId();
	TargetControlValue = LateReverbComponent.SendLevel;
	FadeRate = LateReverbComponent.FadeRate;
	Priority = LateReverbComponent.Priority;
}

bool AkReverbFadeControl::Update(float DeltaTime)
{
	if (CurrentControlValue != TargetControlValue || bIsFadingOut)
	{
		// Rate (%/s) * Delta (s) = % for given delta, apply to target.
		const float Increment = DeltaTime * FadeRate * TargetControlValue;
		if (bIsFadingOut)
		{
			CurrentControlValue -= Increment;
			if (CurrentControlValue <= 0.f)
				return false;
		}
		else
			CurrentControlValue = FMath::Min(CurrentControlValue + Increment, TargetControlValue);
	}

	return true;
}

AkAuxSendValue AkReverbFadeControl::ToAkAuxSendValue() const
{
	AkAuxSendValue ret;
	ret.listenerID = AK_INVALID_GAME_OBJECT;
	ret.auxBusID = AuxBusId;
	ret.fControlValue = CurrentControlValue;
	return ret;
}

bool AkReverbFadeControl::Prioritize(const AkReverbFadeControl& A, const AkReverbFadeControl& B)
{
	if (A.bIsFadingOut == B.bIsFadingOut)
	{
		if (A.Priority == B.Priority)
		{
			// Sort by bus id if priority and fade are equal, to ensure comparisons in UAkComponent::NeedToUpdateAuxSends dont lead to continuous aux sends updates, when there are overlapping reverbs.
			return A.AuxBusId < B.AuxBusId;
		}
		return A.Priority > B.Priority;
	}
	// Ensure the fading out buffers are sent to the end of the array.
	return A.bIsFadingOut < B.bIsFadingOut;
}

/*------------------------------------------------------------------------------------
	UAkComponent
------------------------------------------------------------------------------------*/

UAkComponent::UAkComponent(const class FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	// Property initialization

	DrawFirstOrderReflections = false;
	DrawSecondOrderReflections = false;
	DrawHigherOrderReflections = false;
	DrawDiffraction = false;

	EarlyReflectionBusSendGain = 1.f;

 	StopWhenOwnerDestroyed = true;
	bUseReverbVolumes = true;
	OcclusionRefreshInterval = 0.2f;

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_DuringPhysics;
	PrimaryComponentTick.bAllowTickOnDedicatedServer = false;
	bTickInEditor = true;

	bAutoActivate = true;
	bNeverNeedsRenderUpdate = true;
	bWantsOnUpdateTransform = true;

#if WITH_EDITORONLY_DATA
	bVisualizeComponent = true;
#endif

	AttenuationScalingFactor = 1.0f;
	bAutoDestroy = false;
	bUseDefaultListeners = true;

	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings)
	{
		OcclusionCollisionChannel = AkSettings->DefaultOcclusionCollisionChannel;
	}
	else
	{
		OcclusionCollisionChannel = ECollisionChannel::ECC_Visibility;
	}

	outerRadius = 0.0f;
	innerRadius = 0.0f;
}

int32 UAkComponent::PostAssociatedAkEventAndWaitForEnd(const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo)
{
	return PostAkEventAndWaitForEnd(AkAudioEvent, EventName, ExternalSources, LatentInfo);
}

void UAkComponent::PostAssociatedAkEventAndWaitForEndAsync(int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo)
{
	PostAkEventAndWaitForEndAsync(AkAudioEvent, PlayingID, ExternalSources, LatentInfo);
}

int32 UAkComponent::PostAssociatedAkEventAndWaitForEnd(FLatentActionInfo LatentInfo)
{
	return PostAkEventAndWaitForEnd(AkAudioEvent, EventName, TArray<FAkExternalSourceInfo>(), LatentInfo);
}

int32 UAkComponent::PostAkEventByName(const FString& in_EventName)
{
	return PostAkEventByNameWithCallback(in_EventName);
}

AkPlayingID UAkComponent::PostAkEventByNameWithDelegate(const FString& in_EventName, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources)
{
	AkPlayingID playingID = AK_INVALID_PLAYING_ID;

	auto AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (ExternalSources.Num() > 0)
		{
			FAkSDKExternalSourceArray SDKExternalSrcInfo(ExternalSources);
			playingID = AudioDevice->PostEvent(in_EventName, this, PostEventCallback, CallbackMask, SDKExternalSrcInfo.ExternalSourceArray);
			if (playingID != AK_INVALID_PLAYING_ID)
			{
				for (auto ExtSrc : ExternalSources)
				{
					if (ExtSrc.ExternalSourceAsset)
					{
						ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(in_EventName), playingID);
						if (!StopWhenOwnerDestroyed)
						{
							ExtSrc.ExternalSourceAsset->PinInGarbageCollector(playingID);
						}
					}
				}
			}
		}
		else
		{
			playingID = AudioDevice->PostEvent(in_EventName, this, PostEventCallback, CallbackMask);
		}
		if (playingID != AK_INVALID_PLAYING_ID)
			bStarted = true;
	}

	return playingID;
}

AkPlayingID UAkComponent::PostAkEventByNameWithCallback(const FString& in_EventName, AkUInt32 in_uFlags /*= 0*/, AkCallbackFunc in_pfnUserCallback /*= NULL*/, void * in_pUserCookie /*= NULL*/, const TArray<FAkExternalSourceInfo>& ExternalSources /*= TArray<FAkExternalSourceInfo>()*/)
{
	AkPlayingID playingID = AK_INVALID_PLAYING_ID;

	auto AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (ExternalSources.Num() > 0)
		{
			FAkSDKExternalSourceArray SDKExternalSrcInfo(ExternalSources);
			playingID = AudioDevice->PostEvent(in_EventName, this, in_uFlags, in_pfnUserCallback, in_pUserCookie, SDKExternalSrcInfo.ExternalSourceArray);
			if (playingID != AK_INVALID_PLAYING_ID)
			{
				for (auto ExtSrc : ExternalSources)
				{
					if (ExtSrc.ExternalSourceAsset)
					{
						ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(in_EventName), playingID);
						if (!StopWhenOwnerDestroyed)
						{
							ExtSrc.ExternalSourceAsset->PinInGarbageCollector(playingID);
						}
					}
				}
			}
		}
		else
		{
			playingID = AudioDevice->PostEvent(in_EventName, this, in_uFlags, in_pfnUserCallback, in_pUserCookie);
		}
		if (playingID != AK_INVALID_PLAYING_ID)
			bStarted = true;
	}

	return playingID;
}

int32 UAkComponent::PostAkEventAndWaitForEnd(class UAkAudioEvent * AkEvent, const FString& in_EventName, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo)
{
	AkPlayingID PlayingID = AK_INVALID_PLAYING_ID;

	if (AkEvent == NULL && in_EventName.IsEmpty())
	{
		UE_LOG(LogScript, Warning, TEXT("UAkComponent::PostAkEventAndWaitForEnd: No Event specified!"));
		return AK_INVALID_PLAYING_ID;
	}

	auto AudioDevice = FAkAudioDevice::Get();
	auto CurrentWorld = GetWorld();
	if (AudioDevice && CurrentWorld)
	{
		FLatentActionManager& LatentActionManager = CurrentWorld->GetLatentActionManager();
		FWaitEndOfEventAction* NewAction =  new FWaitEndOfEventAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);

		if (ExternalSources.Num() > 0)
		{
			FAkSDKExternalSourceArray SDKExternalSrcInfo(ExternalSources);
			PlayingID = AudioDevice->PostEventLatentAction(GET_AK_EVENT_NAME(AkEvent, in_EventName), this, NewAction, SDKExternalSrcInfo.ExternalSourceArray);
			if (PlayingID != AK_INVALID_PLAYING_ID)
			{
				for (auto ExtSrc : ExternalSources)
				{
					if (ExtSrc.ExternalSourceAsset)
					{
						ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(GET_AK_EVENT_NAME(AkEvent, in_EventName)), PlayingID);
						if (!StopWhenOwnerDestroyed)
						{
							ExtSrc.ExternalSourceAsset->PinInGarbageCollector(PlayingID);
						}
					}
				}
			}
		}
		else
		{
			PlayingID = AudioDevice->PostEventLatentAction(GET_AK_EVENT_NAME(AkEvent, in_EventName), this, NewAction);
		}

		if (PlayingID == AK_INVALID_PLAYING_ID)
		{
			NewAction->EventFinished = true;
		}
		else if(AkEvent)
		{
			AkEvent->PinInGarbageCollector(PlayingID);
		}
	}

	return PlayingID;
}

void UAkComponent::PostAkEventAndWaitForEndAsync(UAkAudioEvent* AkEvent, int32& PlayingID, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo)
{
	if (!AkEvent)
	{
		UE_LOG(LogScript, Warning, TEXT("UAkComponent::PostAkEventAndWaitForEnd: No Event specified!"));
		PlayingID = AK_INVALID_PLAYING_ID;
		return;
	}

	AkDeviceAndWorld deviceAndWorld(this);
	if (deviceAndWorld.IsValid())
	{
		FLatentActionManager& LatentActionManager = deviceAndWorld.CurrentWorld->GetLatentActionManager();
		FWaitEndOfEventAsyncAction* NewAction = LatentActionManager.FindExistingAction<FWaitEndOfEventAsyncAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		if (!NewAction)
		{
			NewAction = new FWaitEndOfEventAsyncAction(LatentInfo, &PlayingID);
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);

			if (ExternalSources.Num() > 0)
			{
				TSharedPtr<FAkSDKExternalSourceArray, ESPMode::ThreadSafe> SDKExternalSrcInfo = MakeShared<FAkSDKExternalSourceArray, ESPMode::ThreadSafe>(ExternalSources);
				NewAction->FuturePlayingID = deviceAndWorld.AkAudioDevice->PostEventLatentActionAsync(AkEvent, this, NewAction, SDKExternalSrcInfo);
			}
			else
			{
				NewAction->FuturePlayingID = deviceAndWorld.AkAudioDevice->PostEventLatentActionAsync(AkEvent, this, NewAction);
			}
		}
	}
}

AkRoomID UAkComponent::GetSpatialAudioRoom() const
{
	AkRoomID RoomID;
	if (CurrentRoom)
	{
		RoomID = CurrentRoom->GetRoomID();
	}
	return RoomID;
}

void UAkComponent::PostTrigger(const UAkTrigger* TriggerValue, FString Trigger)
{
	if (FAkAudioDevice::Get())
	{
		if (TriggerValue)
		{
			AK::SoundEngine::PostTrigger(TriggerValue->ShortID, GetAkGameObjectID());
		}
		else
		{
			AK::SoundEngine::PostTrigger(TCHAR_TO_AK(*Trigger), GetAkGameObjectID());
		}
	}
}

void UAkComponent::SetSwitch(const UAkSwitchValue* SwitchValue, FString SwitchGroup, FString SwitchState)
{
	if (FAkAudioDevice::Get())
	{
		if (SwitchValue)
		{
			AK::SoundEngine::SetSwitch(SwitchValue->GroupShortID, SwitchValue->ShortID, GetAkGameObjectID());
		}
		else
		{
			uint32 SwitchGroupID = FAkAudioDevice::GetIDFromString(SwitchGroup);
			uint32 SwitchStateID = FAkAudioDevice::GetIDFromString(SwitchState);

			AK::SoundEngine::SetSwitch(SwitchGroupID, SwitchStateID, GetAkGameObjectID());
		}
	}
}

void UAkComponent::SetStopWhenOwnerDestroyed(bool bStopWhenOwnerDestroyed)
{
	StopWhenOwnerDestroyed = bStopWhenOwnerDestroyed;
}

void UAkComponent::SetListeners(const TArray<UAkComponent*>& NewListeners)
{
	auto AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (!bUseDefaultListeners)
		{
			for (auto Listener : Listeners)
			{
				Listener->Emitters.Remove(this);
			}
		}

		bUseDefaultListeners = false;

		Listeners.Reset();
		Listeners.Append(NewListeners);

		for (auto Listener : Listeners)
		{
			Listener->Emitters.Add(this);
		}

		AudioDevice->SetListeners(this, Listeners.Array());
	}
}

void UAkComponent::UseReverbVolumes(bool inUseReverbVolumes)
{
	bUseReverbVolumes = inUseReverbVolumes;
}

void UAkComponent::UseEarlyReflections(
	class UAkAuxBus* AuxBus,
	int Order,
	float BusSendGain,
	float MaxPathLength,
	bool SpotReflectors,
	const FString& AuxBusName)
{
	// Deprecated
}

void UAkComponent::SetEarlyReflectionsAuxBus(const FString& AuxBusName)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->SetEarlyReflectionsAuxBus(this, AuxBusName);
	}
}

void UAkComponent::SetEarlyReflectionsVolume(float SendVolume)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		AudioDevice->SetEarlyReflectionsVolume(this, SendVolume);
	}
}

float UAkComponent::GetAttenuationRadius() const
{
	return AkAudioEvent ? AttenuationScalingFactor * AkAudioEvent->GetMaxAttenuationRadius() : 0.f;
}

void UAkComponent::SetOutputBusVolume(float BusVolume)
{
	FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		for (auto It = Listeners.CreateIterator(); It; ++It)
		{
			AudioDevice->SetGameObjectOutputBusVolume(this, *It, BusVolume);
		}
	}
}

void UAkComponent::OnRegister()
{
	UWorld* CurrentWorld = GetWorld();
	if(!IsRegisteredWithWwise && CurrentWorld->WorldType != EWorldType::Inactive && CurrentWorld->WorldType != EWorldType::None)
		RegisterGameObject(); // Done before parent so that OnUpdateTransform follows registration and updates position correctly.

	ObstructionService.Init(this, OcclusionRefreshInterval);

	// It's possible for OnRegister to be called while the WorldType is inactive.
	// The game object will be registered again later when the WorldType is active.
	if (IsRegisteredWithWwise)
	{
		FAkAudioDevice * AudioDevice = FAkAudioDevice::Get();
		if (AudioDevice)
		{
			if (EarlyReflectionAuxBus)
			{
				AudioDevice->SetEarlyReflectionsAuxBus(this, EarlyReflectionAuxBus->GetName());
			}
			else if (!EarlyReflectionAuxBusName.IsEmpty())
			{
				AudioDevice->SetEarlyReflectionsAuxBus(this, EarlyReflectionAuxBusName);
			}

			AudioDevice->SetEarlyReflectionsVolume(this, EarlyReflectionBusSendGain);
		}
	}

	Super::OnRegister();

#if WITH_EDITORONLY_DATA
	UpdateSpriteTexture();
#endif
}

#if WITH_EDITORONLY_DATA
void UAkComponent::UpdateSpriteTexture()
{
	if (SpriteComponent)
	{
		SpriteComponent->SetSprite(LoadObject<UTexture2D>(NULL, TEXT("/Wwise/S_AkComponent.S_AkComponent")));
	}
}
#endif

void UAkComponent::OnUnregister()
{
	// Route OnUnregister event.
	Super::OnUnregister();

	// Don't stop audio and clean up component if owner has been destroyed (default behaviour). This function gets
	// called from AActor::ClearComponents when an actor gets destroyed which is not usually what we want for one-
	// shot sounds.
	AActor* Owner = GetOwner();
	UWorld* CurrentWorld = GetWorld();
	if( !Owner || !CurrentWorld || StopWhenOwnerDestroyed || CurrentWorld->bIsTearingDown || (Owner->GetClass() == APlayerController::StaticClass() && CurrentWorld->WorldType == EWorldType::PIE))
	{
		Stop();
	}
}

void UAkComponent::OnComponentDestroyed( bool bDestroyingHierarchy )
{
	UnregisterGameObject();
	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UAkComponent::ShutdownAfterError( void )
{
	UnregisterGameObject();

	Super::ShutdownAfterError();
}

bool UAkComponent::NeedToUpdateAuxSends(const TArray<AkAuxSendValue>& NewValues)
{
	if (NewValues.Num() != CurrentAuxSendValues.Num())
		return true;

	for (int32 i = 0; i < NewValues.Num(); i++)
	{
		if (NewValues[i].listenerID != CurrentAuxSendValues[i].listenerID ||
			NewValues[i].auxBusID != CurrentAuxSendValues[i].auxBusID ||
			NewValues[i].fControlValue != CurrentAuxSendValues[i].fControlValue)
		{
			return true;
		}
	}

	return false;
}

void UAkComponent::ApplyAkReverbVolumeList(float DeltaTime)
{
	for (int32 Idx = 0; Idx < ReverbFadeControls.Num(); )
	{
		if (!ReverbFadeControls[Idx].Update(DeltaTime))
			ReverbFadeControls.RemoveAt(Idx);
		else
			++Idx;
	}

	if (ReverbFadeControls.Num() > 1)
		ReverbFadeControls.Sort(AkReverbFadeControl::Prioritize);

	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice)
	{
		TArray<AkAuxSendValue> NewAuxSendValues;
		for (int32 Idx = 0; Idx < ReverbFadeControls.Num() && Idx < AkAudioDevice->GetMaxAuxBus(); Idx++)
		{
			AkAuxSendValue* FoundAuxSend = NewAuxSendValues.FindByPredicate([=](const AkAuxSendValue& ItemInArray) { return ItemInArray.auxBusID == ReverbFadeControls[Idx].AuxBusId; });
			if (FoundAuxSend)
			{
				FoundAuxSend->fControlValue += ReverbFadeControls[Idx].ToAkAuxSendValue().fControlValue;
			}
			else
			{
				NewAuxSendValues.Add(ReverbFadeControls[Idx].ToAkAuxSendValue());
			}
		}

		if (NeedToUpdateAuxSends(NewAuxSendValues))
		{
			AkAudioDevice->SetAuxSends(this, NewAuxSendValues);
			CurrentAuxSendValues = NewAuxSendValues;
		}
	}
}

void UAkComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (AK::SoundEngine::IsInitialized())
	{
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		// If we're a listener, update our position here instead of in OnUpdateTransform. 
		// This is because PlayerController->GetAudioListenerPosition caches its value, and it can be out of sync
		if (IsDefaultListener && HasMoved())
			UpdateGameObjectPosition();

		if (AkAudioDevice && AkAudioDevice->WorldSpatialAudioVolumesUpdated(GetWorld()))
		{
			UpdateSpatialAudioRoom(GetComponentLocation());
			// Find and apply all AkReverbVolumes at this location
			if (bUseReverbVolumes && AkAudioDevice->GetMaxAuxBus() > 0)
			{
				UpdateAkLateReverbComponentList(GetComponentLocation());
			}
		}

		if (AkAudioDevice && bUseReverbVolumes && AkAudioDevice->GetMaxAuxBus() > 0)
			ApplyAkReverbVolumeList(DeltaTime);

		ObstructionService.Tick(Listeners, GetPosition(), GetOwner(), GetSpatialAudioRoom(), OcclusionCollisionChannel, DeltaTime, OcclusionRefreshInterval);

		if (!HasActiveEvents() && bAutoDestroy && bStarted)
			DestroyComponent();

#if !UE_BUILD_SHIPPING
		if (DrawFirstOrderReflections || DrawSecondOrderReflections || DrawHigherOrderReflections)
			DebugDrawReflections();
		if (DrawDiffraction)
			DebugDrawDiffraction();
#endif
	}
}

void UAkComponent::BeginPlay()
{
	Super::BeginPlay();
	UpdateGameObjectPosition();

	// If spawned inside AkReverbVolume(s), we do not want the fade in effect to kick in.
	UpdateAkLateReverbComponentList(GetComponentLocation());
	for (auto& ReverbFadeControl : ReverbFadeControls)
		ReverbFadeControl.ForceCurrentToTargetValue();

	SetAttenuationScalingFactor(AttenuationScalingFactor);

	if (EnableSpotReflectors)
		AAkSpotReflector::SetSpotReflectors(this);
}

void UAkComponent::SetAttenuationScalingFactor(float Value)
{
	AttenuationScalingFactor = Value;
	FAkAudioDevice* AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
		AudioDevice->SetAttenuationScalingFactor(this, AttenuationScalingFactor);
}

void UAkComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	// If we're a listener, our position will be updated from Tick instead of here.
	// This is because PlayerController->GetAudioListenerPosition caches its value, and it can be out of sync
	if(!IsDefaultListener)
		UpdateGameObjectPosition();
}

UAkComponent* UAkComponent::GetAkComponent(AkGameObjectID GameObjectID)
{ 
	return GameObjectID == DUMMY_GAMEOBJ ? nullptr : (UAkComponent*)GameObjectID;
}

void UAkComponent::GetAkGameObjectName(FString& Name) const
{
	AActor* parentActor = GetOwner();
	if (parentActor)
		Name = parentActor->GetName() + ".";

	Name += GetName();

	UWorld* CurrentWorld = GetWorld();
	switch (CurrentWorld->WorldType)
	{
	case  EWorldType::Editor:
		Name += "(Editor)";
		break;
	case  EWorldType::EditorPreview:
		Name += "(EditorPreview)";
		break;
	case  EWorldType::GamePreview:
		Name += "(GamePreview)";
		break;
	case  EWorldType::Inactive:
		Name += "(Inactive)";
		break;
	}
}

void UAkComponent::PostRegisterGameObject() {}

void UAkComponent::PostUnregisterGameObject() {}

void UAkComponent::RegisterGameObject()
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if ( AkAudioDevice )
	{
		if ( bUseDefaultListeners )
		{
			const auto& DefaultListeners = AkAudioDevice->GetDefaultListeners();
			Listeners.Empty(DefaultListeners.Num());
			
			for (auto Listener : DefaultListeners)
			{
				Listeners.Add(Listener);
				// NOTE: We do not add this to Listener's emitter list, the list is only for user specified (non-default) emitters.
			}
		}

		AkAudioDevice->RegisterComponent(this);
		IsRegisteredWithWwise = true;

		AkAudioDevice->SetGameObjectRadius(this, outerRadius, innerRadius);
	}

	PostRegisterGameObject();
}

void UAkComponent::UnregisterGameObject()
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice)
	{
		AkAudioDevice->UnregisterComponent(this);
		IsRegisteredWithWwise = false;
	}

	for (auto Listener : Listeners)
		Listener->Emitters.Remove(this);

	for (auto Emitter : Emitters)
		Emitter->Listeners.Remove(this);

	PostUnregisterGameObject();
}

void UAkComponent::UpdateAkLateReverbComponentList( FVector Loc )
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (!AkAudioDevice)
		return;

	TArray<UAkLateReverbComponent*> FoundComponents = AkAudioDevice->FindLateReverbComponentsAtLocation(Loc, GetWorld());

	// Add the new volumes to the current list
	for (const auto& LateReverbComponent : FoundComponents)
	{
		const auto AuxBusId = LateReverbComponent->GetAuxBusId();
		const int32 FoundIdx = ReverbFadeControls.IndexOfByPredicate([=](const AkReverbFadeControl& Candidate)
		{
			return Candidate.FadeControlUniqueId == (void*)LateReverbComponent;
		});

		if (FoundIdx == INDEX_NONE)
		{
			// The volume was not found, add it to the list
			ReverbFadeControls.Add(AkReverbFadeControl(*LateReverbComponent));
		}
		else
		{
			// The volume was found. We still have to check if it is currently fading out, in case we are
			// getting back in a volume we just exited.
			ReverbFadeControls[FoundIdx].bIsFadingOut = false;
			// We need to update the late reverb values in case they have changed on the reverb component.
			ReverbFadeControls[FoundIdx].UpdateValues(*LateReverbComponent);
		}
	}

	// Fade out the current volumes not found in the new list
	for (auto& ReverbFadeControl : ReverbFadeControls)
	{
		const int32 FoundIdx = FoundComponents.IndexOfByPredicate([=](const UAkLateReverbComponent* const Candidate)
		{
			return ReverbFadeControl.FadeControlUniqueId == (void*)Candidate;
		});

		if (FoundIdx == INDEX_NONE)
			ReverbFadeControl.bIsFadingOut = true;
	}
}

FVector UAkComponent::GetPosition() const
{
	return FAkAudioDevice::AKVectorToFVector(CurrentSoundPosition.Position());
}

bool UAkComponent::HasMoved()
{
	FVector Location, Front, Up;
	UAkComponentUtils::GetLocationFrontUp(this, Location, Front, Up);
	return CurrentSoundPosition.Position().X != Location.X || CurrentSoundPosition.Position().Y != Location.Y || CurrentSoundPosition.Position().Z != Location.Z ||
		CurrentSoundPosition.OrientationTop().X != Up.X || CurrentSoundPosition.OrientationTop().Y != Up.Y || CurrentSoundPosition.OrientationTop().Z != Up.Z ||
		CurrentSoundPosition.OrientationFront().X != Front.X || CurrentSoundPosition.OrientationFront().Y != Front.Y || CurrentSoundPosition.OrientationFront().Z != Front.Z;
}

void UAkComponent::UpdateGameObjectPosition()
{
#ifdef _DEBUG
	CheckEmitterListenerConsistancy();
#endif
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (IsActive() && AkAudioDevice)
	{
		if (AllowAudioPlayback())
		{
			AkSoundPosition soundpos;
			FVector Location, Front, Up;
			UAkComponentUtils::GetLocationFrontUp(this, Location, Front, Up);
			FAkAudioDevice::FVectorsToAKTransform(Location, Front, Up, soundpos);

			UpdateSpatialAudioRoom(Location);

			AkAudioDevice->SetPosition(this, soundpos);
			CurrentSoundPosition = soundpos;
		}
		 
		// Find and apply all AkReverbVolumes at this location
		if (bUseReverbVolumes && AkAudioDevice->GetMaxAuxBus() > 0)
		{
			UpdateAkLateReverbComponentList(GetComponentLocation());
		}
	}
}

void UAkComponent::UpdateSpatialAudioRoom(FVector Location)
{
	if (IsRegisteredWithWwise)
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
		{
			TArray<UAkRoomComponent*> RoomComponents = AkAudioDevice->FindRoomComponentsAtLocation(Location, GetWorld());
			if (RoomComponents.Num() == 0)
			{
				if (AkAudioDevice->WorldHasActiveRooms(GetWorld()))
				{
					CurrentRoom = nullptr;
					AkAudioDevice->SetInSpatialAudioRoom(GetAkGameObjectID(), GetSpatialAudioRoom());
				}
			}
			else if (CurrentRoom != RoomComponents[0])
			{
				CurrentRoom = RoomComponents[0];
				AkAudioDevice->SetInSpatialAudioRoom(GetAkGameObjectID(), GetSpatialAudioRoom());
			}
		}
	}
}

const TSet<UAkComponent*>& UAkComponent::GetEmitters()
{
	FAkAudioDevice* Device = FAkAudioDevice::Get();
	if (Device)
	{
		auto DefaultListeners = Device->GetDefaultListeners();
		if (DefaultListeners.Contains(this))
			return Device->GetDefaultEmitters();
		else
			return Emitters;
	}
	return Emitters;
}

void UAkComponent::CheckEmitterListenerConsistancy()
{
	for (auto Emitter : GetEmitters())
	{
		check(Emitter->Listeners.Contains(this));
	}

	for (auto Listener : Listeners)
	{
		check(Listener->GetEmitters().Contains(this));
	}
}

void UAkComponent::_DebugDrawReflections( const AkVector& akEmitterPos, const AkVector& akListenerPos, const AkReflectionPathInfo* paths, AkUInt32 uNumPaths) const
{
	::FlushDebugStrings(GWorld);

	for (AkInt32 idxPath = uNumPaths-1; idxPath >= 0; --idxPath)
	{
		const AkReflectionPathInfo& path = paths[idxPath];

		unsigned int order = path.numReflections;

		if ((DrawFirstOrderReflections && order == 1) ||
			(DrawSecondOrderReflections && order == 2) ||
			(DrawHigherOrderReflections && order > 2))
		{
			FColor colorLight;
			FColor colorMed;
			FColor colorDark;

			switch ((order - 1))
			{
			case 0:
				colorLight = FColor(0x9DEBF3);
				colorMed = FColor(0x318087);
				colorDark = FColor(0x186067);
				break;
			case 1:
				colorLight = FColor(0xFCDBA2);
				colorMed = FColor(0xDEAB4E);
				colorDark = FColor(0xA97B27);
				break;
			case 2:
			default:
				colorLight = FColor(0xFCB1A2);
				colorMed = FColor(0xDE674E);
				colorDark = FColor(0xA93E27);
				break;
			}

			FColor colorLightGrey(75, 75, 75);
			FColor colorMedGrey(50, 50, 50);
			FColor colorDarkGrey(35, 35, 35);

			const int kPathThickness = 5.f;
			const float kRadiusSphere = 25.f;
			const int kNumSphereSegments = 8;

			const FVector emitterPos = FAkAudioDevice::AKVectorToFVector(akEmitterPos);
			FVector listenerPt = FAkAudioDevice::AKVectorToFVector(akListenerPos);

			for (int idxSeg = path.numPathPoints-1; idxSeg >= 0; --idxSeg)
			{
				const FVector reflectionPt = FAkAudioDevice::AKVectorToFVector(path.pathPoint[idxSeg]);
				
				if (idxSeg != path.numPathPoints - 1)
				{
					// Note: Not drawing the first leg of the path from the listener.  Often hard to see because it is typically the camera position.
					::DrawDebugLine(GWorld, listenerPt, reflectionPt, path.isOccluded ? colorLightGrey : colorLight, false, -1.f, (uint8)'\000', kPathThickness / order);

					::DrawDebugSphere(GWorld, reflectionPt, (kRadiusSphere/2) / order, kNumSphereSegments, path.isOccluded ? colorLightGrey : colorLight);
				}
				else
				{
					::DrawDebugSphere(GWorld, reflectionPt, kRadiusSphere / order, kNumSphereSegments, path.isOccluded ? colorMedGrey : colorMed);
				}
				
				// Draw image source point.  Not as useful as I had hoped.
				//const FVector imageSrc = FAkAudioDevice::AKVectorToFVector(path.imageSource);
				//::DrawDebugSphere(GWorld, imageSrc, kRadiusSphere/order, kNumSphereSegments, colorDark);

				listenerPt = reflectionPt;
			}

			if (!path.isOccluded)
			{
				// Finally the last path segment towards the emitter.
				::DrawDebugLine(GWorld, listenerPt, emitterPos, path.isOccluded ? colorLightGrey : colorLight, false, -1.f, (uint8)'\000', kPathThickness / order);
			}
		}
	}
	
}

void UAkComponent::_DebugDrawDiffraction(const AkVector& akEmitterPos, const AkVector& akListenerPos, const AkDiffractionPathInfo* paths, AkUInt32 uNumPaths) const
{
	::FlushDebugStrings(GWorld);

	for (AkInt32 idxPath = uNumPaths - 1; idxPath >= 0; --idxPath)
	{
		const AkDiffractionPathInfo& path = paths[idxPath];
		
		FColor purple(0x492E74);
		FColor green(0x267158);

		if (path.nodeCount > 0)
		{
			const int kPathThickness = 5.f;
			const float kRadiusSphereMax = 35.f;
			const float kRadiusSphereMin = 2.f;

			const FVector emitterPos = FAkAudioDevice::AKVectorToFVector(akEmitterPos);
			const FVector listenerPos = FAkAudioDevice::AKVectorToFVector(akListenerPos);
			FVector prevPt = FAkAudioDevice::AKVectorToFVector(akListenerPos);

			for (int idxSeg = 0; idxSeg < (int)path.nodeCount; ++idxSeg)
			{
				const FVector pt = FAkAudioDevice::AKVectorToFVector(path.nodes[idxSeg]);

				if (idxSeg != 0)
				{
					::DrawDebugLine(GWorld, prevPt, pt, green, false, -1.f, (uint8)'\000', kPathThickness);
				}

				float rad = kRadiusSphereMin + (1.f - path.angles[idxSeg] / PI) * (kRadiusSphereMax - kRadiusSphereMin);
				::DrawDebugSphere(GWorld, pt, rad, 8, path.portals[idxSeg].IsValid() ? green : purple );

				prevPt = pt;
			}

			// Finally the last path segment towards the emitter.
			::DrawDebugLine(GWorld, prevPt, emitterPos, green, false, -1.f, (uint8)'\000', kPathThickness);
		}
	}
}

void UAkComponent::DebugDrawReflections() const
{
	enum { kMaxPaths = 64 };
	AkReflectionPathInfo paths[kMaxPaths];
	AkUInt32 uNumPaths = kMaxPaths;
	AkVector listenerPos, emitterPos;
	 
	if (AK::SpatialAudio::QueryReflectionPaths(GetAkGameObjectID(), 0, listenerPos, emitterPos, paths, uNumPaths) == AK_Success && uNumPaths > 0)
		_DebugDrawReflections(emitterPos, listenerPos, paths, uNumPaths);
}

void UAkComponent::DebugDrawDiffraction() const
{
	enum { kMaxPaths = 16 };
	AkDiffractionPathInfo paths[kMaxPaths];
	AkUInt32 uNumPaths = kMaxPaths;

	AkVector listenerPos, emitterPos;

	if (AK::SpatialAudio::QueryDiffractionPaths(GetAkGameObjectID(), 0, listenerPos, emitterPos, paths, uNumPaths) == AK_Success)
	{
		if (uNumPaths > 0)
			_DebugDrawDiffraction(emitterPos, listenerPos, paths, uNumPaths);
	}
}

void UAkComponent::SetGameObjectRadius(float in_outerRadius, float in_innerRadius)
{
	outerRadius = in_outerRadius;
	innerRadius = in_innerRadius;
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice && IsRegisteredWithWwise)
	{
		AkAudioDevice->SetGameObjectRadius(this, outerRadius, innerRadius);
	}
}

#if WITH_EDITOR
void UAkComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		if ((PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UAkComponent, outerRadius) ||
			PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UAkComponent, innerRadius)) &&
			PropertyChangedEvent.ChangeType == EPropertyChangeType::ValueSet)
		{
			if (innerRadius > outerRadius)
				innerRadius = outerRadius;
		}
	}
}
#endif

