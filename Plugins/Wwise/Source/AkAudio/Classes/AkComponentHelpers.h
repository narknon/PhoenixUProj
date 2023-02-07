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
	AkComponentHelpers.h:
=============================================================================*/
#pragma once
#include "PhysicsEngine/BodySetup.h"
#include <AK/SoundEngine/Common/AkTypes.h>
#include <AkInclude.h>

namespace AkComponentHelpers
{
	/* Return true if the bodySetup has simple collision */
	AKAUDIO_API bool HasSimpleCollisionGeometry(const UBodySetup* bodySetup);
	
	/* Return true if the Point lies within the Primitive component. SphereRadius provides a margin of error for containment.
	   If OutDistanceToPoint is non-null it will be given the distance from Point to a point on the Primitive component. */
	AKAUDIO_API bool EncompassesPoint(UPrimitiveComponent& Primitive, FVector Point, float SphereRadius = 0.f, float* OutDistanceToPoint = nullptr);
	
	/* Return the unreal-units-to-meters ratio being used by this component */
	AKAUDIO_API float UnrealUnitsPerMeter(const UActorComponent* component);

	/* Return the square of the unreal-units-to-meters ratio being used by this component */
	AKAUDIO_API float UnrealUnitsPerSquaredMeter(const UActorComponent* component);

	/* Return the cube of the unreal-units-to-meters ratio being used by this component */
	AKAUDIO_API float UnrealUnitsPerCubicMeter(const UActorComponent* component);

	/* Convenience function for components based on AActor::FindComponentByClass. 
	   Return the first child component of type COMPONENT_TYPE, or nullptr if there are none. */
	template<class COMPONENT_TYPE>
	AKAUDIO_API COMPONENT_TYPE* GetChildComponentOfType(const USceneComponent& ParentComponent)
	{
		const TArray<USceneComponent*> parentChildren = ParentComponent.GetAttachChildren();

		for (auto* const child : parentChildren)
		{
			if (child && child->IsA<COMPONENT_TYPE>())
			{
				return Cast<COMPONENT_TYPE>(child);
			}
		}
		return nullptr;
	}
	 
	AKAUDIO_API bool IsInGameWorld(const UActorComponent* InComponent);

	/**/
	AKAUDIO_API void GetPrimitiveTransformAndExtent(const UPrimitiveComponent& Primitive, AkTransform& transform, AkExtent& extent);
	AKAUDIO_API void GetPrimitiveUpAndFront(const UPrimitiveComponent& Primitive, AkVector& Up, AkVector& Front);

	/* Return true if the movement would reset the child to (0, 0, 0) locally, with respect to the parent position. Return false otherwise.*/
	AKAUDIO_API bool DoesMovementRecenterChild(USceneComponent* child, USceneComponent* parent, const FVector& Delta);
	
	/* Log an error for invalid parent type */
	AKAUDIO_API void LogAttachmentError(const UActorComponent* child, const UActorComponent* parent, const FString& requiredClassName);
	
	/* Log a warning that parent has no simple geometry, so child will use component bounds */
	AKAUDIO_API void LogSimpleGeometryWarning(const UPrimitiveComponent* parent, const UActorComponent* child);

#if WITH_EDITOR
	/*  IsGameWorldBlueprintComponent() and ShouldDeferBeginPlay() are used to deal with a specific edge case concerning
		Blueprint classes: For Blueprint class components, during Super::PostEditChangeProperty(), the component is
		replaced with a new instance, and PostEditChangeProperty() is called on the old instance.
		In our case this can lead to issues when we update Wwise from PostEditChangeProperty(). For example, duplicate
		rooms or geometry could be sent. This check should be used to make sure we don't update Wwise in this scenario.
		*/
	AKAUDIO_API bool IsGameWorldBlueprintComponent(const UActorComponent* InComponent);
	/*  IsGameWorldBlueprintComponent() and ShouldDeferBeginPlay() are used to deal with a specific edge case concerning
		Blueprint classes. For Blueprint class components, during Super::PostEditChangeProperty(), the component is
		replaced with a new instance.
		The duplicated component instance initially has default values for all UPROPERTY members.
		It is only later, after BeginPlay() has been called, that the values from the previous instance's UPROPERTYs are
		copied to the new instance! So in that case, we need to defer the BeginPlay logic that depends on UPROPERTY values
		that have been updated via user interaction, prior to the begin play call.
		*/
	AKAUDIO_API bool ShouldDeferBeginPlay(const UActorComponent* InComponent);
#endif
}