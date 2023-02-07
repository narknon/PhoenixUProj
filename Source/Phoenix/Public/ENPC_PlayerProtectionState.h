#pragma once
#include "CoreMinimal.h"
#include "ENPC_PlayerProtectionState.generated.h"

UENUM(BlueprintType)
enum class ENPC_PlayerProtectionState : uint8 {
    NormalAttackProtection,
    FullAttackProtection,
    VulnerableNoProtection,
    FlyingProtection,
    SwimmingProtection,
    ENPC_MAX UMETA(Hidden),
};

