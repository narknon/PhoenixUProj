#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryButtonPressed.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryButtonPressed : uint8 {
    None,
    Parry,
    DodgeBlock,
    EEnemy_MAX UMETA(Hidden),
};

