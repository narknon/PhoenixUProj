#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssistState.generated.h"

UENUM(BlueprintType)
enum class ENPC_TurnAssistState : uint8 {
    None,
    Target,
    PathLoc,
    Loc,
    Weapon,
    ENPC_MAX UMETA(Hidden),
};

