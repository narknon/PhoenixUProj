#pragma once
#include "CoreMinimal.h"
#include "EMoveMinSpeedRule.generated.h"

UENUM(BlueprintType)
namespace EMoveMinSpeedRule {
    enum Type {
        ZeroSpeed,
        StartingSpeed,
        FixedSpeed,
    };
}

