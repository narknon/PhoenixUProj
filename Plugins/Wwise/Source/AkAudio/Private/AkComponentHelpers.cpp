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

#include "AkComponentHelpers.h"
#include "Components/PrimitiveComponent.h"
#include "AkAudioDevice.h"
#include "GameFramework/WorldSettings.h"

namespace AkComponentHelpers
{
	bool HasSimpleCollisionGeometry(const UBodySetup* bodySetup)
	{
		FKAggregateGeom geometry = bodySetup->AggGeom;
		return geometry.BoxElems.Num() > 0 || geometry.ConvexElems.Num() > 0 || geometry.SphereElems.Num() > 0 || geometry.TaperedCapsuleElems.Num() > 0 || geometry.SphylElems.Num() > 0;
	}

	bool EncompassesPoint(UPrimitiveComponent& Primitive, FVector Point, float SphereRadius /*= 0.f*/, float* OutDistanceToPoint /*= nullptr*/)
	{
		bool bUsePhysicsCollision = Primitive.GetOwner() != nullptr;
#ifndef WITH_PHYSX
		bUsePhysicsCollision = false;
#endif
		float DistanceSqr = 0.0f;
		const UBodySetup* bodySetup = Primitive.GetBodySetup();
		if (bodySetup == nullptr || !AkComponentHelpers::HasSimpleCollisionGeometry(bodySetup))
		{
			bUsePhysicsCollision = false;
		}
		if (bUsePhysicsCollision)
		{
			FVector ClosestPoint;

			if (Primitive.GetSquaredDistanceToCollision(Point, DistanceSqr, ClosestPoint) == false)
			{
				if (OutDistanceToPoint)
				{
					*OutDistanceToPoint = -1.f;
				}
				return false;
			}
		}
		else
		{
			// Just use simple bounds intersection. This will be less accurate, especially for complex-shaped non-box rooms.
			// Since bUseAttachParentBound = true, we can use Bounds here.
			DistanceSqr = Primitive.Bounds.GetBox().ComputeSquaredDistanceToPoint(Point);
		}
		if (OutDistanceToPoint)
		{
			*OutDistanceToPoint = FMath::Sqrt(DistanceSqr);
		}

		return DistanceSqr >= 0.f && DistanceSqr <= FMath::Square(SphereRadius);
	}

	float UnrealUnitsPerMeter(const UActorComponent* component)
	{
		const float defaultWorldToMetersRatio = 100.0f;
		
		if (component == nullptr)
			return defaultWorldToMetersRatio;
		
		if (component->GetWorld() == nullptr)
			return defaultWorldToMetersRatio;

		AWorldSettings* settings = component->GetWorld()->GetWorldSettings();
		if (settings == nullptr)
			return defaultWorldToMetersRatio;

		return settings->WorldToMeters;
	}

	float UnrealUnitsPerSquaredMeter(const UActorComponent* component)
	{
		return FMath::Pow(UnrealUnitsPerMeter(component), 2.0f);
	}

	float UnrealUnitsPerCubicMeter(const UActorComponent* component)
	{
		return FMath::Pow(UnrealUnitsPerMeter(component), 3.0f);
	}

	bool IsInGameWorld(const UActorComponent* InComponent)
	{
		UWorld* World = InComponent->GetWorld();
		if (World == nullptr)
			return false;
		return World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE;
	}

	AKAUDIO_API FBoxSphereBounds GetPrimitiveBoundsNoRotation(const UPrimitiveComponent& Primitive)
	{
		FTransform Transform(Primitive.GetComponentTransform());
		Transform.SetRotation(FQuat::Identity);
		return Primitive.CalcBounds(Transform);
	}

	void GetPrimitiveTransformAndExtent(const UPrimitiveComponent& Primitive, AkTransform& transform, AkExtent& extent)
	{
		FRotator rotation = Primitive.GetComponentRotation();

		FVector front = rotation.RotateVector(FVector::ForwardVector);
		FVector up = rotation.RotateVector(FVector::UpVector);

		AkVector Front, Up;
		FAkAudioDevice::FVectorToAKVector(front, Front);
		FAkAudioDevice::FVectorToAKVector(up, Up);
		transform.SetOrientation(Front, Up);

		FBoxSphereBounds primitiveBounds = GetPrimitiveBoundsNoRotation(Primitive);
		extent = FAkAudioDevice::FVectorToAkExtent(primitiveBounds.BoxExtent);
		AkVector Center;
		// For uniformly shaped primitives, primitiveBounds.Origin will be the same as the component position.
		// For complex meshes and brushes, there will be an offset.
		FAkAudioDevice::FVectorToAKVector(Primitive.Bounds.Origin, Center);
		transform.SetPosition(Center);
	}

	void GetPrimitiveUpAndFront(const UPrimitiveComponent& Primitive, AkVector& Up, AkVector& Front)
	{
		FRotator rotation = Primitive.GetComponentRotation();

		FVector front = rotation.RotateVector(FVector::ForwardVector);
		FVector up = rotation.RotateVector(FVector::UpVector);
				
		FAkAudioDevice::FVectorToAKVector(front, Front);
		FAkAudioDevice::FVectorToAKVector(up, Up);
	}

	bool DoesMovementRecenterChild(USceneComponent* child, USceneComponent* parent, const FVector& Delta)
	{
#if WITH_EDITOR
		// Only implement movement when it is to recentre component at local origin
		FVector direction;
		float length;
		FVector relativeDestination = child->GetRelativeLocation() + Delta;
		// When movement happens from OnRegister, after reparenting, GetRelativeLocation() can sometimes refer to the old parent,
		// because the private SceneComponent::RelativeLocation member has not been correctly updated yet for this frame.
		// This causes a local offset to be left applied to the component after it is reparented.
		// Therefore, use Parent, which will refer to the current attachment parent and use it to derive the correct relative location.
		if (parent != nullptr)
		{
			relativeDestination = (child->GetComponentLocation() + Delta) - parent->GetComponentLocation();
		}
		relativeDestination.ToDirectionAndLength(direction, length);
		if (length <= 0.01f)
			return true;
#endif //WITH_EDITOR
		return false;
	}

	void LogAttachmentError(const UActorComponent* child, const UActorComponent* parent, const FString& requiredClassName)
	{
		FString actorString = FString("NONE");
		if (child->GetOwner() != nullptr)
			actorString = child->GetOwner()->GetName();
		FString parentName = parent->GetName();
		FString parentClass = parent->GetClass()->GetName();
		FString childName = child->GetName();
		FString childClass = child->GetClass()->GetName();

		UE_LOG(LogAkAudio, Error,
			TEXT("On actor %s, there is a %s (%s) attached to parent of type %s (%s)."),
			*actorString, *childClass, *childName, *parentClass, *parentName);
		
		UE_LOG(LogAkAudio, Error, TEXT("%s requires to be nested under a component inheriting from %s."),
			*childClass, *requiredClassName);
	}

	void LogSimpleGeometryWarning(const UPrimitiveComponent* parent, const UActorComponent* child)
	{
		FString primitiveName = "";
		FString childName = "";
		parent->GetName(primitiveName);
		child->GetName(childName);
		FString actorName = "";
		AActor* owner = parent->GetOwner();
		if (owner != nullptr)
			owner->GetName(actorName);
		UE_LOG(LogAkAudio, Warning,
			TEXT("Primitive component %s on actor %s has no simple collision geometry.%sChild component %s will use component bounds for containment calculations. This could be less accurate than using simple collision geometry."),
			*primitiveName, *actorName, LINE_TERMINATOR, *childName);
	}

#if WITH_EDITOR
	bool IsGameWorldBlueprintComponent(const UActorComponent* InComponent)
	{
		// CreationMethod == EComponentCreationMethod::SimpleConstructionScript means the component was added as part of a blueprint class.
		return IsInGameWorld(InComponent) && InComponent->CreationMethod == EComponentCreationMethod::SimpleConstructionScript;
	}

	bool ShouldDeferBeginPlay(const UActorComponent* InComponent)
	{
		bool worldHasBegunPlay = InComponent->GetWorld() && InComponent->GetWorld()->HasBegunPlay();
		return IsGameWorldBlueprintComponent(InComponent) && worldHasBegunPlay;
	}
#endif
}
