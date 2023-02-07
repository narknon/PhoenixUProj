#pragma once
#include "CoreMinimal.h"
#include "ECameraStackSplineType.generated.h"

UENUM(BlueprintType)
enum class ECameraStackSplineType : uint8 {
    LookAheadSpline,
    RailCameraSpline,
    RailTargetSpline,
    None,
};

