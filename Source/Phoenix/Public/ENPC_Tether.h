#pragma once
#include "CoreMinimal.h"
#include "ENPC_Tether.generated.h"

UENUM(BlueprintType)
enum class ENPC_Tether : uint8 {
    None,
    Spawn,
    Player,
    Location,
    WanderStartLocation,
    Actor,
    ENPC_MAX UMETA(Hidden),
};

