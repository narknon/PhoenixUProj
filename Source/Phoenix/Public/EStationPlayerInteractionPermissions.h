#pragma once
#include "CoreMinimal.h"
#include "EStationPlayerInteractionPermissions.generated.h"

UENUM(BlueprintType)
enum EStationPlayerInteractionPermissions {
    PIP_NEVER,
    PIP_WHEN_OCCUPIED,
    PIP_CONDITIONAL,
    PIP_ALWAYS,
    PIP_MAX UMETA(Hidden),
};

