#pragma once
#include "CoreMinimal.h"
#include "EMoveDirectionRule.generated.h"

UENUM(BlueprintType)
namespace EMoveDirectionRule {
    enum Type {
        ForwardVector,
        DesiredDirection,
        FacingTracker,
        ForwardVector_NEGATED,
        DesiredDirection_NEGATED,
        FacingTracker_NEGATED,
    };
}

