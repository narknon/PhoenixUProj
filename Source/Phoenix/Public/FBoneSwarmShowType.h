#pragma once
#include "CoreMinimal.h"
#include "FBoneSwarmShowType.generated.h"

UENUM(BlueprintType)
enum class FBoneSwarmShowType : uint8 {
    Manual,
    EvenDistribution,
    Random,
    AllAtOnce,
};

