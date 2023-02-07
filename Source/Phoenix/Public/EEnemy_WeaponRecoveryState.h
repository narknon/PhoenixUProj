#pragma once
#include "CoreMinimal.h"
#include "EEnemy_WeaponRecoveryState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_WeaponRecoveryState : uint8 {
    None,
    WaitForActionToStart,
    StartRecovery,
    MoveToLocation,
    PickupWeapon,
    FinalizeRecovery,
    Done,
    EEnemy_MAX UMETA(Hidden),
};

