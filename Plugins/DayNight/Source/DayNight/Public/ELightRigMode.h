#pragma once
#include "CoreMinimal.h"
#include "ELightRigMode.generated.h"

UENUM(BlueprintType)
enum class ELightRigMode : uint8 {
    GameAndProbeCapture,
    GameOnly,
    ProbeCaptureOnly,
};

