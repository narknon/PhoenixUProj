#pragma once
#include "CoreMinimal.h"
#include "EMobilityState.generated.h"

UENUM(BlueprintType)
namespace EMobilityState {
    enum Type {
        None,
        Combat,
        Stealth,
        FlyingBroom,
    };
}

