#pragma once
#include "CoreMinimal.h"
#include "ESeasonOverride.generated.h"

UENUM(BlueprintType)
enum class ESeasonOverride : uint8 {
    SO_NONE,
    SO_SPRING,
    SO_FALL,
    SO_WINTER,
    SO_SUMMER,
    SO_MAX UMETA(Hidden),
};

