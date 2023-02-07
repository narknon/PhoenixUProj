#pragma once
#include "CoreMinimal.h"
#include "ENPC_SetStateNext.generated.h"

UENUM(BlueprintType)
enum class ENPC_SetStateNext : uint8 {
    None,
    TargetLost,
    PostSpawn,
    TargetSuccess,
    ReactionDone,
    LosingTarget,
    ConfundoDone,
    ENPC_MAX UMETA(Hidden),
};

