#pragma once
#include "CoreMinimal.h"
#include "ENPC_CrouchContext.generated.h"

UENUM(BlueprintType)
enum class ENPC_CrouchContext : uint8 {
    InCrouchVolume,
    OnCrouchNavArea,
    CompanionCrouch,
    ENPC_MAX UMETA(Hidden),
};

