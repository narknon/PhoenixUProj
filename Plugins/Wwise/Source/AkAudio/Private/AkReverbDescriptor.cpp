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

#include "AkReverbDescriptor.h"
#include <AK/SpatialAudio/Common/AkReverbEstimation.h>
#include "AkAudioDevice.h"
#include "AkAcousticTextureSetComponent.h"
#include "AkLateReverbComponent.h"
#include "AkRoomComponent.h"
#include "AkComponentHelpers.h"
#include "AkSettings.h"

#include "Components/PrimitiveComponent.h"
#include "Rendering/PositionVertexBuffer.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/BrushComponent.h"

#include "PhysicsEngine/BodySetup.h"
#include "PhysicsEngine/ConvexElem.h"

#if PHYSICS_INTERFACE_PHYSX
#include "PhysXIncludes.h"
#endif

/*=============================================================================
	Volume & Area Helpers
=============================================================================*/

// FKBoxElem has its own GetVolume function but it is inaccurate. It uses scale.GetMin() rather than using element-wise multiplication.
float BoxVolume(const FKBoxElem& box, const FVector& scale)
{
	return (box.X * scale.X) * (box.Y * scale.Y) * (box.Z * scale.Z);
}
// This is the volume calculated by Unreal in UBodySetup::GetVolume, for box elements. We'll use this to subtract from the total volume, and add the more accurate volume calculated by BoxVolume, above.
float InaccurateBoxVolume(const FKBoxElem& box, const FVector& scale)
{
	float MinScale = scale.GetMin();
	return (box.X * MinScale) * (box.Y * MinScale) * (box.Z * MinScale);
}

float BoxSurfaceArea(const FKBoxElem& box, const FVector& scale)
{
	return box.X * scale.X * box.Y * scale.Y * 2.0f /* top & bottom */
		+ box.X * scale.X * box.Z * scale.Z * 2.0f /* left & right */
		+ box.Y * scale.Y * box.Z * scale.Z * 2.0f; /* front & back */
}

float SphereSurfaceArea(const FKSphereElem& sphere, const FVector& scale)
{
	return 4.0f * PI * FMath::Pow(sphere.Radius * scale.GetMin(), 2.0f);
}

float CapsuleSurfaceArea(const FKSphylElem& capsule, const FVector& scale)
{
	const float r = capsule.Radius * FMath::Min(scale.X, scale.Y);
	return 2.0f * PI * r * (2.0f * r + capsule.Length * scale.Z);
}

bool HasSimpleCollisionGeometry(UBodySetup* bodySetup)
{
	FKAggregateGeom geometry = bodySetup->AggGeom;
	return geometry.BoxElems.Num() > 0 || geometry.ConvexElems.Num() > 0 || geometry.SphereElems.Num() > 0 || geometry.TaperedCapsuleElems.Num() > 0 || geometry.SphylElems.Num() > 0;

}

#if WITH_CHAOS
// Copied from BodySetup.cpp
// References: 
// http://amp.ece.cmu.edu/Publication/Cha/icip01_Cha.pdf
// http://stackoverflow.com/questions/1406029/how-to-calculate-the-volume-of-a-3d-mesh-object-the-surface-of-which-is-made-up
float SignedVolumeOfTriangle(const FVector& p1, const FVector& p2, const FVector& p3)
{
	return FVector::DotProduct(p1, FVector::CrossProduct(p2, p3)) / 6.0f;
}
#endif

void UpdateVolumeAndArea(UBodySetup* bodySetup, const FVector& scale, float& volume, float& surfaceArea)
{
	surfaceArea = 0.0f;
	// Initially use the Unreal UBodySetup::GetVolume function to calculate volume...
	volume = bodySetup->GetVolume(scale);
	FKAggregateGeom& geometry = bodySetup->AggGeom;

	for (const FKBoxElem& box : geometry.BoxElems)
	{
		surfaceArea += BoxSurfaceArea(box, scale);
		// ... correct for any FKBoxElem elements in the geometry.
		// UBodySetup::GetVolume has an inaccuracy for box elements. It is scaled uniformly by the minimum scale dimension (see FKBoxElem::GetVolume).
		// For our purposes we want to scale by each dimension individually.
		volume -= InaccurateBoxVolume(box, scale);
		volume += BoxVolume(box, scale);
	}
	for (const FKConvexElem& convexElem : geometry.ConvexElems)
	{
		FTransform ScaleTransform = FTransform(FQuat::Identity, FVector::ZeroVector, scale);

		int32 numTriangles = convexElem.IndexData.Num() / 3;
		for (int32 triIdx = 0; triIdx < numTriangles; ++triIdx)
		{
			FVector v0 = ScaleTransform.TransformPosition(convexElem.VertexData[convexElem.IndexData[3 * triIdx]]);
			FVector v1 = ScaleTransform.TransformPosition(convexElem.VertexData[convexElem.IndexData[3 * triIdx + 1]]);
			FVector v2 = ScaleTransform.TransformPosition(convexElem.VertexData[convexElem.IndexData[3 * triIdx + 2]]);

			surfaceArea += FAkReverbDescriptor::TriangleArea(v0, v1, v2);
#if WITH_CHAOS
			// FKConvexElem::GetVolume is not implemented with Chaos
			// TODO: Remove the following when it is implemented in the future
			volume += SignedVolumeOfTriangle(v0, v1, v2);
#endif
		}
	}
	for (const FKSphereElem& sphere : geometry.SphereElems)
	{
		surfaceArea += SphereSurfaceArea(sphere, scale);
	}
	for (const FKSphylElem& capsule : geometry.SphylElems)
	{
		surfaceArea += CapsuleSurfaceArea(capsule, scale);
	}
}

/*=============================================================================
	FAkReverbDescriptor:
=============================================================================*/
double FAkReverbDescriptor::TriangleArea(const FVector& v1, const FVector& v2, const FVector& v3)
{
#if UE_5_0_OR_LATER
	double Mag = 0.0;
#else
	float Mag = 0.0f;
#endif
	FVector Dir;
	FVector::CrossProduct(v2 - v1, v3 - v1).ToDirectionAndLength(Dir, Mag);
	return 0.5 * Mag;
}

bool FAkReverbDescriptor::ShouldEstimateDecay() const
{
	if (IsValid(ReverbComponent) && ReverbComponent->AutoAssignAuxBus)
		return true;
	if (!IsValid(Primitive) || AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Primitive) == nullptr)
		return false;
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		return AkSettings->DecayRTPCInUse();
	}
	return false;
}

bool FAkReverbDescriptor::ShouldEstimateDamping() const
{
	if (!IsValid(Primitive) || AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Primitive) == nullptr)
		return false;
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		return AkSettings->DampingRTPCInUse();
	}
	return false;
}

bool FAkReverbDescriptor::ShouldEstimatePredelay() const
{
	if (!IsValid(Primitive) || AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Primitive) == nullptr)
		return false;
	const UAkSettings* AkSettings = GetDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		return AkSettings->PredelayRTPCInUse();
	}
	return false;
}

bool FAkReverbDescriptor::RequiresUpdates() const
{
	return ShouldEstimateDecay() || ShouldEstimateDamping() || ShouldEstimatePredelay();
}

void FAkReverbDescriptor::SetPrimitive(UPrimitiveComponent* primitive)
{
	Primitive = primitive;
}

void FAkReverbDescriptor::SetReverbComponent(UAkLateReverbComponent* reverbComp)
{
	ReverbComponent = reverbComp;
}

void FAkReverbDescriptor::CalculateT60()
{
	if (IsValid(Primitive))
	{
		PrimitiveVolume = 0.0f;
		PrimitiveSurfaceArea = 0.0f;
		T60Decay = 0.0f;
		if (Primitive != nullptr)
		{
			FVector scale = Primitive->GetComponentScale();
			UBodySetup* primitiveBody = Primitive->GetBodySetup();
			if (primitiveBody != nullptr && HasSimpleCollisionGeometry(primitiveBody))
			{
				UpdateVolumeAndArea(primitiveBody, scale, PrimitiveVolume, PrimitiveSurfaceArea);
			}
			else
			{
				if (UBrushComponent* brush = Cast<UBrushComponent>(Primitive))
				{
					brush->BuildSimpleBrushCollision();
				}
				else
				{
					FString PrimitiveName = "";
					Primitive->GetName(PrimitiveName);
					FString ActorName = "";
					AActor* owner = Primitive->GetOwner();
					if (owner != nullptr)
						owner->GetName(ActorName);
					UE_LOG(LogAkAudio, Warning,
						TEXT("Primitive component %s on actor %s has no simple collision geometry.%sCalculations for reverb aux bus assignment will use component bounds. This could be less accurate than using simple collision geometry."),
						*PrimitiveName, *ActorName, LINE_TERMINATOR);
					// only apply scale to local bounds to calculate volume and surface area.
					FTransform transform = Primitive->GetComponentTransform();
					transform.SetRotation(FQuat::Identity);
					transform.SetLocation(FVector::ZeroVector);
					FBoxSphereBounds bounds = Primitive->CalcBounds(transform);
					FVector boxDimensions = bounds.BoxExtent * 2.0f;
					PrimitiveVolume = boxDimensions.X * boxDimensions.Y * boxDimensions.Z;
					PrimitiveSurfaceArea += boxDimensions.X * boxDimensions.Y * 2.0f;
					PrimitiveSurfaceArea += boxDimensions.X * boxDimensions.Z * 2.0f;
					PrimitiveSurfaceArea += boxDimensions.Y * boxDimensions.Z * 2.0f;
				}
			}

			PrimitiveVolume = FMath::Abs(PrimitiveVolume) / AkComponentHelpers::UnrealUnitsPerCubicMeter(Primitive);
			PrimitiveSurfaceArea /= AkComponentHelpers::UnrealUnitsPerSquaredMeter(Primitive);

			if (PrimitiveVolume > 0.0f && PrimitiveSurfaceArea > 0.0f)
			{
				float absorption = 0.5f;
				UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
				if (AkSettings != nullptr)
					absorption = AkSettings->GlobalDecayAbsorption;
				//calcuate t60 using the Sabine equation
				AK::SpatialAudio::ReverbEstimation::EstimateT60Decay(PrimitiveVolume, PrimitiveSurfaceArea, absorption, T60Decay);
			}
		}
	}
#if WITH_EDITOR
	if (IsValid(ReverbComponent))
		ReverbComponent->UpdateDecayEstimation(T60Decay, PrimitiveVolume, PrimitiveSurfaceArea);
#endif
	UpdateDecayRTPC();
}

void FAkReverbDescriptor::CalculateTimeToFirstReflection()
{
	if (IsValid(Primitive))
	{
		FTransform transform = Primitive->GetComponentTransform();
		transform.SetRotation(FQuat::Identity);
		transform.SetLocation(FVector::ZeroVector);
		FBoxSphereBounds bounds = Primitive->CalcBounds(transform);
		AkVector extentMeters = FAkAudioDevice::FVectorToAKVector(bounds.BoxExtent / AkComponentHelpers::UnrealUnitsPerMeter(Primitive)); // Potential loss of precision here. Also, shouldn't it use FVectorToAKExtent?
		AK::SpatialAudio::ReverbEstimation::EstimateTimeToFirstReflection(extentMeters, TimeToFirstReflection);
	}
#if WITH_EDITOR
	if (IsValid(ReverbComponent))
		ReverbComponent->UpdatePredelayEstimation(TimeToFirstReflection);
#endif
	UpdatePredelaytRTPC();
}

void FAkReverbDescriptor::CalculateHFDamping(const UAkAcousticTextureSetComponent* acousticTextureSetComponent)
{
	HFDamping = 0.0f;
	if (IsValid(Primitive))
	{
		const UAkSettings* AkSettings = GetDefault<UAkSettings>();
		if (AkSettings != nullptr)
		{
			TArray<FAkAcousticTextureParams> texturesParams;
			TArray<float> surfaceAreas;
			acousticTextureSetComponent->GetTexturesAndSurfaceAreas(texturesParams, surfaceAreas);
			TArray<AkAcousticTexture> textures;
			for (const FAkAcousticTextureParams& params : texturesParams)
			{
				AkAcousticTexture texture;
				texture.fAbsorptionLow = params.AbsorptionLow();
				texture.fAbsorptionMidLow = params.AbsorptionMidLow();
				texture.fAbsorptionMidHigh = params.AbsorptionMidHigh();
				texture.fAbsorptionHigh = params.AbsorptionHigh();
				textures.Add(texture);
			}
			const int numTextures = textures.Num();
			if (numTextures == 0)
				HFDamping = 0.0f;
			else
				AK::SpatialAudio::ReverbEstimation::EstimateHFDamping(&textures[0], &surfaceAreas[0], textures.Num(), HFDamping);
		}
	}
#if WITH_EDITOR
	if (IsValid(ReverbComponent))
		ReverbComponent->UpdateHFDampingEstimation(HFDamping);
#endif
	UpdateDampingRTPC();
}

bool FAkReverbDescriptor::GetRTPCRoom(UAkRoomComponent*& room) const
{
	if (!IsValid(Primitive))
		return false;

	room = AkComponentHelpers::GetChildComponentOfType<UAkRoomComponent>(*Primitive);
	if (!CanSetRTPCOnRoom(room))
	{
		room = nullptr;
	}

	return room != nullptr;
}

bool FAkReverbDescriptor::CanSetRTPCOnRoom(const UAkRoomComponent* room) const
{
	if (FAkAudioDevice::Get() == nullptr
		|| room == nullptr
		|| !room->HasBeenRegisteredWithWwise()
		|| room->GetWorld() == nullptr
		|| (room->GetWorld()->WorldType != EWorldType::Game && room->GetWorld()->WorldType != EWorldType::PIE))
	{
		return false;
	}
	return true;
}

void FAkReverbDescriptor::UpdateDecayRTPC() const
{
	UAkRoomComponent* room = nullptr;
	if (GetRTPCRoom(room))
	{
		const UAkSettings* AkSettings = GetDefault<UAkSettings>();
		if (AkSettings != nullptr && AkSettings->ReverbRTPCsInUse())
		{
			room->SetRTPCValue(AkSettings->DecayEstimateRTPC.LoadSynchronous(), T60Decay, 0, AkSettings->DecayEstimateName);
		}
	}
}

void FAkReverbDescriptor::UpdateDampingRTPC() const
{
	UAkRoomComponent* room = nullptr;
	if (GetRTPCRoom(room))
	{
		const UAkSettings* AkSettings = GetDefault<UAkSettings>();
		if (AkSettings != nullptr && AkSettings->ReverbRTPCsInUse())
		{
			room->SetRTPCValue(AkSettings->HFDampingRTPC.LoadSynchronous(), HFDamping, 0, *AkSettings->HFDampingName);
		}
	}
}

void FAkReverbDescriptor::UpdatePredelaytRTPC() const
{
	UAkRoomComponent* room = nullptr;
	if (GetRTPCRoom(room))
	{
		const UAkSettings* AkSettings = GetDefault<UAkSettings>();
		if (AkSettings != nullptr && AkSettings->ReverbRTPCsInUse())
		{
			room->SetRTPCValue(AkSettings->TimeToFirstReflectionRTPC.LoadSynchronous(), TimeToFirstReflection, 0, *AkSettings->TimeToFirstReflectionName);
		}
	}
}

void FAkReverbDescriptor::UpdateAllRTPCs(const UAkRoomComponent* room) const
{
	AKASSERT(room != nullptr);

	if (CanSetRTPCOnRoom(room))
	{
		const UAkSettings* AkSettings = GetDefault<UAkSettings>();
		if (AkSettings != nullptr && AkSettings->ReverbRTPCsInUse())
		{
			if ((ReverbComponent != nullptr && ReverbComponent->AutoAssignAuxBus) || AkSettings->DecayRTPCInUse())
			{
				room->SetRTPCValue(AkSettings->DecayEstimateRTPC.LoadSynchronous(), T60Decay, 0, AkSettings->DecayEstimateName);
			}

			if (AkSettings->DampingRTPCInUse())
			{
				room->SetRTPCValue(AkSettings->HFDampingRTPC.LoadSynchronous(), HFDamping, 0, *AkSettings->HFDampingName);
			}

			if (AkSettings->PredelayRTPCInUse())
			{
				room->SetRTPCValue(AkSettings->TimeToFirstReflectionRTPC.LoadSynchronous(), TimeToFirstReflection, 0, *AkSettings->TimeToFirstReflectionName);
			}
		}
	}
}
