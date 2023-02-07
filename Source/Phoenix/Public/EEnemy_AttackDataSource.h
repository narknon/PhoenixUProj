#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackDataSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackDataSource : uint8 {
    Choose,
    Attack,
    Count,
    EEnemy_MAX UMETA(Hidden),
};

