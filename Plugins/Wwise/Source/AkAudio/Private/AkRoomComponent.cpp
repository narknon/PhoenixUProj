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
	AkRoomComponent.cpp:
=============================================================================*/

#include "AkRoomComponent.h"
#include "AkComponentHelpers.h"
#include "AkAcousticPortal.h"
#include "AkAudioDevice.h"
#include "AkGeometryComponent.h"
#include "AkLateReverbComponent.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "Components/BrushComponent.h"
#include "GameFramework/Volume.h"
#include "Model.h"
#include "EngineUtils.h"
#include "AkAudioEvent.h"
#include "AkSettings.h"
#if WITH_EDITOR
#include "AkDrawRoomComponent.h"
#include "AkSpatialAudioHelper.h"
#endif

#define MOVEMENT_STOP_TIMEOUT 0.1f

/*------------------------------------------------------------------------------------
	UAkRoomComponent
------------------------------------------------------------------------------------*/

UAkRoomComponent::UAkRoomComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	Parent = NULL;

	WallOcclusion = 1.0f;

	bEnable = true;
	bUseAttachParentBound = true;
	AutoPost = false;

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	bTickInEditor = true;
#if WITH_EDITOR
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->AddUObject(this, &UAkRoomComponent::HandleObjectsReplaced);
	}
	bWantsOnUpdateTransform = true;
	bWantsInitializeComponent = true;
#else
	bWantsOnUpdateTransform = bDynamic;
#endif
}

FName UAkRoomComponent::GetName() const
{
	return Parent->GetFName();
}

bool UAkRoomComponent::HasEffectOnLocation(const FVector& Location) const
{
	// Need to add a small radius, because on the Mac, EncompassesPoint returns false if
	// Location is exactly equal to the Volume's location
	static float RADIUS = 0.01f;
	return RoomIsActive() && EncompassesPoint(Location, RADIUS);
}

bool UAkRoomComponent::RoomIsActive() const
{ 
	return IsValid(Parent) && bEnable && !IsRunningCommandlet();
}

void UAkRoomComponent::OnRegister()
{
	Super::OnRegister();
	SetRelativeTransform(FTransform::Identity);
	InitializeParent();
	// We want to add / update the room both in BeginPlay and OnRegister. BeginPlay for aux bus and reverb level assignment, OnRegister for portal room assignment and visualization
	if (!IsRegisteredWithWwise)
		AddSpatialAudioRoom();
	else
		UpdateSpatialAudioRoom();

#if WITH_EDITOR
	if (GetDefault<UAkSettings>()->VisualizeRoomsAndPortals)
	{
		InitializeDrawComponent();
	}
#endif
}

void UAkRoomComponent::OnUnregister()
{
	Super::OnUnregister();
	RemoveSpatialAudioRoom();
}

#if WITH_EDITOR
void UAkRoomComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	RegisterVisEnabledCallback();
}

void UAkRoomComponent::InitializeComponent()
{
	Super::InitializeComponent();
	RegisterVisEnabledCallback();
}

void UAkRoomComponent::PostLoad()
{
	Super::PostLoad();
	RegisterVisEnabledCallback();
}


void UAkRoomComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	AkSettings->OnShowRoomsPortalsChanged.Remove(ShowRoomsChangedHandle);
	ShowRoomsChangedHandle.Reset();
	DestroyDrawComponent();
}
#endif // WITH_EDITOR

void UAkRoomComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
#if WITH_EDITOR
	if (bRequiresDeferredBeginPlay)
	{
		BeginPlayInternal();
		bRequiresDeferredBeginPlay = false;
	}
#endif

	// In PIE, only update in tick if bDynamic is true (simulate the behaviour in the no-editor game build).
	bool bUpdate = true;
#if WITH_EDITOR
	if (AkComponentHelpers::IsInGameWorld(this))
		bUpdate = bDynamic;
#endif
	if (bUpdate)
	{
		if (Moving)
		{
			SecondsSinceMovement += DeltaTime;
			if (SecondsSinceMovement >= MOVEMENT_STOP_TIMEOUT)
			{
				FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
				if (AkAudioDevice != nullptr)
				{
					AkAudioDevice->ReindexRoom(this);
					AkAudioDevice->UpdateRoomsForPortals(GetWorld());
				}
				Moving = false;
			}
		}
		if ((bEnable && !IsRegisteredWithWwise) || (!bEnable && IsRegisteredWithWwise))
		{
			FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
			if (AkAudioDevice != nullptr)
			{
				if (IsRegisteredWithWwise)
					RemoveSpatialAudioRoom();
				else
					AddSpatialAudioRoom();
			}
		}
	}
}

#if WITH_EDITOR
void UAkRoomComponent::BeginDestroy()
{
	Super::BeginDestroy();
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->RemoveAll(this);
	}
}

void UAkRoomComponent::HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	if (ReplacementMap.Contains(Parent))
	{
		InitializeParent();
		if (!IsRegisteredWithWwise)
			AddSpatialAudioRoom();
		else
			UpdateSpatialAudioRoom();
	}
	if (ReplacementMap.Contains(GeometryComponent))
	{
		GeometryComponent = AkComponentHelpers::GetChildComponentOfType<UAkAcousticTextureSetComponent>(*Parent);
		if (GeometryComponent == nullptr || GeometryComponent->HasAnyFlags(RF_Transient) || GeometryComponent->IsBeingDestroyed())
		{
			GeometryComponent = NewObject<UAkGeometryComponent>(Parent, TEXT("GeometryComponent"));
			UAkGeometryComponent* GeomComp = Cast<UAkGeometryComponent>(GeometryComponent);
			GeomComp->MeshType = AkMeshType::CollisionMesh;
			GeomComp->bWasAddedByRoom = true;
			GeometryComponent->AttachToComponent(Parent, FAttachmentTransformRules::KeepRelativeTransform);
			GeometryComponent->RegisterComponent();

			if (!RoomIsActive())
				GeomComp->RemoveGeometry();
		}
		SendGeometry();
		UpdateSpatialAudioRoom();
	}
}

void UAkRoomComponent::RegisterVisEnabledCallback()
{
	if (!ShowRoomsChangedHandle.IsValid())
	{
		UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
		ShowRoomsChangedHandle = AkSettings->OnShowRoomsPortalsChanged.AddLambda([this, AkSettings]()
		{
			if (AkSettings->VisualizeRoomsAndPortals)
			{
				InitializeDrawComponent();
			}
			else
			{
				DestroyDrawComponent();
			}
		});
	}
}

void UAkRoomComponent::InitializeDrawComponent()
{
	if (AActor* Owner = GetOwner())
	{
		if (DrawRoomComponent == nullptr)
		{
			DrawRoomComponent = NewObject<UDrawRoomComponent>(Owner, NAME_None, RF_Transactional | RF_TextExportTransient);
			DrawRoomComponent->SetupAttachment(this);
			DrawRoomComponent->SetIsVisualizationComponent(true);
			DrawRoomComponent->CreationMethod = CreationMethod;
			DrawRoomComponent->RegisterComponentWithWorld(GetWorld());
			DrawRoomComponent->MarkRenderStateDirty();
		}
	}
}

void UAkRoomComponent::DestroyDrawComponent()
{
	if (DrawRoomComponent != nullptr)
	{
		DrawRoomComponent->DestroyComponent();
		DrawRoomComponent = nullptr;
	}
}
#endif 

void UAkRoomComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Moving = true;
	SecondsSinceMovement = 0.0f;
}

bool UAkRoomComponent::MoveComponentImpl(
	const FVector & Delta,
	const FQuat & NewRotation,
	bool bSweep,
	FHitResult * Hit,
	EMoveComponentFlags MoveFlags,
	ETeleportType Teleport)
{
	if (AkComponentHelpers::DoesMovementRecenterChild(this, Parent, Delta))
		Super::MoveComponentImpl(Delta, NewRotation, bSweep, Hit, MoveFlags, Teleport);

	return false;
}

void UAkRoomComponent::InitializeParent()
{
	USceneComponent* SceneParent = GetAttachParent();
	if (SceneParent != nullptr)
	{
		Parent = Cast<UPrimitiveComponent>(SceneParent);
		if (!Parent)
		{
			bEnable = false;
			AkComponentHelpers::LogAttachmentError(this, SceneParent, "UPrimitiveComponent");
			return;
		}

		UBodySetup* bodySetup = Parent->GetBodySetup();
		if (bodySetup == nullptr || !AkComponentHelpers::HasSimpleCollisionGeometry(bodySetup))
		{
			if (UBrushComponent* brush = Cast<UBrushComponent>(Parent))
				brush->BuildSimpleBrushCollision();
			else
				AkComponentHelpers::LogSimpleGeometryWarning(Parent, this);
		}
	}
}

void UAkRoomComponent::GetRoomParams(AkRoomParams& outParams)
{
	FString nameStr = UObject::GetName();
	AActor* roomOwner = GetOwner();
	if (roomOwner != nullptr)
	{
		nameStr = roomOwner->GetName();
		if (Parent != nullptr)
		{
			// ensures unique and meaningful names when we have multiple rooms in the same actor.
#if UE_4_24_OR_LATER
			TInlineComponentArray<UAkRoomComponent*> RoomComponents;
			roomOwner->GetComponents(RoomComponents);
			if (RoomComponents.Num() > 1)
				nameStr.Append(FString("_").Append(Parent->GetName()));
#else
			if (roomOwner->GetComponentsByClass(UAkRoomComponent::StaticClass()).Num() > 1)
				nameStr.Append(FString("_").Append(Parent->GetName()));
#endif
		}
	}

	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (!AkAudioDevice)
		return;

	if (IsValid(Parent))
	{
		AkComponentHelpers::GetPrimitiveUpAndFront(*Parent, outParams.Up, outParams.Front);
	}

	// This ensures that src stays alive until the end of the function compared to TCHAR_TO_ANSI which erased it just after the Get()
	auto src = StringCast<ANSICHAR>(static_cast<const TCHAR*>(*nameStr));
	outParams.strName = src.Get();
	// moving the ownership to spatial audio because src is erased at the end of the function, but params.strName needs to stay alive
	outParams.strName.AllocCopy();

	outParams.TransmissionLoss = WallOcclusion;

	UAkLateReverbComponent* ReverbComp = nullptr;
	if (Parent != nullptr)
		ReverbComp = AkComponentHelpers::GetChildComponentOfType<UAkLateReverbComponent>(*Parent);
	if (ReverbComp && ReverbComp->bEnable)
	{
		outParams.ReverbAuxBus = ReverbComp->GetAuxBusId();
		outParams.ReverbLevel = ReverbComp->SendLevel;
	}

	if (GeometryComponent != nullptr)
		outParams.GeometryID = GeometryComponent->GetGeometrySetID();
	
	outParams.RoomGameObj_AuxSendLevelToSelf = AuxSendLevel;
	outParams.RoomGameObj_KeepRegistered = AkAudioEvent == NULL && EventName.IsEmpty() ? false : true;
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings != nullptr && AkSettings->ReverbRTPCsInUse())
		outParams.RoomGameObj_KeepRegistered = true;
}

UPrimitiveComponent* UAkRoomComponent::GetPrimitiveParent() const
{
	return Parent;
}

void UAkRoomComponent::AddSpatialAudioRoom()
{
	if (RoomIsActive())
	{
		SendGeometry();

		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
		{
			AkRoomParams params;
			GetRoomParams(params);
			AkAudioDevice->AddRoom(this, params);
			IsRegisteredWithWwise = true;
			if (GetOwner() != nullptr && Parent != nullptr && IsRegisteredWithWwise && (GetWorld()->WorldType == EWorldType::Game || GetWorld()->WorldType == EWorldType::PIE))
			{
				UAkLateReverbComponent* pRvbComp = AkComponentHelpers::GetChildComponentOfType<UAkLateReverbComponent>(*Parent);
				if (pRvbComp != nullptr)
					pRvbComp->UpdateRTPCs(this);
			}
		}
	}
}

void UAkRoomComponent::UpdateSpatialAudioRoom()
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (RoomIsActive() && AkAudioDevice && IsRegisteredWithWwise)
	{
		AkRoomParams params;
		GetRoomParams(params);
		AkAudioDevice->UpdateRoom(this, params);
		if (GetOwner() != nullptr && Parent != nullptr && (GetWorld()->WorldType == EWorldType::Game || GetWorld()->WorldType == EWorldType::PIE))
		{
			UAkLateReverbComponent* pRvbComp = AkComponentHelpers::GetChildComponentOfType<UAkLateReverbComponent>(*Parent);
			if (pRvbComp != nullptr)
				pRvbComp->UpdateRTPCs(this);
		}
	}
}

void UAkRoomComponent::RemoveSpatialAudioRoom()
{
	if (Parent && !IsRunningCommandlet())
	{
		RemoveGeometry();

		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
		{
			if (GetOwner() != nullptr && (GetWorld()->WorldType == EWorldType::Game || GetWorld()->WorldType == EWorldType::PIE))
			{
				// stop all sounds posted on the room
				Stop();
			}
			AkAudioDevice->RemoveRoom(this);
			IsRegisteredWithWwise = false;
		}
	}
}

int32 UAkRoomComponent::PostAssociatedAkEvent(int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources)
{
	AkPlayingID playingID = AK_INVALID_PLAYING_ID;

	if (!HasActiveEvents())
		playingID = PostAkEvent(AkAudioEvent, CallbackMask, PostEventCallback, ExternalSources, EventName);

	return playingID;
}

AkPlayingID UAkRoomComponent::PostAkEventByNameWithDelegate(
	const FString& in_EventName,
	int32 CallbackMask,
	const FOnAkPostEventCallback& PostEventCallback,
	const TArray<FAkExternalSourceInfo>& ExternalSources)
{
	AkPlayingID playingID = AK_INVALID_PLAYING_ID;

	auto AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		playingID = AudioDevice->PostEvent(in_EventName, this, PostEventCallback, CallbackMask);
		if (playingID != AK_INVALID_PLAYING_ID)
			bStarted = true;
	}

	return playingID;
}

void UAkRoomComponent::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITOR
	// If we're PIE, or somehow otherwise in a game world in editor, simulate the bDynamic behaviour.
	if (AkComponentHelpers::IsInGameWorld(this))
	{
		bWantsOnUpdateTransform = bDynamic;
	}
	if (AkComponentHelpers::ShouldDeferBeginPlay(this))
		bRequiresDeferredBeginPlay = true;
	else
		BeginPlayInternal();
#else
	BeginPlayInternal();
	PrimaryComponentTick.bCanEverTick = bDynamic;
	PrimaryComponentTick.bStartWithTickEnabled = bDynamic;
#endif
}

void UAkRoomComponent::BeginPlayInternal()
{
	GeometryComponent = AkComponentHelpers::GetChildComponentOfType<UAkAcousticTextureSetComponent>(*Parent);
	if (GeometryComponent == nullptr || GeometryComponent->HasAnyFlags(RF_Transient) || GeometryComponent->IsBeingDestroyed())
	{
		static const FName GeometryComponentName = TEXT("GeometryComponent");
		GeometryComponent = NewObject<UAkGeometryComponent>(Parent, GeometryComponentName);
		UAkGeometryComponent* geom = Cast<UAkGeometryComponent>(GeometryComponent);
		geom->MeshType = AkMeshType::CollisionMesh;
		geom->bWasAddedByRoom = true;
		GeometryComponent->AttachToComponent(Parent, FAttachmentTransformRules::KeepRelativeTransform);
		GeometryComponent->RegisterComponent();

		if (!RoomIsActive())
			geom->RemoveGeometry();
	}

	// We want to add / update the room both in BeginPlay and OnRegister. BeginPlay for aux bus and reverb level assignment, OnRegister for portal room assignment and visualization
	if (!IsRegisteredWithWwise)
	{
		AddSpatialAudioRoom();
	}
	else
	{
		SendGeometry();
		UpdateSpatialAudioRoom();
	}

	if (AutoPost)
	{
		if (!HasActiveEvents())
			PostAssociatedAkEvent(0, FOnAkPostEventCallback(), TArray<FAkExternalSourceInfo>());
	}
}

void UAkRoomComponent::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	if (bStarted)
		Stop();

	Super::EndPlay(EndPlayReason);
}

void UAkRoomComponent::SetGeometryComponent(UAkAcousticTextureSetComponent* textureSetComponent)
{
	if (GeometryComponent != nullptr)
	{
		RemoveGeometry();
	}
	GeometryComponent = textureSetComponent;
	if (RoomIsActive())
	{
		SendGeometry();
		UpdateSpatialAudioRoom();
	}
}

#if WITH_EDITOR
void UAkRoomComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	//Call add again to update the room parameters, if it has already been added.
	if (IsRegisteredWithWwise)
		UpdateSpatialAudioRoom();
}
#endif

bool UAkRoomComponent::EncompassesPoint(FVector Point, float SphereRadius/*=0.f*/, float* OutDistanceToPoint/*=nullptr*/) const
{
	if (IsValid(Parent))
	{
		return AkComponentHelpers::EncompassesPoint(*Parent, Point, SphereRadius, OutDistanceToPoint);
	}
	FString actorString = FString("NONE");
	if (GetOwner() != nullptr)
		actorString = GetOwner()->GetName();
	UE_LOG(LogAkAudio, Error, TEXT("UAkRoomComponent::EncompassesPoint : Error. In actor %s, AkRoomComponent %s has an invalid Parent."), *actorString, *UObject::GetName());
	return false;
}

void UAkRoomComponent::SendGeometry()
{
	if (GeometryComponent)
	{
		UAkGeometryComponent* GeometryComp = Cast<UAkGeometryComponent>(GeometryComponent);
		if (GeometryComp && GeometryComp->bWasAddedByRoom)
		{
			GeometryComp->SendGeometry();
		}
		UAkSurfaceReflectorSetComponent* SurfaceReflector = Cast<UAkSurfaceReflectorSetComponent>(GeometryComponent);
		if (SurfaceReflector && !SurfaceReflector->bEnableSurfaceReflectors)
		{
			SurfaceReflector->SendSurfaceReflectorSet();
		}
	}
}

void UAkRoomComponent::RemoveGeometry()
{
	if (IsValid(GeometryComponent))
	{
		UAkGeometryComponent* GeometryComp = Cast<UAkGeometryComponent>(GeometryComponent);
		if (GeometryComp && GeometryComp->bWasAddedByRoom)
		{
			GeometryComp->RemoveGeometry();
		}
		UAkSurfaceReflectorSetComponent* SurfaceReflector = Cast<UAkSurfaceReflectorSetComponent>(GeometryComponent);
		if (SurfaceReflector && !SurfaceReflector->bEnableSurfaceReflectors)
		{
			SurfaceReflector->RemoveSurfaceReflectorSet();
		}
	}
}