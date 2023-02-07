#pragma once
#include "CoreMinimal.h"
#include "EAblNpcCollisionDetectionType.generated.h"

UENUM(BlueprintType)
enum class EAblNpcCollisionDetectionType : uint8 {
    MoveDirectionDotHitNormal,
    MoveDirectionDotUpVector,
    HitNormalDotUpVector,
};

