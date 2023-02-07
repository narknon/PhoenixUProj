#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetDirection.generated.h"

UENUM(BlueprintType)
enum class ENPC_TargetDirection : uint8 {
    Forward,
    Back,
    Left,
    Right,
    ENPC_MAX UMETA(Hidden),
};

