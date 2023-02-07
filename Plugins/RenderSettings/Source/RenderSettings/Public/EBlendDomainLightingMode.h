#pragma once
#include "CoreMinimal.h"
#include "EBlendDomainLightingMode.generated.h"

UENUM(BlueprintType)
enum class EBlendDomainLightingMode : uint8 {
    GameAndProbeCapture,
    GameOnly,
    ProbeCaptureOnly,
};

