#pragma once
#include "CoreMinimal.h"
#include "ELightProbeCaptureMode.generated.h"

UENUM(BlueprintType)
enum class ELightProbeCaptureMode : uint8 {
    Off,
    GlobalSlot,
    LocalTime,
};

