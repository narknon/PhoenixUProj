#pragma once
#include "CoreMinimal.h"
#include "ENPC_MoveDataState.generated.h"

UENUM(BlueprintType)
enum class ENPC_MoveDataState : uint8 {
    Normal,
    Attack,
    ENPC_MAX UMETA(Hidden),
};

