#pragma once
#include "CoreMinimal.h"
#include "ENPC_StairsSlopeContext.generated.h"

UENUM(BlueprintType)
enum class ENPC_StairsSlopeContext : uint8 {
    None,
    GoingUp,
    GoingDown,
    ENPC_MAX UMETA(Hidden),
};

