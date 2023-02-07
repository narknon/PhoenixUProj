#pragma once
#include "CoreMinimal.h"
#include "EFXAutoTriggerConditionType.generated.h"

UENUM(BlueprintType)
enum class EFXAutoTriggerConditionType : uint8 {
    StartAndEnd,
    StartOnly,
    EndOnly,
};

