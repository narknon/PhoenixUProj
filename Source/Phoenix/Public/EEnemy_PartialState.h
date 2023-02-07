#pragma once
#include "CoreMinimal.h"
#include "EEnemy_PartialState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_PartialState : uint8 {
    None,
    WandActive,
    ShieldActive,
    EEnemy_MAX UMETA(Hidden),
};

