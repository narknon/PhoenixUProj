#pragma once
#include "CoreMinimal.h"
#include "ELineTraceTestActorObjectTypeQuery.generated.h"

UENUM(BlueprintType)
enum class ELineTraceTestActorObjectTypeQuery : uint8 {
    WorldStatic,
    WorldDynamic,
    Pawn,
    PhysicsBody,
    Vehicle,
    Destructible,
    ShallowWater,
    SphereTracer,
    Spell,
    Station,
    DeepWater,
    Weapon,
    WebbedObject,
    Audio_Volume,
    GameVolume,
    PlayerOnly,
    FluidSim,
    NavMarkup,
    Station_Static,
};

