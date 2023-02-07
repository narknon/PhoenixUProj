#pragma once
#include "CoreMinimal.h"
#include "ENPC_Event.generated.h"

UENUM(BlueprintType)
enum class ENPC_Event : uint8 {
    None,
    TransientWeaponActivate,
    TransientWeaponDeactivate,
    TombProtectorMeteor_Choose,
    TombProtectorMeteor_Break,
    TombProtectorMeteor_Throw,
    ENPC_MAX UMETA(Hidden),
};

