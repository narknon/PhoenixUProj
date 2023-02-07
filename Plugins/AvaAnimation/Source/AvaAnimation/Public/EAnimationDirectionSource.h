#pragma once
#include "CoreMinimal.h"
#include "EAnimationDirectionSource.generated.h"

UENUM(BlueprintType)
enum class EAnimationDirectionSource : uint8 {
    Gameplay,
    TargetTracker,
    PickupObject,
    CharacterOptions,
    SceneRig,
    SceneRigActive,
    Highest,
    SourceCount,
};

