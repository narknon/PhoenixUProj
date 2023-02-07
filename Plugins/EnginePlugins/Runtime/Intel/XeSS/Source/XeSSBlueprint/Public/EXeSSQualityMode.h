#pragma once
#include "CoreMinimal.h"
#include "EXeSSQualityMode.generated.h"

UENUM(BlueprintType)
enum class EXeSSQualityMode : uint8 {
    Off,
    Performance,
    Balanced,
    Quality,
    UltraQuality,
};

