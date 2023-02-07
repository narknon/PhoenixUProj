#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingPriority.generated.h"

UENUM(BlueprintType)
enum class EMaterialPermuterLoadingPriority : uint8 {
    VeryLow,
    Low,
    Normal,
    AboveNormal,
    High,
    Critical,
};

