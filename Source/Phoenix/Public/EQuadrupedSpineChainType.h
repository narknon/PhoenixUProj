#pragma once
#include "CoreMinimal.h"
#include "EQuadrupedSpineChainType.generated.h"

UENUM(BlueprintType)
enum class EQuadrupedSpineChainType : uint8 {
    Neck,
    Spine,
    Tail,
    Invalid,
};

