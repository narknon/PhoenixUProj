#pragma once
#include "CoreMinimal.h"
#include "EImpactReactionStrength.generated.h"

UENUM(BlueprintType)
enum class EImpactReactionStrength : uint8 {
    None,
    Hitch,
    Knockdown,
    Levioso,
    DeathBlows,
    Slam,
};

