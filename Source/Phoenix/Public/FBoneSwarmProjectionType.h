#pragma once
#include "CoreMinimal.h"
#include "FBoneSwarmProjectionType.generated.h"

UENUM(BlueprintType)
enum class FBoneSwarmProjectionType : uint8 {
    UseCone,
    SphereDistribution,
    TotalRandom,
};

