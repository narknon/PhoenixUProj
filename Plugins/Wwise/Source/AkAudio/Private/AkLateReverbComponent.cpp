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
	AkLateReverbComponent.cpp:
=============================================================================*/

#include "AkLateReverbComponent.h"
#include "AkCustomVersion.h"
#include "AkSettings.h"
#include "AkComponentHelpers.h"
#include "AkAudioDevice.h"
#include "AkAuxBus.h"
#include "AkRoomComponent.h"
#include "AkSurfaceReflectorSetComponent.h"
#include "AkGeometryComponent.h"
#include "AkAcousticTextureSetComponent.h"
#include "Components/BrushComponent.h"
#include "Model.h"
#include "GameFramework/Volume.h"

#include "Engine/Canvas.h"
#include "CanvasItem.h"

#if WITH_EDITOR
#include "Editor.h"
#include "LevelEditorViewport.h"
#include "AkAudioStyle.h"
#include "AkSpatialAudioHelper.h"
#endif

/*------------------------------------------------------------------------------------
	UAkLateReverbComponent
------------------------------------------------------------------------------------*/
#if WITH_EDITOR
float UAkLateReverbComponent::TextVisualizerHeightOffset = 80.0f;
#endif

UAkLateReverbComponent::UAkLateReverbComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	Parent = nullptr;
	bUseAttachParentBound = true;

	// Property initialization
	SendLevel = 1.0f;
	FadeRate = 0.5f;
	Priority = 1.0f;

	bEnable = true;
	bWantsOnUpdateTransform = true;

#if WITH_EDITOR
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->AddUObject(this, &UAkLateReverbComponent::HandleObjectsReplaced);
	}
#endif
}

void UAkLateReverbComponent::PostLoad()
{
	Super::PostLoad();
	const int32 AkVersion = GetLinkerCustomVersion(FAkCustomVersion::GUID);

	if (AkVersion < FAkCustomVersion::ReverbAuxBusAutoAssignment)
	{
		AutoAssignAuxBus = false;
		AuxBusManual = AuxBus;
	}
}

void UAkLateReverbComponent::Serialize(FArchive& Ar)
{
	Ar.UsingCustomVersion(FAkCustomVersion::GUID);
	Super::Serialize(Ar);
}

bool UAkLateReverbComponent::HasEffectOnLocation(const FVector& Location) const
{
	// Need to add a small radius, because on the Mac, EncompassesPoint returns false if
	// Location is exactly equal to the Volume's location
	static float RADIUS = 0.01f;
	return LateReverbIsActive() && EncompassesPoint(Location, RADIUS);
}

uint32 UAkLateReverbComponent::GetAuxBusId() const
{
	if (AuxBus)
	{
		return AuxBus->ShortID;
	}
	else
	{
		return FAkAudioDevice::GetIDFromString(AuxBusName);
	}
}

void UAkLateReverbComponent::InitializeParent()
{
	USceneComponent* SceneParent = GetAttachParent();
	if (SceneParent != nullptr)
	{
		ReverbDescriptor.SetPrimitive(Cast<UPrimitiveComponent>(SceneParent));
		Parent = Cast<UPrimitiveComponent>(SceneParent);
		if (Parent)
		{
			ReverbDescriptor.SetReverbComponent(this);
			UBodySetup* bodySetup = Parent->GetBodySetup();
			if (bodySetup == nullptr || !AkComponentHelpers::HasSimpleCollisionGeometry(bodySetup))
			{
				if (UBrushComponent* brush = Cast<UBrushComponent>(Parent))
					brush->BuildSimpleBrushCollision();
				else
					AkComponentHelpers::LogSimpleGeometryWarning(Parent, this);
			}
		}
		else
		{
			bEnable = false;
			AkComponentHelpers::LogAttachmentError(this, SceneParent, "UPrimitiveComponent");
			return;
		}
	}
}

void UAkLateReverbComponent::BeginPlay()
{
	Super::BeginPlay();

	RecalculateDecay();
	RecalculatePredelay();

	UAkRoomComponent* pRoomCmpt = nullptr;
	if (Parent)
	{
		pRoomCmpt = AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Parent);
	}

	if (!pRoomCmpt || !pRoomCmpt->RoomIsActive())
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice && LateReverbIsActive())
		{
			AkAudioDevice->IndexLateReverb(this);
		}
	}
}

void UAkLateReverbComponent::BeginDestroy()
{
	Super::BeginDestroy();
	if (TextureSetComponent != nullptr)
	{
		TextureSetComponent->SetReverbDescriptor(nullptr);
	}
	ReverbDescriptor.SetPrimitive(nullptr);
#if WITH_EDITOR
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->RemoveAll(this);
	}
#endif
}

void UAkLateReverbComponent::OnRegister()
{
	Super::OnRegister();
	SetRelativeTransform(FTransform::Identity);
	InitializeParent();
	ParentChanged();

	// During runtime (non editor), we only want to tick if we'll ever need to update the reverb parameters.
	PrimaryComponentTick.bCanEverTick = ReverbDescriptor.RequiresUpdates();
	PrimaryComponentTick.bStartWithTickEnabled = ReverbDescriptor.RequiresUpdates();
#if WITH_EDITOR
	// In editor builds we always want to tick in case the global RTPCs become active, or aux bus assignment is enabled.
	bTickInEditor = true;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
#endif
}

void UAkLateReverbComponent::ParentChanged()
{
	if (IsValid(Parent))
	{
		DecayEstimationNeedsUpdate = true;
#if WITH_EDITOR
		RegisterAuxBusMapChangedCallback();
		RegisterReverbRTPCChangedCallback();
#endif
		// In the case where a blueprint class has a texture set component and a late reverb component as siblings, We can't know which will be registered first.
		// We need to check for the sibling in each OnRegister function and associate the texture set component to the late reverb when they are both registered.
		if (UAkSurfaceReflectorSetComponent* surfaceComponent = AkComponentHelpers::GetChildComponentOfType<UAkSurfaceReflectorSetComponent>(*Parent))
		{
			AssociateAkTextureSetComponent(surfaceComponent);
		}
		else if (UAkGeometryComponent* geometryComponent = AkComponentHelpers::GetChildComponentOfType<UAkGeometryComponent>(*Parent))
		{
			AssociateAkTextureSetComponent(geometryComponent);
		}
	}

	// Edge case: For a Blueprint-added late reverb component whose default 'auto-assign aux bus' value is true,
	// updating the aux bus directly here can cause it to remain in a read-only state even after auto-assign aux 
	// bus is disabled.
	if (CreationMethod == EComponentCreationMethod::SimpleConstructionScript)
		DecayEstimationNeedsUpdate = true;
	else
		RecalculateDecay();
	// --------------------

	RecalculatePredelay();
}

void UAkLateReverbComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
	if (AkAudioDevice && IsIndexed)
	{
		AkAudioDevice->UnindexLateReverb(this);
	}
}

void UAkLateReverbComponent::OnUnregister()
{
	Super::OnUnregister();

#if WITH_EDITOR
	DestroyTextVisualizers();
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (AuxBusChangedHandle.IsValid())
		{
			AkSettings->OnAuxBusAssignmentMapChanged.Remove(AuxBusChangedHandle);
		}
		if (RTPCChangedHandle.IsValid())
		{
			AkSettings->OnReverbRTPCChanged.Remove(RTPCChangedHandle);
		}
	}
#endif
}

bool UAkLateReverbComponent::MoveComponentImpl(
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

void UAkLateReverbComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	DecayEstimationNeedsUpdate = ReverbDescriptor.ShouldEstimateDecay();
	PredelayEstimationNeedsUpdate = ReverbDescriptor.ShouldEstimatePredelay();

	if (IsIndexed)
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice)
			AkAudioDevice->ReindexLateReverb(this);
	}

#if WITH_EDITOR
	if (TextVisualizerLabels != nullptr)
	{
		TextVisualizerLabels->SetWorldScale3D(FVector::OneVector);
		if (IsValid(Parent))
		{
			TextVisualizerLabels->SetWorldLocation(GetTextVisualizersLocation());
		}
	}
	if (TextVisualizerValues != nullptr)
	{
		TextVisualizerValues->SetWorldScale3D(FVector::OneVector);
		if (IsValid(Parent))
		{
			TextVisualizerValues->SetWorldLocation(GetTextVisualizersLocation());
		}
	}
#endif
}

void UAkLateReverbComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Update decay and time to first reflection estimations when the size is changed, every PARAM_ESTIMATION_UPDATE_PERIOD seconds.
	if (SecondsSinceDecayUpdate < PARAM_ESTIMATION_UPDATE_PERIOD)
	{
		SecondsSinceDecayUpdate += DeltaTime;
	}
	if (DecayEstimationNeedsUpdate && SecondsSinceDecayUpdate >= PARAM_ESTIMATION_UPDATE_PERIOD)
	{
		ReverbDescriptor.CalculateT60();
		DecayEstimationNeedsUpdate = false;
		SecondsSinceDecayUpdate = 0.0f;
	}
	if (SecondsSincePredelayUpdate < PARAM_ESTIMATION_UPDATE_PERIOD)
	{
		SecondsSincePredelayUpdate += DeltaTime;
	}
	if (PredelayEstimationNeedsUpdate && SecondsSincePredelayUpdate >= PARAM_ESTIMATION_UPDATE_PERIOD)
	{
		ReverbDescriptor.CalculateTimeToFirstReflection();
		PredelayEstimationNeedsUpdate = false;
		SecondsSincePredelayUpdate = 0.0f;
	}
#if WITH_EDITOR
	if (GCurrentLevelEditingViewportClient != nullptr)
	{
		// Keep the text renderers pointing to the camera.
		if (IsValid(TextVisualizerLabels))
		{
			FVector PointTo = GCurrentLevelEditingViewportClient->GetViewLocation() - TextVisualizerLabels->GetComponentLocation();
			TextVisualizerLabels->SetWorldRotation(PointTo.Rotation());
		}
		if (IsValid(TextVisualizerValues))
		{
			FVector PointTo = GCurrentLevelEditingViewportClient->GetViewLocation() - TextVisualizerValues->GetComponentLocation();
			TextVisualizerValues->SetWorldRotation(PointTo.Rotation());
		}
	}
	if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor || GetWorld()->WorldType == EWorldType::PIE)
	{
		// Only show the text renderer for selected actors.
		if (GetOwner()->IsSelected() && !WasSelected)
		{
			WasSelected = true;
			UpdateValuesLabels();
		}
		if (!GetOwner()->IsSelected() && WasSelected)
		{
			WasSelected = false;
			UpdateValuesLabels();
		}
	}
#endif
}

void UAkLateReverbComponent::RecalculateDecay()
{
	if (ReverbDescriptor.ShouldEstimateDecay())
	{
		ReverbDescriptor.CalculateT60();
		SecondsSinceDecayUpdate = 0.0f;
	}
}

void UAkLateReverbComponent::RecalculatePredelay()
{
	if (ReverbDescriptor.ShouldEstimatePredelay())
	{
		ReverbDescriptor.CalculateTimeToFirstReflection();
		SecondsSincePredelayUpdate = 0.0f;
	}
}

#if WITH_EDITOR
void UAkLateReverbComponent::HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	if (ReplacementMap.Contains(Parent))
	{
		InitializeParent();
		RecalculateDecay();
		RecalculatePredelay();
	}
	if (ReplacementMap.Contains(TextureSetComponent))
	{
		if (Parent != nullptr)
		{
			if (UAkSurfaceReflectorSetComponent* SurfaceComponent = AkComponentHelpers::GetChildComponentOfType<UAkSurfaceReflectorSetComponent>(*Parent))
			{
				AssociateAkTextureSetComponent(SurfaceComponent);
			}
			else if (UAkGeometryComponent* GeomComponent = AkComponentHelpers::GetChildComponentOfType<UAkGeometryComponent>(*Parent))
			{
				AssociateAkTextureSetComponent(GeomComponent);
			}
		}
	}
}

void UAkLateReverbComponent::UpdateTextVisualizerStatus()
{
	// The reverb descriptor may or may not require updates depending on which global RTPCs are in use, and whether auto assign aux bus is selected.
	// We only want to show the text renderers when the reverb parameter estimation is in use.
	if (!ReverbDescriptor.RequiresUpdates() && TextVisualizersInitialized())
	{
		DestroyTextVisualizers();
	}
	else if (ReverbDescriptor.RequiresUpdates() && !TextVisualizersInitialized())
	{
		InitTextVisualizers();
		DecayEstimationNeedsUpdate = ReverbDescriptor.ShouldEstimateDecay();
		PredelayEstimationNeedsUpdate = ReverbDescriptor.ShouldEstimatePredelay();
	}
}

bool UAkLateReverbComponent::TextVisualizersInitialized() const
{
	return IsValid(TextVisualizerLabels) && IsValid(TextVisualizerValues);
}

FText UAkLateReverbComponent::GetValuesLabels() const
{
	// Get a nicely formatted string showing the values of all of the reverb properties in a left-aligned block.
	// They will appear adjacent to a right-aligned block showing the property labels.
	FString BusName = FString("NONE");
	if (AuxBus != nullptr)
		AuxBus->GetName(BusName);
	FNumberFormattingOptions NumberFormat;
	NumberFormat.MaximumFractionalDigits = 2;
	FString volumeString = FText::AsNumber(EnvironmentVolume, &NumberFormat).ToString();
	FString areaString = FText::AsNumber(SurfaceArea, &NumberFormat).ToString();

	const FString missingRoomString = FString("Requires sibling AkRoom component");
	FString decayString = missingRoomString;
	FString reflectionTimeString = missingRoomString;
	FString dampingString = missingRoomString;
	
	if (AutoAssignAuxBus)
		decayString = FText::AsNumber(EnvironmentDecayEstimate, &NumberFormat).ToString() + " seconds";
	
	if (Parent != nullptr && AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Parent))
	{
		decayString = ReverbDescriptor.ShouldEstimateDecay() ? FText::AsNumber(EnvironmentDecayEstimate, &NumberFormat).ToString() + " seconds" : FString("Not in use");
		reflectionTimeString = FString("RTPC not in use");
		if (ReverbDescriptor.ShouldEstimatePredelay())
		{
			reflectionTimeString = FText::AsNumber(TimeToFirstReflection, &NumberFormat).ToString() + " seconds";
			if (TimeToFirstReflection < 0.1f)
			{
				reflectionTimeString = FText::AsNumber(TimeToFirstReflection * 1000.0f, &NumberFormat).ToString() + "ms";
			}
		}
		dampingString = "No associated geometry component.";
		if (TextureSetComponent != nullptr)
		{
			dampingString = ReverbDescriptor.ShouldEstimateDamping() ? FText::AsNumber(HFDamping, &NumberFormat).ToString() : FString("RTPC not in use");
		}
	}
	return FText::FromString(FString::Format(TEXT("{1} cubic meters{0}{2} square meters{0}{3}{0}{4}{0}{5}{0}{6}"),
		{ LINE_TERMINATOR, volumeString, areaString, decayString, BusName, reflectionTimeString, dampingString }));
}

void UAkLateReverbComponent::InitTextVisualizers()
{
	if (!HasAnyFlags(RF_Transient) && bEnable)
	{
		if (ReverbDescriptor.RequiresUpdates())
		{
			FString TextVizName = GetOwner()->GetName() + GetName();
			UMaterialInterface* mat = Cast<UMaterialInterface>(FAkAudioStyle::GetAkForegroundTextMaterial());
			if (!IsValid(TextVisualizerLabels))
			{
				TextVisualizerLabels = NewObject<UTextRenderComponent>(GetOuter(), *(TextVizName + TEXT("TextLabels")));
				if (IsValid(TextVisualizerLabels))
				{
					if (mat != nullptr)
						TextVisualizerLabels->SetTextMaterial(mat);
					TextVisualizerLabels->SetHorizontalAlignment(EHorizTextAligment::EHTA_Right);
					TextVisualizerLabels->RegisterComponentWithWorld(GetWorld());
					TextVisualizerLabels->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
					TextVisualizerLabels->ResetRelativeTransform();
					TextVisualizerLabels->SetWorldScale3D(FVector::OneVector);
					if (IsValid(Parent))
					{
						TextVisualizerLabels->SetWorldLocation(GetTextVisualizersLocation());
					}
					TextVisualizerLabels->bIsEditorOnly = true;
					// Creates a right-aligned block of text showing the property labels.
					TextVisualizerLabels->SetText(FText::FromString(FString::Format(TEXT("Volume {0}Area {0}Decay {0}AuxBus {0}Time to first reflection {0}HFDamping "), { LINE_TERMINATOR })));
					TextVisualizerLabels->bSelectable = false;
				}
			}
			if (!IsValid(TextVisualizerValues))
			{
				TextVisualizerValues = NewObject<UTextRenderComponent>(GetOuter(), *(TextVizName + TEXT("TextValues")));
				if (IsValid(TextVisualizerValues))
				{
					if (mat != nullptr)
						TextVisualizerValues->SetTextMaterial(mat);
					TextVisualizerValues->SetHorizontalAlignment(EHorizTextAligment::EHTA_Left);
					TextVisualizerValues->RegisterComponentWithWorld(GetWorld());
					TextVisualizerValues->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
					TextVisualizerValues->ResetRelativeTransform();
					TextVisualizerValues->SetWorldScale3D(FVector::OneVector);
					if (IsValid(Parent))
					{
						TextVisualizerValues->SetWorldLocation(GetTextVisualizersLocation());
					}
					TextVisualizerValues->bIsEditorOnly = true;
					TextVisualizerValues->bSelectable = false;
					UpdateValuesLabels();
				}
			}
		}
	}
}

void UAkLateReverbComponent::DestroyTextVisualizers()
{
	if (IsValid(TextVisualizerLabels))
	{
		TextVisualizerLabels->DestroyComponent();
		TextVisualizerLabels = nullptr;
	}
	if (IsValid(TextVisualizerValues))
	{
		TextVisualizerValues->DestroyComponent();
		TextVisualizerValues = nullptr;
	}
}

void UAkLateReverbComponent::UpdateValuesLabels()
{
	if (!TextVisualizersInitialized())
		InitTextVisualizers();
	if (IsValid(TextVisualizerValues))
	{
		TextVisualizerValues->SetText(GetValuesLabels());
		bool visible = false;
		if (GetWorld() != nullptr)
		{
			EWorldType::Type WorldType = GetWorld()->WorldType;
			if (WorldType == EWorldType::Editor)
			{
				visible = GetOwner() != nullptr && GetOwner()->IsSelected();
			}
			else if (WorldType == EWorldType::EditorPreview)
			{
				visible = true;
			}
		}
		if (GetOwner() != nullptr)
		{
			TextVisualizerValues->SetVisibility(visible);
			if (IsValid(TextVisualizerLabels))
				TextVisualizerLabels->SetVisibility(visible);
		}
	}
}
#endif // WITH_EDITOR

void UAkLateReverbComponent::UpdateRTPCs(const UAkRoomComponent* room) const
{
	// The global RTPCs are set on the room ids.
	ReverbDescriptor.UpdateAllRTPCs(room);
}

void UAkLateReverbComponent::AssociateAkTextureSetComponent(UAkAcousticTextureSetComponent* textureSetComponent)
{
	if (TextureSetComponent != nullptr)
		TextureSetComponent->SetReverbDescriptor(nullptr);
	TextureSetComponent = textureSetComponent;
	TextureSetComponent->SetReverbDescriptor(&ReverbDescriptor);
}

void UAkLateReverbComponent::UpdateDecayEstimation(float decay, float volume, float surfaceArea)
{
	if (AutoAssignAuxBus)
	{
		UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
		if (AkSettings != nullptr)
		{
			AkSettings->GetAuxBusForDecayValue(decay, AuxBus);
		}
	}

#if WITH_EDITOR
	EnvironmentVolume = volume;
	SurfaceArea = surfaceArea;
	EnvironmentDecayEstimate = decay;

	UpdateValuesLabels();
#endif // WITH_EDITOR
}

#if WITH_EDITOR
void UAkLateReverbComponent::UpdateHFDampingEstimation(float hfDamping)
{
	HFDamping = hfDamping;
	UpdateValuesLabels();
}

void UAkLateReverbComponent::UpdatePredelayEstimation(float predelay)
{
	TimeToFirstReflection = predelay;
	UpdateValuesLabels();
}

void UAkLateReverbComponent::PreEditChange(FProperty* PropertyAboutToChange)
{
	if (PropertyAboutToChange != nullptr)
	{
		if (!AutoAssignAuxBus
			&& (PropertyAboutToChange->NamePrivate == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, AutoAssignAuxBus)
				|| PropertyAboutToChange->NamePrivate == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, AuxBus)))
		{
			AuxBusManual = AuxBus;
		}
		if (AutoAssignAuxBus
			&& PropertyAboutToChange->NamePrivate == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, AutoAssignAuxBus))
		{
			AuxBus = AuxBusManual;
		}
	}
}

void UAkLateReverbComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName MemberPropertyName = (PropertyChangedEvent.MemberProperty != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;
	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, AutoAssignAuxBus))
	{
		PrimaryComponentTick.bCanEverTick = AutoAssignAuxBus;
		PrimaryComponentTick.bStartWithTickEnabled = AutoAssignAuxBus;
		bTickInEditor = AutoAssignAuxBus;
		RecalculateDecay();
		UpdateTextVisualizerStatus();

		if (!AutoAssignAuxBus)
		{
			AuxBus = AuxBusManual;
		}
	}
	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, AuxBus))
	{
		if (!AutoAssignAuxBus)
		{
			AuxBusManual = AuxBus;
		}
		if (AkComponentHelpers::IsInGameWorld(this))
		{
			UAkRoomComponent* RoomCmpt = nullptr;
			if (Parent)
			{
				RoomCmpt = AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Parent);
			}
			if (!RoomCmpt || !RoomCmpt->RoomIsActive())
			{
				// No room, or inactive room. Update the late reverb in the oct tree.
				FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
				if (AkAudioDevice && bEnable && IsIndexed)
				{
					AkAudioDevice->ReindexLateReverb(this);
				}
			}
			else if (RoomCmpt && RoomCmpt->RoomIsActive())
			{
				// Late reverb is inside an active room. Update the room such that the reverb aux bus is correctly updated.
				RoomCmpt->UpdateSpatialAudioRoom();
			}
		}
	}
	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, bEnable))
	{
		if (AkComponentHelpers::IsInGameWorld(this))
		{
			UAkRoomComponent* RoomCmpt = nullptr;
			if (Parent)
			{
				RoomCmpt = AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Parent);
			}

			if (!RoomCmpt || !RoomCmpt->RoomIsActive())
			{
				// No room, or inactive room. Update the late reverb in the oct tree.
				FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
				if (AkAudioDevice)
				{
					if (!bEnable && IsIndexed)
					{
						AkAudioDevice->UnindexLateReverb(this);
					}
					else if (bEnable && !IsIndexed)
					{
						AkAudioDevice->IndexLateReverb(this);
					}
				}
			}
			else if (RoomCmpt && RoomCmpt->RoomIsActive())
			{
				// Late reverb is inside an active room. Update the room such that the reverb aux bus is correctly updated.
				RoomCmpt->UpdateSpatialAudioRoom();
			}
		}
		else if (CreationMethod == EComponentCreationMethod::Instance && bEnable)
		{
			InitTextVisualizers();
		}
	}
	if (MemberPropertyName == GET_MEMBER_NAME_CHECKED(UAkLateReverbComponent, SendLevel))
	{
		UWorld* World = GetWorld();
		if (World != nullptr && World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE)
		{
			UAkRoomComponent* RoomCmpt = nullptr;
			if (Parent)
			{
				RoomCmpt = AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Parent);
			}
			if (!RoomCmpt || !RoomCmpt->RoomIsActive())
			{
				// No room, or inactive room. Update the late reverb in the oct tree.
				FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
				if (AkAudioDevice && bEnable && IsIndexed)
				{
					AkAudioDevice->ReindexLateReverb(this);
				}
			}
			else if (RoomCmpt && RoomCmpt->RoomIsActive())
			{
				// Late reverb is inside an active room. Update the room such that the reverb send level is correctly updated.
				RoomCmpt->UpdateSpatialAudioRoom();
			}
		}
	}
}

void UAkLateReverbComponent::OnAttachmentChanged()
{
	Super::OnAttachmentChanged();
	if (CreationMethod == EComponentCreationMethod::Instance)
	{
		InitializeParent();
		ParentChanged();
	}
}

FVector UAkLateReverbComponent::GetTextVisualizersLocation()
{
	if (!IsValid(Parent))
		return FVector();

	FBoxSphereBounds bounds = Parent->CalcBounds(Parent->GetComponentTransform());
	return Parent->GetComponentLocation() + FVector(0.0f, 0.0f, bounds.BoxExtent.Z + TextVisualizerHeightOffset);
}

void UAkLateReverbComponent::RegisterAuxBusMapChangedCallback()
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (AuxBusChangedHandle.IsValid())
			AkSettings->OnAuxBusAssignmentMapChanged.Remove(AuxBusChangedHandle);
		AuxBusChangedHandle = AkSettings->OnAuxBusAssignmentMapChanged.AddLambda([this]()
		{
			RecalculateDecay();
			UpdateTextVisualizerStatus();
		});
	}
}

void UAkLateReverbComponent::RegisterReverbRTPCChangedCallback()
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (RTPCChangedHandle.IsValid())
			AkSettings->OnReverbRTPCChanged.Remove(RTPCChangedHandle);
		RTPCChangedHandle = AkSettings->OnReverbRTPCChanged.AddLambda([this]()
		{
			RecalculateDecay();
			RecalculatePredelay();
			UpdateTextVisualizerStatus();
		});
	}
}
#endif

bool UAkLateReverbComponent::EncompassesPoint(FVector Point, float SphereRadius/*=0.f*/, float* OutDistanceToPoint) const
{
	if (IsValid(Parent))
	{
		return AkComponentHelpers::EncompassesPoint(*Parent, Point, SphereRadius, OutDistanceToPoint);
	}
	FString actorString = FString("NONE");
	if (GetOwner() != nullptr)
		actorString = GetOwner()->GetName();
	UE_LOG(LogAkAudio, Error, TEXT("UAkLateReverbComponent::EncompassesPoint : Error. In actor %s, AkLateReverbComponent %s has an invalid Parent."), *actorString, *GetName());
	return false;
}

