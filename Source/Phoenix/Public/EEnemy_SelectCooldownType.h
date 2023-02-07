#pragma once
#include "CoreMinimal.h"
#include "EEnemy_SelectCooldownType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_SelectCooldownType : uint8 {
    Immediate,
    Increment,
    EEnemy_MAX UMETA(Hidden),
};

