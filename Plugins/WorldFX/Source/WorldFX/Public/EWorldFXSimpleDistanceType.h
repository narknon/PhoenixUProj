#pragma once
#include "CoreMinimal.h"
#include "EWorldFXSimpleDistanceType.generated.h"

UENUM(BlueprintType)
enum class EWorldFXSimpleDistanceType : uint8 {
    DistanceMeters,
    NoCulling,
};

