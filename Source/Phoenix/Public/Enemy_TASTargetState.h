#pragma once
#include "CoreMinimal.h"
#include "Enemy_TASTargetState.generated.h"

UENUM(BlueprintType)
enum class Enemy_TASTargetState : uint8 {
    TrackingTarget,
    TrackingPlayer,
    LosingPlayer,
    NotTracking,
    Enemy_MAX UMETA(Hidden),
};

