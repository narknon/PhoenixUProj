#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigProbeMode.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigProbeMode : uint8 {
    GameAndProbeCapture,
    GameOnly,
    ProbeCaptureOnly,
};

