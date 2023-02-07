#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingFocusType.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingFocusType : uint8 {
    Undefined,
    Actor,
    SceneComponent,
    Fixed,
};

