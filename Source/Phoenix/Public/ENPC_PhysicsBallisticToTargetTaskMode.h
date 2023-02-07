#pragma once
#include "CoreMinimal.h"
#include "ENPC_PhysicsBallisticToTargetTaskMode.generated.h"

UENUM(BlueprintType)
enum class ENPC_PhysicsBallisticToTargetTaskMode : uint8 {
    Start,
    Update,
    StartAndUpdate,
    Reset,
    StartUpdateAndReset,
    ENPC_MAX UMETA(Hidden),
};

