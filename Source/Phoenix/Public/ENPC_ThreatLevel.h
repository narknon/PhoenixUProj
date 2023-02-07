#pragma once
#include "CoreMinimal.h"
#include "ENPC_ThreatLevel.generated.h"

UENUM(BlueprintType)
enum class ENPC_ThreatLevel : uint8 {
    None,
    ThreatLow,
    ThreatMedium,
    ThreatHigh,
    ThreatMax,
    ENPC_MAX UMETA(Hidden),
};

