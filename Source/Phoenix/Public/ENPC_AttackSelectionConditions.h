#pragma once
#include "CoreMinimal.h"
#include "ENPC_AttackSelectionConditions.generated.h"

UENUM(BlueprintType)
enum class ENPC_AttackSelectionConditions : uint8 {
    LongDistBump,
    ShortDistBump,
    ShieldBreaker,
    CrowdControlEffect,
    DamagePotential,
    CurseApplier,
    JuggleStarter,
    JuggleContinuer,
    JuggleEnder,
    LargeCharacterInterrupter,
    AOE,
    Fire,
    StupefyAdvancer,
    StupefyEnder,
    PlantPriorityBump,
    Count,
    ENPC_MAX UMETA(Hidden),
};

