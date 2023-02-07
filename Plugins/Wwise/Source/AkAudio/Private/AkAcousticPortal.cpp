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
	AAkAcousticPortal.cpp:
=============================================================================*/

#include "AkAcousticPortal.h"
#include "AkAudioDevice.h"
#include "AkComponentHelpers.h"
#include "AkSpatialAudioHelper.h"
#include "Components/BrushComponent.h"
#include "Model.h"
#include "EngineUtils.h"
#include "AkRoomComponent.h"
#include "AkComponent.h"
#include "AkCustomVersion.h"
#include "Kismet/KismetMathLibrary.h"
#include "AkSpatialAudioVolume.h"

#include <algorithm>

// A standard AAkAcousticPortal is based on a cube brush with verts at [+/-]100 X,Y,Z. 
static const float kDefaultBrushExtents = 100.f;

// min portal size, in cm. For raycasts
static const float kMinPortalSize = 10.0f; 

#if WITH_EDITOR
#include "AkDrawPortalComponent.h"
#include "AkSettings.h"
#endif

UAkPortalComponent::UAkPortalComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	ObstructionRefreshInterval = 0.f;

	PortalState = InitialState;
	bUseAttachParentBound = true;

	FrontRoom = nullptr;
	BackRoom = nullptr;

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	bTickInEditor = true;
#if WITH_EDITOR
	bWantsOnUpdateTransform = true;
	bWantsInitializeComponent = true;
#else
	bWantsOnUpdateTransform = bDynamic;
#endif

#if WITH_EDITOR
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->AddUObject(this, &UAkPortalComponent::HandleObjectsReplaced);
	}
#endif
}

void UAkPortalComponent::OnRegister()
{
	Super::OnRegister();
	SetRelativeTransform(FTransform::Identity);
	InitializeParent();
	UpdateConnectedRooms();

	UWorld* world = GetWorld();
	if (world != nullptr)
		SetSpatialAudioPortal();

#if WITH_EDITOR
	if (GetDefault<UAkSettings>()->VisualizeRoomsAndPortals)
	{
		InitializeDrawComponent();
	}
#endif
}

void UAkPortalComponent::OnUnregister()
{
	Super::OnUnregister();
	FAkAudioDevice * Dev = FAkAudioDevice::Get();
	if (Dev != nullptr)
	{
		Dev->RemoveSpatialAudioPortal(this);
	}
}

#if WITH_EDITOR
void UAkPortalComponent::BeginDestroy()
{
	Super::BeginDestroy();
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->RemoveAll(this);
	}
}

void UAkPortalComponent::HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	if (ReplacementMap.Contains(Parent))
	{
		InitializeParent();
	}
	if (ReplacementMap.Contains(FrontRoom) || ReplacementMap.Contains(BackRoom))
	{
		UpdateConnectedRooms();
	}
}

void UAkPortalComponent::InitializeComponent()
{
	Super::InitializeComponent();
	RegisterVisEnabledCallback();
}

void UAkPortalComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	RegisterVisEnabledCallback();
}

void UAkPortalComponent::PostLoad()
{
	Super::PostLoad();
	RegisterVisEnabledCallback();
}

void UAkPortalComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	AkSettings->OnShowRoomsPortalsChanged.Remove(ShowPortalsChangedHandle);
	ShowPortalsChangedHandle.Reset();
	DestroyDrawComponent();
}
#endif // WITH_EDITOR

bool UAkPortalComponent::MoveComponentImpl(
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

void UAkPortalComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	PortalNeedUpdated = true;
}


#if WITH_EDITOR
void UAkPortalComponent::RegisterVisEnabledCallback()
{
	if (!ShowPortalsChangedHandle.IsValid())
	{
		UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
		ShowPortalsChangedHandle = AkSettings->OnShowRoomsPortalsChanged.AddLambda([this, AkSettings]()
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


void UAkPortalComponent::InitializeDrawComponent()
{
	if (AActor* Owner = GetOwner())
	{
		if (DrawPortalComponent == nullptr)
		{
			DrawPortalComponent = NewObject<UDrawPortalComponent>(Owner, NAME_None, RF_Transactional | RF_TextExportTransient);
			DrawPortalComponent->SetupAttachment(this);
			DrawPortalComponent->SetIsVisualizationComponent(true);
			DrawPortalComponent->CreationMethod = CreationMethod;
			DrawPortalComponent->RegisterComponentWithWorld(GetWorld());
			DrawPortalComponent->MarkRenderStateDirty();
		}
	}
}

void UAkPortalComponent::DestroyDrawComponent()
{
	if (DrawPortalComponent != nullptr)
	{
		DrawPortalComponent->DestroyComponent();
		DrawPortalComponent = nullptr;
	}
}
#endif 

void UAkPortalComponent::InitializeParent()
{
	USceneComponent* SceneParent = GetAttachParent();
	if (SceneParent != nullptr)
	{
		Parent = Cast<UPrimitiveComponent>(SceneParent);
		if (!Parent)
		{
			AkComponentHelpers::LogAttachmentError(this, SceneParent, "UPrimitiveComponent");
		}
	}
}

void UAkPortalComponent::SetSpatialAudioPortal()
{
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice != nullptr)
	{
		AkAudioDevice->SetSpatialAudioPortal(this);
		PortalNeedUpdated = false;
	}
}

void UAkPortalComponent::OpenPortal()
{
	if (PortalState == AkAcousticPortalState::Closed)
	{
		PortalState = AkAcousticPortalState::Open;
		SetSpatialAudioPortal();
	}
}

void UAkPortalComponent::ClosePortal()
{
	if (PortalState == AkAcousticPortalState::Open)
	{
		PortalState = AkAcousticPortalState::Closed;
		SetSpatialAudioPortal();
	}
}

AkAcousticPortalState UAkPortalComponent::GetCurrentState() const
{
	return PortalState;
}

void UAkPortalComponent::BeginPlay()
{
	Super::BeginPlay();
	// If we're PIE, or somehow otherwise in a game world in editor, simulate the bDynamic behaviour.
#if WITH_EDITOR
	UWorld* world = GetWorld();
	if (world != nullptr && (world->WorldType == EWorldType::Type::Game || world->WorldType == EWorldType::Type::PIE))
		bWantsOnUpdateTransform = bDynamic;
#endif
	UpdateConnectedRooms();
	ResetPortalState();
	FAkAudioDevice * Dev = FAkAudioDevice::Get();
	if (Dev != nullptr)
	{
		ObstructionService.Init(this, ObstructionRefreshInterval);
	}
}

void UAkPortalComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if (PortalNeedUpdated)
	{
		UpdateConnectedRooms();
		SetSpatialAudioPortal();
	}

	if (GetCurrentState() == AkAcousticPortalState::Open)
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
		{
			UAkComponent* Listener = AkAudioDevice->GetSpatialAudioListener();
			if (Listener != nullptr)
			{
				AkRoomID listenerRoom = Listener->GetSpatialAudioRoom();
				UAkComponentSet set;
				set.Add(Listener);
				ObstructionService.Tick(set, GetOwner()->GetActorLocation(), GetOwner(), listenerRoom, ObstructionCollisionChannel, DeltaTime, ObstructionRefreshInterval);
			}
		}
	}
}

void UAkPortalComponent::ResetPortalState()
{
	PortalState = InitialState;
	SetSpatialAudioPortal();
}

bool UAkPortalComponent::UpdateConnectedRooms()
{
	/* Keep note of the rooms and validity before the update. */
	AkRoomID previousFront = GetFrontRoom();
	AkRoomID previousBack = GetBackRoom();
	/* Update the room connections */
	FrontRoom = nullptr;
	BackRoom = nullptr;
	FAkAudioDevice * Dev = FAkAudioDevice::Get();
	FindConnectedComponents(Dev->GetRoomIndex(), FrontRoom, BackRoom);
	LastRoomsUpdate = GetWorld()->GetTimeSeconds();
	PreviousLocation = GetComponentLocation();
	PreviousRotation = GetComponentRotation();
	/* Return true if any room connection has changed. */
	return (GetFrontRoom() != previousFront || GetBackRoom() != previousBack);
}

UPrimitiveComponent* UAkPortalComponent::GetPrimitiveParent() const
{
	return Parent;
}

FVector UAkPortalComponent::GetExtent() const
{
	FBoxSphereBounds ComponentBounds = Bounds;
	if (Parent != nullptr)
	{
		FTransform Transform (Parent->GetComponentTransform());
		Transform.SetRotation(FQuat::Identity);
		ComponentBounds = Parent->CalcBounds(Transform);
	}
	return ComponentBounds.BoxExtent;
}

AkRoomID UAkPortalComponent::GetFrontRoom() const { return FrontRoom == nullptr ? AkRoomID() : FrontRoom->GetRoomID(); }
AkRoomID UAkPortalComponent::GetBackRoom() const { return BackRoom == nullptr ? AkRoomID() : BackRoom->GetRoomID(); }



template <typename tComponent>
void UAkPortalComponent::FindConnectedComponents(FAkEnvironmentIndex& RoomIndex, tComponent*& out_pFront, tComponent*& out_pBack)
{
	out_pFront = nullptr;
	out_pBack = nullptr;

	FAkAudioDevice* pAudioDevice = FAkAudioDevice::Get();
	if (pAudioDevice != nullptr && Parent != nullptr)
	{
		float x = GetExtent().X;
		FVector frontVector(x, 0.f, 0.f);

		FTransform toWorld = Parent->GetComponentTransform();
		toWorld.SetScale3D(FVector(1.0f));

		FVector frontPoint = toWorld.TransformPosition(frontVector);
		FVector backPoint = toWorld.TransformPosition(-1 * frontVector);

		TArray<tComponent*> front = RoomIndex.Query<tComponent>(frontPoint, GetWorld());
		if (front.Num() > 0)
			out_pFront = front[0];

		TArray<tComponent*> back = RoomIndex.Query<tComponent>(backPoint, GetWorld());
		if (back.Num() > 0)
			out_pBack = back[0];
	}
}

/*------------------------------------------------------------------------------------
	AAkAcousticPortal
------------------------------------------------------------------------------------*/

AAkAcousticPortal::AAkAcousticPortal(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	// Property initialization
	static const FName CollisionProfileName(TEXT("OverlapAll"));
	GetBrushComponent()->SetCollisionProfileName(CollisionProfileName);

	bColored = true;
	BrushColor = FColor(255, 196, 137, 255);

	InitialState = AkAcousticPortalState::Open;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_DuringPhysics;
	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	static const FName PortalComponentName = TEXT("PortalComponent");
	Portal = ObjectInitializer.CreateDefaultSubobject<UAkPortalComponent>(this, PortalComponentName);
	Portal->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

#if WITH_EDITOR
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings)
	{
		CollisionChannel = AkSettings->DefaultFitToGeometryCollisionChannel;
	}
	else
	{
		CollisionChannel = ECollisionChannel::ECC_WorldStatic;
	}
#endif
}

void AAkAcousticPortal::OpenPortal()
{
	if (Portal != nullptr)
	{
		Portal->OpenPortal();
	}
	else
	{
		UE_LOG(LogAkAudio, Warning, TEXT("AAkAcousticPortal %s called OpenPortal with uninitialized portal component."), *GetName());
	}
}

void AAkAcousticPortal::ClosePortal()
{
	if (Portal != nullptr)
	{
		Portal->ClosePortal();
	}
	else
	{
		UE_LOG(LogAkAudio, Warning, TEXT("AAkAcousticPortal %s called ClosePortal with uninitialized portal component."), *GetName());
	}
}

AkAcousticPortalState AAkAcousticPortal::GetCurrentState() const
{
	if (Portal != nullptr)
		return Portal->GetCurrentState();
	UE_LOG(LogAkAudio, Warning, TEXT("AAkAcousticPortal %s called GetCurrentState with uninitialized portal component."), *GetName());
	return AkAcousticPortalState::Closed;
}

AkRoomID AAkAcousticPortal::GetFrontRoom() const
{
	if (Portal != nullptr)
		return Portal->GetFrontRoom();
	UE_LOG(LogAkAudio, Warning, TEXT("AAkAcousticPortal %s called GetFrontRoom with uninitialized portal component."), *GetName());
	return AkRoomID();
}

AkRoomID AAkAcousticPortal::GetBackRoom() const
{
	if (Portal != nullptr)
		return Portal->GetBackRoom();
	UE_LOG(LogAkAudio, Warning, TEXT("AAkAcousticPortal %s called GetBackRoom with uninitialized portal component."), *GetName());
	return AkRoomID();
}

void AAkAcousticPortal::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	if (bRequiresStateMigration)
	{
		if (Portal != nullptr)
		{
			Portal->InitialState = InitialState;
			bRequiresStateMigration = false;
		}
	}
	
	if (bRequiresTransformMigration)
	{
		FVector right = FVector(0.0f, 1.0f, 0.0f);
		FVector left = FVector(0.0f, -1.0f, 0.0f);
		FTransform actorTransform = GetActorTransform();
		/* get the local 'front' (with respect to Y). */
		FVector localYFront = (actorTransform.TransformPosition(right) - actorTransform.TransformPosition(left));
		localYFront.Normalize();
		FVector scale = GetActorScale3D();
		SetActorScale3D(FVector(scale.Y, scale.X, scale.Z));
		/* get the local front, using Unreal coordinate orientation. */
		FVector localXFront = GetActorForwardVector();
		/* get the local up vector around which to rotate. */
		FVector localUp = FVector::CrossProduct(localYFront, localXFront);
		/* rotate the local front vector around the local up, such that it points along the 'true' local front, in Unreal terms. */
		localXFront = localXFront.RotateAngleAxis(-90.0f, localUp);
		/* Set up new local axes such that localUp remains constant, local front is changed to localXFront, and the local right is calculated from these two. */
		SetActorRotation(UKismetMathLibrary::MakeRotFromXZ(localXFront, localUp));

		bRequiresTransformMigration = false;
	}
}

void AAkAcousticPortal::PostLoad()
{
	Super::PostLoad();
	const int32 AkVersion = GetLinkerCustomVersion(FAkCustomVersion::GUID);

	if (AkVersion < FAkCustomVersion::SpatialAudioExtentAPIChange)
	{
		bRequiresTransformMigration = true;
	}

	if (AkVersion < FAkCustomVersion::SpatialAudioComponentisation)
	{
		bRequiresStateMigration = true;
	}
}

void AAkAcousticPortal::Serialize(FArchive& Ar)
{
	Ar.UsingCustomVersion(FAkCustomVersion::GUID);
	Super::Serialize(Ar);
}

#if WITH_EDITOR

void AAkAcousticPortal::FitRaycast()
{
	static const FName NAME_SAV_Fit = TEXT("AAkAcousticPortalRaycast");

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(this);
	if (!World)
		return;

	TArray<TTuple<float, FVector, FVector>> hits;

	// Ray length - DetectionRadius X current scale. 
	float RayLength = GetDetectionRadius();

	FCollisionQueryParams CollisionParams(NAME_SAV_Fit, true, this);

	FVector RaycastOrigin = bUseSavedRaycastOrigin ? SavedRaycastOrigin : GetActorLocation();

	float Offset = 2.f / kNumRaycasts;
	float Increment = PI * (3.f - sqrtf(5.f));

	TArray< FHitResult > OutHits;

	for (int i = 0; i < kNumRaycasts; ++i)
	{
		float x = ((i * Offset) - 1) + (Offset / 2);
		float r = sqrtf(1.f - powf(x, 2.f));

		float phi = ((i + 1) % kNumRaycasts) * Increment;

		float y = cosf(phi) * r;
		float z = sinf(phi) * r;

		FVector to = RaycastOrigin + FVector(x, y, z) * RayLength;

		OutHits.Empty();
		World->LineTraceMultiByObjectType(OutHits, RaycastOrigin, to, (int)CollisionChannel, CollisionParams);

		if (OutHits.Num() > 0)
		{
			bool bHit = false;
			FVector ImpactPoint0;
			FVector ImpactNormal0;

			for (auto& res : OutHits)
			{
				if (res.IsValidBlockingHit() &&
					!AkSpatialAudioHelper::IsAkSpatialAudioActorClass(AkSpatialAudioHelper::GetActorFromHitResult(res)))
				{
					bHit = true;
					ImpactPoint0 = res.ImpactPoint;
					ImpactNormal0 = res.ImpactNormal;
					break;
				}
			}

			if (bHit)
			{
				OutHits.Empty();
				World->LineTraceMultiByObjectType(OutHits, ImpactPoint0, ImpactPoint0 + ImpactNormal0 * RayLength, (int)CollisionChannel, CollisionParams);

				bHit = false;
				FVector ImpactPoint1;

				for (auto& res : OutHits)
				{
					if (res.IsValidBlockingHit() &&
						res.Distance > kMinPortalSize &&
						!AkSpatialAudioHelper::IsAkSpatialAudioActorClass(AkSpatialAudioHelper::GetActorFromHitResult(res)))
					{
						bHit = true;
						ImpactPoint1 = res.ImpactPoint;
						break;
					}
				}

				if (bHit)
				{
					float distance = (ImpactPoint0 - ImpactPoint1).Size();
					hits.Emplace(MakeTuple(distance, ImpactPoint0, ImpactPoint1));
				}
				
			}
		}
	}

	auto SortPredicate = [](TTuple<float, FVector, FVector>& A, TTuple<float, FVector, FVector>& B) {	return A.Get<0>() < B.Get<0>(); };

	Algo::Sort(hits, SortPredicate);
	
	static const float kDotEpsilon = 0.1f;
	static const float kLineIntersectThresh = 2.0f;

	float minDist = FLT_MAX;
	int Best0 = INT_MAX;
	int Best1 = INT_MAX;
	bool bIntersects = false;
	for (int i = 0; i < hits.Num() && !bIntersects; ++i)
	{
		FVector& pti = hits[i].Get<1>();
		FVector vi = hits[i].Get<2>() - hits[i].Get<1>();
		FVector diri;
		float leni;
		vi.ToDirectionAndLength(diri, leni);

		for (int j = i + 1; j < hits.Num() && !bIntersects; ++j)
		{
			FVector& ptj = hits[j].Get<1>();
			FVector vj = hits[j].Get<2>() - hits[j].Get<1>();
			FVector dirj;
			float lenj;
			vj.ToDirectionAndLength(dirj, lenj);

			if (FMath::Abs(FVector::DotProduct(diri, dirj)) < kDotEpsilon)
			{
				float proj_ji = FVector::DotProduct((ptj - pti), diri);
				if (proj_ji > 0.f && proj_ji < leni)
				{
					float proj_ij = FVector::DotProduct((pti - ptj), dirj);
					if (proj_ij > 0.f && proj_ij < lenj)
					{
						FVector p0 = pti + proj_ji * diri;
						FVector p1 = ptj + proj_ij * dirj;

						float dist = (p0 - p1).Size();
						if (dist < minDist)
						{
							minDist = dist;
							Best0 = i;
							Best1 = j;
							
							if (dist < kLineIntersectThresh)
							{
								//Assuming here we found a pretty good result, bail out so as to favor smaller portals over bigger ones.
								bIntersects = true;
							}
						}
					}
				}
			}
		}
	}

	if (bIntersects)
	{
		BestFit[0] = hits[Best0].Get<1>();
		BestFit[1] = hits[Best0].Get<2>();
		BestFit[2] = hits[Best1].Get<1>();
		BestFit[3] = hits[Best1].Get<2>();

		BestFitValid = true;
	}
	else
	{
		// We will hold on to the best fit points, as long as they are within the detection radius.
		BestFitValid = FVector::DistSquared(RaycastOrigin, (BestFit[0] + BestFit[1] + BestFit[2] + BestFit[3]) / 4.f) < DetectionRadius * DetectionRadius;
	}
}

void AAkAcousticPortal::FitPortal()
{
	if (!BestFitValid)
		return;

	FVector center;
	FVector front;
	FVector side;
	FVector up;
	FVector scale;
	
	FVector& pti = BestFit[0];
	FVector vi = BestFit[1] - BestFit[0];
	FVector diri;
	float leni;
	vi.ToDirectionAndLength(diri, leni);

	FVector& ptj = BestFit[2];
	FVector vj = BestFit[3] - BestFit[2];
	FVector dirj;
	float lenj;
	vj.ToDirectionAndLength(dirj, lenj);

	float proj_ji = FVector::DotProduct((ptj - pti), diri);
	if (proj_ji > 0.f && proj_ji < leni)
	{
		float proj_ij = FVector::DotProduct((pti - ptj), dirj);
		if (proj_ij > 0.f && proj_ij < lenj)
		{
			FVector p0 = pti + proj_ji * diri;
			FVector p1 = ptj + proj_ij * dirj;

			center = pti - proj_ij * dirj;
			center += diri * leni / 2.f + dirj * lenj / 2.f;

			front = FVector::CrossProduct(diri, dirj);
			side = diri;
			up = dirj;
			scale.Y = leni / 2.f;
			scale.Z = lenj / 2.f;

			scale /= kDefaultBrushExtents;

			scale.X = GetActorScale3D().X;

			auto* RC = GetRootComponent();
			if (RC)
			{
				RC->SetWorldLocation(center);
				FRotator rotation = FRotationMatrix::MakeFromXZ(front, up).Rotator();
				RC->SetWorldRotation(rotation);
				RC->SetWorldScale3D(scale);
			}
		}
	}
}

void AAkAcousticPortal::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);

	if (FitToGeometry)
	{
		FitRaycast();
		
		IsDragging = !bFinished;
		
		if (bFinished)
		{
			bUseSavedRaycastOrigin = false;
	
			FitPortal();
		}
	}
}

void AAkAcousticPortal::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AAkAcousticPortal, FitToGeometry))
		{
			ClearBestFit();

			if (FitToGeometry)
			{
				FitRaycast();
				FitPortal();
			}
		}

		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AAkAcousticPortal, DetectionRadius))
		{
			if (FitToGeometry)
			{
				if (!bUseSavedRaycastOrigin)
				{
					// Cache the actor position to get consistant results over multiple updates, since FitPortal() changes the actor location.
					SavedRaycastOrigin = GetActorLocation();
					bUseSavedRaycastOrigin = true;
				}

				FitRaycast();
				FitPortal();
			}
		}
	}
}

void AAkAcousticPortal::ClearBestFit()
{
	BestFit[0] = FVector::ZeroVector;
	BestFit[1] = FVector::ZeroVector;
	BestFit[2] = FVector::ZeroVector;
	BestFit[3] = FVector::ZeroVector;
	BestFitValid = false;
}

#endif // WITH_EDITOR

