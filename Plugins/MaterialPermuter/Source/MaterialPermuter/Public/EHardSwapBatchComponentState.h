#pragma once
#include "CoreMinimal.h"
#include "EHardSwapBatchComponentState.generated.h"

UENUM(BlueprintType)
enum class EHardSwapBatchComponentState : uint8 {
    Startup,
    Building,
    Swapping,
    Done,
};

