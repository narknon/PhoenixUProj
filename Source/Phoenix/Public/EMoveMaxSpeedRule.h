#pragma once
#include "CoreMinimal.h"
#include "EMoveMaxSpeedRule.generated.h"

UENUM(BlueprintType)
namespace EMoveMaxSpeedRule {
    enum Type {
        StartingSpeed,
        DesiredSpeed,
        FixedSpeed,
    };
}

