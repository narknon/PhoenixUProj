#pragma once
#include "CoreMinimal.h"
#include "EInstancedTrailMemberRotationConstraint.generated.h"

UENUM(BlueprintType)
enum class EInstancedTrailMemberRotationConstraint : uint8 {
    ITMRC_NONE,
    ITMRC_WHOLE,
    ITMRC_HALF,
    ITMRC_MAX UMETA(Hidden),
};

