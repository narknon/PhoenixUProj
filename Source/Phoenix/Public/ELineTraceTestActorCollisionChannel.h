#pragma once
#include "CoreMinimal.h"
#include "ELineTraceTestActorCollisionChannel.generated.h"

UENUM(BlueprintType)
enum class ELineTraceTestActorCollisionChannel : uint8 {
    WorldStatic,
    WorldDynamic,
    Pawn,
    Visibility,
    Camera,
    PhysicsBody,
    Vehicle,
    Destructible,
    ShallowWater,
    SphereTracer,
    LedgeTrace,
    Spell,
    Station,
    DeepWater,
    Weapon,
    WebbedObject,
    Audio_Volume,
    GameVolume,
    FootIK,
    PlayerOnly,
    FluidSim,
    MapTrace,
    InteractBlocker,
    NavMarkup,
    Station_Static,
    AimConeCheck,
    EdgeCheck,
};

