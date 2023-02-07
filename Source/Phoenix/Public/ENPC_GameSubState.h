#pragma once
#include "CoreMinimal.h"
#include "ENPC_GameSubState.generated.h"

UENUM(BlueprintType)
enum class ENPC_GameSubState : uint8 {
    None,
    Outside,
    SwimToShore,
    TooClose,
    BackOnNav,
    RecoverWeapon,
    Investigate,
    ENPC_MAX UMETA(Hidden),
};

