#pragma once
#include "CoreMinimal.h"
#include "EEnemyWeaponEquip.generated.h"

UENUM(BlueprintType)
enum class EEnemyWeaponEquip : uint8 {
    None,
    Stored,
    Hidden,
};

