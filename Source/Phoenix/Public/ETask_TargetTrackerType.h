#pragma once
#include "CoreMinimal.h"
#include "ETask_TargetTrackerType.generated.h"

UENUM(BlueprintType)
enum class ETask_TargetTrackerType : uint8 {
    None,
    Face,
    LookAt,
    AimAt,
    ETask_MAX UMETA(Hidden),
};

