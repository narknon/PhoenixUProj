#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapInvert.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapInvert : uint8 {
    MeshObjectFilter,
    MeshTypeFilter,
    MeshTagFilter,
    ActorObjectFilter,
    ActorTypeFilter,
    ActorTagFilter,
    DependentSelection,
    DependentSelectionAttached,
    DependentActorObjectFilter,
    DependentActorTypeFilter,
    DependentActorTagFilter,
};

