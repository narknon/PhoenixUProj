#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackSource : uint8 {
    Normal,
    Split,
    Counter,
    EEnemy_MAX UMETA(Hidden),
};

