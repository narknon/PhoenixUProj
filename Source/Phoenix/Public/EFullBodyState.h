#pragma once
#include "CoreMinimal.h"
#include "EFullBodyState.generated.h"

UENUM(BlueprintType)
namespace EFullBodyState {
    enum Type {
        None,
        Moving,
        Combat,
        FlooPowder,
        PortKey,
        Sprinting,
        Jumping,
        FireSpell,
        Blocking,
        Parrying,
        Climbing,
        ClimbingLadder,
        Falling,
        Dodging,
        Reacting,
        Teleporting,
        Harvesting,
        PlantSeed,
        StationInteract,
        PickupBucket,
        PutDownBucket,
        SpreadFeed,
        AncientMagic,
        StartCatchCarry,
        CatchCarry,
        StartCarry,
        EndCarry,
        Swimming,
        ButtSliding,
        OpeningChest,
        Cinematic,
        DodgeDucking,
        ShadowBlinking,
    };
}

