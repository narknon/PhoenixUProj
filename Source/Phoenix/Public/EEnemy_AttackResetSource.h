#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackResetSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackResetSource : uint8 {
    Normal,
    AttackSplit,
    EEnemy_MAX UMETA(Hidden),
};

