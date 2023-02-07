#pragma once
#include "CoreMinimal.h"
#include "EFXAutoTriggerConditionResult.generated.h"

UENUM(BlueprintType)
enum class EFXAutoTriggerConditionResult : uint8 {
    None,
    End,
    Start,
};

