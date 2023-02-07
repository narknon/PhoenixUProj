#pragma once
#include "CoreMinimal.h"
#include "EEnemy_TASTreeState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_TASTreeState : uint8 {
    None,
    AlertStart_W2Y,
    AggroStart_Y2R,
    EquipWeapon_Y2R,
    StoreWeapon_R2Y,
    AggroLost_R2Y,
    AlertLost_Y2W,
    EEnemy_MAX UMETA(Hidden),
};

