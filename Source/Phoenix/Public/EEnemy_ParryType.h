#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryType : uint8 {
    None,
    Melee,
    Ranged,
    Ballistic,
    Animation,
    Custom,
    RunTo,
    EEnemy_MAX UMETA(Hidden),
};

