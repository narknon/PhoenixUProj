#pragma once
#include "CoreMinimal.h"
#include "EMobilityModeState.generated.h"

UENUM(BlueprintType)
namespace EMobilityModeState {
    enum Type {
        Invalid,
        FreeRoam,
        FreeRoamCombat,
        Strafe,
        StrafeCombat,
        Crawling,
        StrafeCombatAttack,
        StrafeCombatAttack2,
        StrafeCombatAttack3,
        Combat,
        Num_MobilityModes,
    };
}

