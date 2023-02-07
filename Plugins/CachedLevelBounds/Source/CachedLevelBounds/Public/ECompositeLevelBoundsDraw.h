#pragma once
#include "CoreMinimal.h"
#include "ECompositeLevelBoundsDraw.generated.h"

UENUM(BlueprintType)
enum class ECompositeLevelBoundsDraw : uint8 {
    None,
    OverallBounds,
    ActorBounds,
    LandscapeBounds,
    LevelBoundsActors,
    CalculatedActorBounds,
};

