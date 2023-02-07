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

#include "Math/GenericOctree.h"
#include "AkUEFeatures.h"
#include "Components/SceneComponent.h"
#include "EngineDefines.h"

class UAkEnvironmentOctree;

#if UE_4_26_OR_LATER
#define AK_OCTREE_TYPE TOctree2
#define AK_OCTREE_ELEMENT_ID FOctreeElementId2
#else
#define AK_OCTREE_TYPE TOctree
#define AK_OCTREE_ELEMENT_ID FOctreeElementId
#endif

struct FAkEnvironmentOctreeElement
{
	USceneComponent* Component;

	FBoxCenterAndExtent BoundingBox;

	FAkEnvironmentOctreeElement(USceneComponent* in_Component)
	{
		Component = in_Component;
		BoundingBox = FBoxCenterAndExtent(Component->Bounds.GetBox().GetCenter(), Component->Bounds.GetBox().GetExtent());
	}
};

struct FAkEnvironmentOctreeSemantics
{
	typedef AK_OCTREE_TYPE<FAkEnvironmentOctreeElement, FAkEnvironmentOctreeSemantics> FOctree;

	enum { MaxElementsPerLeaf = 16 };
	enum { MinInclusiveElementsPerNode = 7 };
	enum { MaxNodeDepth = 12 };

	typedef TInlineAllocator<MaxElementsPerLeaf> ElementAllocator;

	FORCEINLINE static FBoxCenterAndExtent GetBoundingBox(const FAkEnvironmentOctreeElement& Element)
	{
		return Element.BoundingBox;
	}

	FORCEINLINE static bool AreElementsEqual(const FAkEnvironmentOctreeElement& A, const FAkEnvironmentOctreeElement& B)
	{
		return (A.Component == B.Component);
	}

	static void SetElementId(FOctree& OctreeOwner, const FAkEnvironmentOctreeElement& Element, AK_OCTREE_ELEMENT_ID Id);
};

class UAkEnvironmentOctree : public AK_OCTREE_TYPE<FAkEnvironmentOctreeElement, FAkEnvironmentOctreeSemantics>
{
public:

	UAkEnvironmentOctree() : AK_OCTREE_TYPE<FAkEnvironmentOctreeElement, FAkEnvironmentOctreeSemantics>(FVector::ZeroVector, HALF_WORLD_MAX) {}

	TMap<uint32, AK_OCTREE_ELEMENT_ID> ObjectToOctreeId;
};

/** A spatial indexing data structure used to accelerate geometric queries. 
	Used for fast look up of UAkRoomComponents for Spatial Audio Rooms, and for UAkLateReverbComponents for auxiliary sends in Wwise.
*/
class FAkEnvironmentIndex
{
public:
	/**
		Query a world and location for an environmental rooms or late reverb components.
		Returns an array of components that overlap Location, sorted by decreasing priority.
	*/
	template <typename EnvironmentType>
	TArray<EnvironmentType*> Query(const FVector& Location, const UWorld* World)
	{
		TArray<EnvironmentType*> Result;

		TUniquePtr<UAkEnvironmentOctree>* Octree = Map.Find(World);

		if (Octree != nullptr)
		{
#if UE_4_26_OR_LATER
			FBoxCenterAndExtent BoxBounds(Location, FVector::ZeroVector);
			(*Octree)->FindElementsWithBoundsTest(BoxBounds, [&Result, Location](const FAkEnvironmentOctreeElement& Element)
				{
					EnvironmentType* Env = Cast<EnvironmentType>(Element.Component);
					if (Env &&
						Env->bEnable &&
						Env->HasEffectOnLocation(Location))
					{
						Result.Add(Env);
					}
				});
#else
			for (UAkEnvironmentOctree::TConstElementBoxIterator<>	It(**Octree, FBoxCenterAndExtent(Location, FVector(ForceInitToZero)));
				It.HasPendingElements();
				It.Advance())
			{
				const FAkEnvironmentOctreeElement& Element = It.GetCurrentElement();
				EnvironmentType* Env = Cast<EnvironmentType>(Element.Component);
				if (Env &&
					Env->bEnable &&
					Env->HasEffectOnLocation(Location))
				{
					Result.Add(Env);
				}
			}
#endif
		}

		// Sort the found Volumes
		if (Result.Num() > 1)
		{
			Result.Sort([](const EnvironmentType& A, const EnvironmentType& B)
				{
					return A.Priority > B.Priority;
				});
		}

		return Result;
	}

	/**
		Add a Component to the spatial index.
	*/
	void Add(USceneComponent* EnvironmentToAdd);
	
	/**
	 * Remove a Component from the spatial index.
	 */
	bool Remove(USceneComponent* EnvironmentToRemove);

	/**
	 * Update the bounds of a component that is already indexed. Must be called if the transform of the component changes.
	 */
	void Update(USceneComponent* EnvironmentToUpdate);

	/**
	 * Clear all components in the given World.
	 */
	void Clear(const UWorld* WorldToClear);

	/**
	 * Is the index empty for the given World.
	 */
	bool IsEmpty(const UWorld* World);

private:
	TMap<UWorld*, TUniquePtr<UAkEnvironmentOctree> > Map;
};
