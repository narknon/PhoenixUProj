#pragma once
#include "CoreMinimal.h"
#include "ECreatureMoveToSpeedSetting.generated.h"

UENUM(BlueprintType)
enum class ECreatureMoveToSpeedSetting : uint8 {
    SetSpeed,
    KeepPreviousSpeed,
    DistanceAdaptiveSpeed,
};

