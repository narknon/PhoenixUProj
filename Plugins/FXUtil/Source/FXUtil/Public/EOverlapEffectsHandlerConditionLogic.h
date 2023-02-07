#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsHandlerConditionLogic.generated.h"

UENUM(BlueprintType)
enum class EOverlapEffectsHandlerConditionLogic : uint8 {
    And,
    Or,
    ExclusiveOr,
};

