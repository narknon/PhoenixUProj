#pragma once
#include "CoreMinimal.h"
#include "EEnemy_TargetType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_TargetType : uint8 {
    None,
    Attack,
    Flee,
    EEnemy_MAX UMETA(Hidden),
};

