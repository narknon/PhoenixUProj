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


#include "AkEnvironmentIndex.h"
#include "AkAudioDevice.h"

void FAkEnvironmentOctreeSemantics::SetElementId(AK_OCTREE_TYPE<FAkEnvironmentOctreeElement, FAkEnvironmentOctreeSemantics>& OctreeOwner, const FAkEnvironmentOctreeElement& Element, AK_OCTREE_ELEMENT_ID Id)
{
	static_cast<UAkEnvironmentOctree&>(OctreeOwner).ObjectToOctreeId.Add(Element.Component->GetUniqueID(), Id);
}

void FAkEnvironmentIndex::Add(USceneComponent* EnvironmentToAdd)
{
	UWorld* CurrentWorld = EnvironmentToAdd->GetWorld();
	TUniquePtr<UAkEnvironmentOctree>& Octree = Map.FindOrAdd(CurrentWorld);
	
	if (Octree == nullptr)
	{
		Octree = MakeUnique<UAkEnvironmentOctree>();
	}

	if (Octree != nullptr)
	{
		FAkEnvironmentOctreeElement Element(EnvironmentToAdd);
		Octree->AddElement(Element);
	}
}

bool FAkEnvironmentIndex::Remove(USceneComponent* EnvironmentToRemove)
{
	UWorld* CurrentWorld = EnvironmentToRemove->GetWorld();
	TUniquePtr<UAkEnvironmentOctree>* Octree = Map.Find(CurrentWorld);

	if (Octree != nullptr && EnvironmentToRemove != nullptr)
	{
		AK_OCTREE_ELEMENT_ID* Id = (*Octree)->ObjectToOctreeId.Find(EnvironmentToRemove->GetUniqueID());
		if (Id != nullptr && (*Octree)->IsValidElementId(*Id))
		{
			(*Octree)->RemoveElement(*Id);
		}

		(*Octree)->ObjectToOctreeId.Remove(EnvironmentToRemove->GetUniqueID());
		return true;
	}

	return false;
}

void FAkEnvironmentIndex::Update(USceneComponent* Environment)
{
	Remove(Environment);
	Add(Environment);
}

void FAkEnvironmentIndex::Clear(const UWorld* World)
{
	Map.Remove(World);
}

bool FAkEnvironmentIndex::IsEmpty(const UWorld* World)
{
	TUniquePtr<UAkEnvironmentOctree>* Octree = Map.Find(World);
	return Octree == nullptr;
}
