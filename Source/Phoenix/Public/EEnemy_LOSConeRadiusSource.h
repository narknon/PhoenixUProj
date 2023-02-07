#pragma once
#include "CoreMinimal.h"
#include "EEnemy_LOSConeRadiusSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_LOSConeRadiusSource : uint8 {
    CapsuleHalf,
    Custom,
    EEnemy_MAX UMETA(Hidden),
};

