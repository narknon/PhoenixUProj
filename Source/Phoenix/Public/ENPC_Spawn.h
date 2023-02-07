#pragma once
#include "CoreMinimal.h"
#include "ENPC_Spawn.generated.h"

UENUM(BlueprintType)
enum class ENPC_Spawn : uint8 {
    None,
    Default,
    Birth,
    BurrowUp,
    Descend,
    Apparate,
    Death,
    Smoke,
    CrackWall,
    CrackFloor,
    CrackStanding,
    OnBack,
    GroundOnFront,
    GroundOnBack,
    BurstOut,
    Fall,
    WallStepDown,
    Freeze,
    Petrified,
    JumpDown,
    Animagus,
    Spline,
    Hidden,
    Asleep,
    SplineSmoke,
    JumpSpline,
    Climb,
    AncientMagic,
    Reflection,
    InkySmoke,
    FromStone,
    SlowStand,
    BossSpawn,
    WipeIn,
    ENPC_MAX UMETA(Hidden),
};

