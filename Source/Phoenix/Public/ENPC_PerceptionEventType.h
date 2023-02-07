#pragma once
#include "CoreMinimal.h"
#include "ENPC_PerceptionEventType.generated.h"

UENUM(BlueprintType)
enum class ENPC_PerceptionEventType : uint8 {
    None,
    Damage,
    Death,
    Sound,
    Engaged,
    Dead,
    StealthDeath,
    Collided,
    MunitionHit,
    MunitionFire,
    Footfall,
    CombatPlant,
    ENPC_MAX UMETA(Hidden),
};

