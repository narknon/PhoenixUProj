#pragma once
#include "CoreMinimal.h"
#include "ENPC_WaterResponse.generated.h"

UENUM(BlueprintType)
enum class ENPC_WaterResponse : uint8 {
    Die,
    TeleportToShore,
    SwimToShore,
    SwimAndAttack,
    ENPC_MAX UMETA(Hidden),
};

