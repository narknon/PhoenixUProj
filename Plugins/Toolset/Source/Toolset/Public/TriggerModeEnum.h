#pragma once
#include "CoreMinimal.h"
#include "TriggerModeEnum.generated.h"

UENUM(BlueprintType)
enum class TriggerModeEnum : uint8 {
    Off,
    Weapon,
    Vibration,
    Feedback,
};

