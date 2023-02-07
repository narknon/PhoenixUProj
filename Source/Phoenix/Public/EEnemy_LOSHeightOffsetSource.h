#pragma once
#include "CoreMinimal.h"
#include "EEnemy_LOSHeightOffsetSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_LOSHeightOffsetSource : uint8 {
    CapsuleHalf,
    Custom,
    EEnemy_MAX UMETA(Hidden),
};

