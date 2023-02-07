#pragma once
#include "CoreMinimal.h"
#include "EReactionPlayMultiFxTaskType.generated.h"

UENUM(BlueprintType)
enum class EReactionPlayMultiFxTaskType : uint8 {
    UseImpactLocationAndDirectionInverse,
    UseImpactDirectionInverseOnly,
};

