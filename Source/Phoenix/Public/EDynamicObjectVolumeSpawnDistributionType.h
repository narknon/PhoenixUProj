#pragma once
#include "CoreMinimal.h"
#include "EDynamicObjectVolumeSpawnDistributionType.generated.h"

UENUM(BlueprintType)
enum class EDynamicObjectVolumeSpawnDistributionType : uint8 {
    Uniform,
    UniformWithShuffle,
    VolumeDistribution,
    VolumeDistributionWithShuffle,
};

