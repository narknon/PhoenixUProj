#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackExecuteType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackExecuteType : uint8 {
    None,
    Default,
    RunTo,
    DeferredEquip,
    EEnemy_MAX UMETA(Hidden),
};

