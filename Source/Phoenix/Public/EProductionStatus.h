#pragma once
#include "CoreMinimal.h"
#include "EProductionStatus.generated.h"

UENUM(BlueprintType)
enum class EProductionStatus : uint8 {
    IN_DEVELOPMENT,
    FUNCTIONAL,
    SHIPPABLE,
    CUT,
};

