#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentObstacle.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentObstacle : uint8 {
    Throwable,
    RedBarrel,
    SendTarget,
    ENUM_MAX UMETA(Hidden),
};

