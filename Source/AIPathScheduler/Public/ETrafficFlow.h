#pragma once
#include "CoreMinimal.h"
#include "ETrafficFlow.generated.h"

UENUM(BlueprintType)
enum class ETrafficFlow : uint8 {
    Forward,
    Backwards,
    Bidirectional,
    Blocked,
    Random,
};

