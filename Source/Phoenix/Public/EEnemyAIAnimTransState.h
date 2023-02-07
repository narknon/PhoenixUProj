#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIAnimTransState.generated.h"

UENUM(BlueprintType)
namespace EEnemyAIAnimTransState {
    enum Type {
        None,
        IdleStart,
        IdleBlended,
        LocomotionStart,
        LocomotionBlended,
    };
}

