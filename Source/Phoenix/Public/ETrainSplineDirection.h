#pragma once
#include "CoreMinimal.h"
#include "ETrainSplineDirection.generated.h"

UENUM(BlueprintType)
enum class ETrainSplineDirection : uint8 {
    INCREMENTING_NORTH,
    INCREMENTING_SOUTH,
    INCREMENTING_MAX UMETA(Hidden),
};

