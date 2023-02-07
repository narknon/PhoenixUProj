#pragma once
#include "CoreMinimal.h"
#include "EStreamingBehaviorType.generated.h"

UENUM(BlueprintType)
enum class EStreamingBehaviorType : uint8 {
    Persistent,
    Attached,
    VolumeBased,
    VolumeBasedLOD,
    WorldComposition,
    WorldCompositionLOD,
};

