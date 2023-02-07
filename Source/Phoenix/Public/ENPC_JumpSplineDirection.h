#pragma once
#include "CoreMinimal.h"
#include "ENPC_JumpSplineDirection.generated.h"

UENUM(BlueprintType)
enum class ENPC_JumpSplineDirection : uint8 {
    Forward,
    Reverse,
    ENPC_MAX UMETA(Hidden),
};

