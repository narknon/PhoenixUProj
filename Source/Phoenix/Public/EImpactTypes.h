#pragma once
#include "CoreMinimal.h"
#include "EImpactTypes.generated.h"

UENUM(BlueprintType)
enum class EImpactTypes : uint8 {
    None,
    BroomFlight,
    Default,
    ExitWater,
    Explosion,
    Fire,
    Flesh,
    FloatingInWater,
    Footfall,
    Ice,
    Lift,
    Metal,
    Slide,
    SpellDefault,
    SpellDamage,
    SpellDamageLarge,
    Stone,
    Water,
    Wood,
};

