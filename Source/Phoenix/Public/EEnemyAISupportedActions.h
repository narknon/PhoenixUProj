#pragma once
#include "CoreMinimal.h"
#include "EEnemyAISupportedActions.generated.h"

UENUM(BlueprintType)
enum class EEnemyAISupportedActions : uint8 {
    React,
    Spawn,
    Attack,
    BecomeAware,
    LoseAware,
    ActivateStoredWeapon,
    StoreActiveWeapon,
    PickupWeaponFloor,
    PickupWeaponWall,
    DodgeLeft,
    DodgeRight,
    Disappear,
    Reappear,
    Taunt,
    FleeExit,
    InvestigateAlert,
};

