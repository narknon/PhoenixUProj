#pragma once
#include "CoreMinimal.h"
#include "EEnemy_Context.generated.h"

UENUM(BlueprintType)
enum class EEnemy_Context : uint8 {
    HighHealth,
    LowHealth,
    SuccessfulAttack,
    TargetDead,
    LowEnergy,
    TeammateSuccessfulAttack,
    EEnemy_MAX UMETA(Hidden),
};

