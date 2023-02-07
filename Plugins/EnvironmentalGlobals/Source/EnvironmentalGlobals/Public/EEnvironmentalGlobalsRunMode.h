#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsRunMode.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsRunMode : uint8 {
    GameAndProbeCapture,
    GameOnly,
    ProbeCaptureOnly,
};

