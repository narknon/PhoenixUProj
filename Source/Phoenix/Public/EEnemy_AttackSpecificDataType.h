#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackSpecificDataType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackSpecificDataType : uint8 {
    None,
    Ballistic,
    Flourish,
    RunTo,
    Apparate,
    EEnemy_MAX UMETA(Hidden),
};

