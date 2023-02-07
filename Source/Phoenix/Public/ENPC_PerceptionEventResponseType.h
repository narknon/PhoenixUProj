#pragma once
#include "CoreMinimal.h"
#include "ENPC_PerceptionEventResponseType.generated.h"

UENUM(BlueprintType)
enum class ENPC_PerceptionEventResponseType : uint8 {
    Normal,
    Distraction,
    ENPC_MAX UMETA(Hidden),
};

