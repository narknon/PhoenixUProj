#pragma once
#include "CoreMinimal.h"
#include "ENPC_MoveTurnTo.generated.h"

UENUM(BlueprintType)
enum class ENPC_MoveTurnTo : uint8 {
    None,
    MoveDir,
    Target,
    Weapon,
    ENPC_MAX UMETA(Hidden),
};

