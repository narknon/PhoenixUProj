#pragma once
#include "CoreMinimal.h"
#include "EPostProcessingVarBool.generated.h"

UENUM(BlueprintType)
enum class EPostProcessingVarBool : uint8 {
    None,
    AutoExposureApplyPhysicalCameraExposure,
    AmbientOcclusionRadiusInWS,
};

