#pragma once
#include "CoreMinimal.h"
#include "EAblCollisionBranchDetectionType.generated.h"

UENUM(BlueprintType)
enum class EAblCollisionBranchDetectionType : uint8 {
    MoveDirectionDotHitNormal,
    MoveDirectionDotUpVector,
    HitNormalDotUpVector,
};

