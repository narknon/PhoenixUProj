#pragma once
#include "CoreMinimal.h"
#include "ENPC_Split.generated.h"

UENUM(BlueprintType)
enum class ENPC_Split : uint8 {
    None,
    Attack,
    PostAttack,
    CounterAttack,
    ENPC_MAX UMETA(Hidden),
};

