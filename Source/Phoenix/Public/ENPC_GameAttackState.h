#pragma once
#include "CoreMinimal.h"
#include "ENPC_GameAttackState.generated.h"

UENUM(BlueprintType)
enum class ENPC_GameAttackState : uint8 {
    None,
    RunThrough,
    ENPC_MAX UMETA(Hidden),
};

