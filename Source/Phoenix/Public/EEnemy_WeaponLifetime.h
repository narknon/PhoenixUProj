#pragma once
#include "CoreMinimal.h"
#include "EEnemy_WeaponLifetime.generated.h"

UENUM(BlueprintType)
enum class EEnemy_WeaponLifetime : uint8 {
    None,
    Throw,
    Drop,
    Protego,
    EEnemy_MAX UMETA(Hidden),
};

