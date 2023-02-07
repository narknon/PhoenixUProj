#pragma once
#include "CoreMinimal.h"
#include "EOdcNavmeshProbeType.generated.h"

UENUM(BlueprintType)
enum class EOdcNavmeshProbeType : uint8 {
    Full3D,
    Projection,
    Horizontal,
};

