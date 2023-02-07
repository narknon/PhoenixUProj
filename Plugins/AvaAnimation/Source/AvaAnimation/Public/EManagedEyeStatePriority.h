#pragma once
#include "CoreMinimal.h"
#include "EManagedEyeStatePriority.generated.h"

UENUM(BlueprintType)
enum class EManagedEyeStatePriority : uint8 {
    EMOTION,
    CHARACTEROPTIONS,
    SCENERIG,
    SCENERIG_ACTIVE,
    DIALOG,
};

