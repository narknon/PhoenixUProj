#pragma once
#include "CoreMinimal.h"
#include "ENPC_PerceptionUpdate.generated.h"

UENUM(BlueprintType)
enum class ENPC_PerceptionUpdate : uint8 {
    Target,
    Weapon_DEPRECATED,
    CrimeScene_DEPRECATED,
    GameEvent,
    Default,
    ENPC_MAX UMETA(Hidden),
};

