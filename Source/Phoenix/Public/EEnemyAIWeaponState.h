#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIWeaponState.generated.h"

UENUM(BlueprintType)
namespace EEnemyAIWeaponState {
    enum Type {
        None,
        Active,
        Claimed,
        Stored,
        Munition,
    };
}

