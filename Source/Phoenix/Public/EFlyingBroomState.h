#pragma once
#include "CoreMinimal.h"
#include "EFlyingBroomState.generated.h"

UENUM(BlueprintType)
namespace EFlyingBroomState {
    enum Type {
        None,
        Flying,
        Strafe,
        BarrelRollLft,
        BarrelRollRht,
        AimMode,
        AftView,
        CombatMode,
        Boosting,
        Turbo,
        React,
    };
}

