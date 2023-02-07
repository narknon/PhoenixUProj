#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryWindowType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryWindowType : uint8 {
    None,
    Single,
    Dual,
    EEnemy_MAX UMETA(Hidden),
};

