#pragma once
#include "CoreMinimal.h"
#include "EWindGustSimplexNoiseMode.generated.h"

UENUM(BlueprintType)
enum class EWindGustSimplexNoiseMode : uint8 {
    Constant,
    Simple,
    XYPlane,
    Full3D,
};

