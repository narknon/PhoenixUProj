#pragma once
#include "CoreMinimal.h"
#include "EInteractTurnToFaceRules.generated.h"

UENUM(BlueprintType)
enum class EInteractTurnToFaceRules : uint8 {
    None,
    PlayerToTarget,
    TargetToPlayer,
    TargetAxis,
};

