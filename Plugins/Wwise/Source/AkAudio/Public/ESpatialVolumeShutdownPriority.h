#pragma once
#include "CoreMinimal.h"
#include "ESpatialVolumeShutdownPriority.generated.h"

UENUM(BlueprintType)
enum class ESpatialVolumeShutdownPriority : uint8 {
    Standard,
    InStation,
    AnimNotify,
    AnimNotifyUpate,
};

