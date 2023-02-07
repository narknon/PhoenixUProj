#pragma once
#include "CoreMinimal.h"
#include "ELandingType.generated.h"

UENUM(BlueprintType)
namespace ELandingType {
    enum Type {
        None,
        IdleLand,
        WalkingLand,
        JoggingLand,
        SprintingLand,
        LadderSlideLand,
        LadderJumpBottomLand,
    };
}

