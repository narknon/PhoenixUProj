#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetPerceptionType.generated.h"

UENUM(BlueprintType)
enum class ENPC_TargetPerceptionType : uint8 {
    None,
    Attack,
    CrimeScene,
    Notify,
    ENPC_MAX UMETA(Hidden),
};

