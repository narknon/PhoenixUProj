#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingKillEventDeathLeapCollisionType.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingKillEventDeathLeapCollisionType : uint8 {
    None,
    Simple,
    Complex,
};

