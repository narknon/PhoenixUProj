#pragma once
#include "CoreMinimal.h"
#include "EInfirmaryPriority.generated.h"

UENUM(BlueprintType)
enum class EInfirmaryPriority : uint8 {
    Systemic,
    WorldEvent,
    Mission,
    Count,
};

