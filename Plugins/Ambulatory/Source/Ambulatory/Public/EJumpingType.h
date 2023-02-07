#pragma once
#include "CoreMinimal.h"
#include "EJumpingType.generated.h"

UENUM(BlueprintType)
namespace EJumpingType {
    enum Type {
        None,
        IdleJump,
        WalkingJump,
        JoggingJump,
        SprintingJump,
        Falling,
        Dropping,
        ClimbFail,
        JumpVault,
        JumpLedge2Vault,
        LadderSlide,
        LadderJumpBottom,
        Buttslide,
        SwimDive,
        SwimHighDive,
        JogJumpDown,
        SprintJumpDown,
    };
}

