#pragma once
#include "CoreMinimal.h"
#include "EEnemy_WeaponReleaseType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_WeaponReleaseType : uint8 {
    DisarmWeapon,
    DisarmShield,
    DropWeapon,
    DropShield,
    ThrowWeapon,
    ThrowTransientWeapon,
    DeathDisarmWeapon,
    DisarmWeaponForRecovery,
    EEnemy_MAX UMETA(Hidden),
};

