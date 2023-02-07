#pragma once
#include "CoreMinimal.h"
#include "EPerkState.generated.h"

UENUM(BlueprintType)
enum class EPerkState : uint8 {
    PERK_UNAVAILABLE,
    PERK_AVAILABLE,
    PERK_PURCHASED,
    PERK_UPGRADE_UNAVAILABLE,
    PERK_MAX UMETA(Hidden),
};

