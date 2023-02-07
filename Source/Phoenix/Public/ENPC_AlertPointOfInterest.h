#pragma once
#include "CoreMinimal.h"
#include "ENPC_AlertPointOfInterest.generated.h"

UENUM(BlueprintType)
enum class ENPC_AlertPointOfInterest : uint8 {
    None,
    Target,
    TeammateTarget,
    TeammateDeath,
    TeammateDamage,
    Sound,
    TeammateDead,
    Distraction,
    CombatPlant,
    ENPC_MAX UMETA(Hidden),
};

