#pragma once
#include "CoreMinimal.h"
#include "EHintConditionResult.generated.h"

UENUM(BlueprintType)
enum class EHintConditionResult : uint8 {
    ConditionFalse,
    ConditionTrue,
    ConditionReset,
};

