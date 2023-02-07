#pragma once
#include "CoreMinimal.h"
#include "EEnemy_BuffType_DEPRECATED.generated.h"

UENUM(BlueprintType)
enum class EEnemy_BuffType_DEPRECATED : uint8 {
    None_DEPRECATED,
    Health_DEPRECATED,
    WeaponRespawn_DEPRECATED,
    WeaponPowerup_DEPRECATED,
    EEnemy_BuffType_MAX UMETA(Hidden),
};

