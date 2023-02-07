#pragma once
#include "CoreMinimal.h"
#include "EClimbingLedgeState.generated.h"

UENUM(BlueprintType)
namespace EClimbingLedgeState {
    enum Type {
        None,
        ClimbingLedge_StepUp,
        ClimbingLedge_HalfM,
        ClimbingLedge_1M,
        ClimbingLedge_2M,
        ClimbingLedge_3M,
        ClimbingLedge_LandClimb,
        ClimbingLedge_LandHands,
        ClimbingLedge_LandHands_Outcrop,
        ClimbingLedge_LandWaist,
        ClimbingLedge_LandWaist_Outcrop,
        ClimbingLedge_JumpHands,
        ClimbingLedge_JumpHandsPullUp,
        ClimbingLedge_FallHands,
        ClimbingLedge_Leapfrog,
        ClimbingLedge_Swim,
        NUM,
    };
}

