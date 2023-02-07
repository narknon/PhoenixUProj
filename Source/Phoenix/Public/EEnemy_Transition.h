#pragma once
#include "CoreMinimal.h"
#include "EEnemy_Transition.generated.h"

UENUM(BlueprintType)
enum class EEnemy_Transition : uint8 {
    None,
    LosingTarget,
    StoreActiveWeapon,
    Wander,
    Stationary,
    KilledTarget,
    EEnemy_MAX UMETA(Hidden),
};

