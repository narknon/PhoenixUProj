#pragma once
#include "CoreMinimal.h"
#include "ENPC_FireContext.generated.h"

UENUM(BlueprintType)
enum class ENPC_FireContext : uint8 {
    None,
    Charred,
    OnFire,
    ENPC_MAX UMETA(Hidden),
};

