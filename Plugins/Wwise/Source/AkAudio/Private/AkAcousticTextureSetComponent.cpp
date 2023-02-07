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

#include "AkAcousticTextureSetComponent.h"
#include "AkAudioDevice.h"
#include "AkRoomComponent.h"
#include "AkReverbDescriptor.h"
#include "AkComponentHelpers.h"
#include "AkLateReverbComponent.h"
#include "AkSpatialAudioHelper.h"

UAkAcousticTextureSetComponent::UAkAcousticTextureSetComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	bTickInEditor = true;
#if WITH_EDITOR
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->AddUObject(this, &UAkAcousticTextureSetComponent::HandleObjectsReplaced);
	}
#endif
}

void UAkAcousticTextureSetComponent::OnRegister()
{
	Super::OnRegister();
#if WITH_EDITOR
	RegisterAllTextureParamCallbacks();
	RegisterReverbRTPCChangedCallback();
#endif
	// In the case where a blueprint class has a texture set component and a late reverb component as siblings, We can't know which will be registered first.
	// We need to check for the sibling in each OnRegister function and associate the texture set component to the late reverb when they are both registered.
	if (USceneComponent* parent = GetAttachParent())
	{
		if (UAkLateReverbComponent* reverbComp = AkComponentHelpers::GetChildComponentOfType<UAkLateReverbComponent>(*parent))
		{
			reverbComp->AssociateAkTextureSetComponent(this);
		}
	}
	RecalculateHFDamping();
}

void UAkAcousticTextureSetComponent::OnUnregister()
{
#if WITH_EDITOR
	UnregisterTextureParamChangeCallbacks();
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (RTPCChangedHandle.IsValid())
			AkSettings->OnReverbRTPCChanged.Remove(RTPCChangedHandle);
	}
#endif
	Super::OnUnregister();
}

void UAkAcousticTextureSetComponent::BeginPlay()
{
	Super::BeginPlay();
	RecalculateHFDamping();
}

void UAkAcousticTextureSetComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SecondsSinceDampingUpdate < PARAM_ESTIMATION_UPDATE_PERIOD)
	{
		SecondsSinceDampingUpdate += DeltaTime;
	}
	if (DampingEstimationNeedsUpdate && SecondsSinceDampingUpdate >= PARAM_ESTIMATION_UPDATE_PERIOD)
	{
		ReverbDescriptor->CalculateHFDamping(this);
		SecondsSinceDampingUpdate = 0.0f;
		DampingEstimationNeedsUpdate = false;
	}
}

void UAkAcousticTextureSetComponent::SetReverbDescriptor(FAkReverbDescriptor* reverbDescriptor)
{
	ReverbDescriptor = reverbDescriptor;
#if WITH_EDITOR
	UnregisterTextureParamChangeCallbacks();
	if (reverbDescriptor != nullptr)
		RegisterAllTextureParamCallbacks();
#endif
	if (reverbDescriptor != nullptr)
		RecalculateHFDamping();
}

void UAkAcousticTextureSetComponent::RecalculateHFDamping()
{
	if (ReverbDescriptor != nullptr && ReverbDescriptor->ShouldEstimateDamping())
	{
		ReverbDescriptor->CalculateHFDamping(this);
		SecondsSinceDampingUpdate = 0.0f;
	}
}

#if WITH_EDITOR
void UAkAcousticTextureSetComponent::BeginDestroy()
{
	Super::BeginDestroy();
	if (AkSpatialAudioHelper::GetObjectReplacedEvent())
	{
		AkSpatialAudioHelper::GetObjectReplacedEvent()->RemoveAll(this);
	}
}

void UAkAcousticTextureSetComponent::HandleObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	if (ReplacementMap.Contains(this))
	{
		UAkAcousticTextureSetComponent* NewTextureSetComponent = Cast<UAkAcousticTextureSetComponent>(ReplacementMap[this]);
		if (USceneComponent* Parent = NewTextureSetComponent->GetAttachParent())
		{
			if (UAkLateReverbComponent* ReverbComp = AkComponentHelpers::GetChildComponentOfType<UAkLateReverbComponent>(*Parent))
			{
				ReverbComp->AssociateAkTextureSetComponent(NewTextureSetComponent);
			}
		}
	}
}

void UAkAcousticTextureSetComponent::RegisterReverbRTPCChangedCallback()
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (RTPCChangedHandle.IsValid())
			AkSettings->OnReverbRTPCChanged.Remove(RTPCChangedHandle);
		RTPCChangedHandle = AkSettings->OnReverbRTPCChanged.AddLambda([this]()
		{
			RecalculateHFDamping();
		});
	}
}

void UAkAcousticTextureSetComponent::RegisterTextureParamChangeCallback(FGuid textureID)
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		if (TextureDelegateHandles.Find(textureID) != nullptr)
		{
			if (TextureDelegateHandles[textureID].IsValid())
				AkSettings->OnTextureParamsChanged.Remove(TextureDelegateHandles[textureID]);
			TextureDelegateHandles.Remove(textureID);
		}
		TextureDelegateHandles.Add(textureID, AkSettings->OnTextureParamsChanged.AddLambda([&](const FGuid& textureID)
		{
			if (ContainsTexture(textureID) && ReverbDescriptor != nullptr)
				DampingEstimationNeedsUpdate = ReverbDescriptor->ShouldEstimateDamping();
		}));
	}
}

void UAkAcousticTextureSetComponent::UnregisterTextureParamChangeCallbacks()
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		for (auto it = TextureDelegateHandles.CreateIterator(); it; ++it)
		{
			if (it->Value.IsValid())
				AkSettings->OnTextureParamsChanged.Remove(it->Value);
		}
		TextureDelegateHandles.Empty();
	}
}
#endif

bool UAkAcousticTextureSetComponent::ShouldSendGeometry() const
{
	UWorld* CurrentWorld = GetWorld();
	if (CurrentWorld && !IsRunningCommandlet())
	{
		return CurrentWorld->WorldType == EWorldType::Game || CurrentWorld->WorldType == EWorldType::PIE;
	}
	return false;
}

void UAkAcousticTextureSetComponent::SendGeometryToWwise(const AkGeometryParams& params)
{
	if (ShouldSendGeometry())
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice != nullptr && AkAudioDevice->SetGeometry(GetGeometrySetID(), params) == AK_Success)
			GeometryHasBeenSent = true;
	}
}

void UAkAcousticTextureSetComponent::RemoveGeometryFromWwise()
{
	if (ShouldSendGeometry() && GeometryHasBeenSent)
	{
		FAkAudioDevice* AkAudioDevice = FAkAudioDevice::Get();
		if (AkAudioDevice != nullptr && AkAudioDevice->RemoveGeometrySet(GetGeometrySetID()) == AK_Success)
			GeometryHasBeenSent = false;
	}
}
