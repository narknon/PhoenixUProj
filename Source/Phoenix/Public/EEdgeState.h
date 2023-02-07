#pragma once
#include "CoreMinimal.h"
#include "EEdgeState.generated.h"

UENUM(BlueprintType)
namespace EEdgeState {
    enum Type {
        None,
        FirmlyOnGround,
        EdgeBlocked,
        SlightlyOverEdge,
        FullyPastEdge,
        MovingBackToEdge,
    };
}

