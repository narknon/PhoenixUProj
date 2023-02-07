#pragma once
#include "CoreMinimal.h"
#include "EWorldFXDistanceType.generated.h"

UENUM(BlueprintType)
enum class EWorldFXDistanceType : uint8 {
    UseDefault,
    DistanceMeters,
    NoCulling,
};

