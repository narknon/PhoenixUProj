#pragma once
#include "CoreMinimal.h"
#include "EGameEventLocation.generated.h"

UENUM(BlueprintType)
enum class EGameEventLocation : uint8 {
    None,
    Caster,
    Impact,
    Target,
    Destination,
};

