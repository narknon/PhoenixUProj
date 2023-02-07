#pragma once
#include "CoreMinimal.h"
#include "ECombatAdditiveState.generated.h"

UENUM(BlueprintType)
namespace ECombatAdditiveState {
    enum Type {
        None,
        Inactive,
        Active,
    };
}

