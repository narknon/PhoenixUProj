#pragma once
#include "CoreMinimal.h"
#include "EBasicMobilityFootState.generated.h"

UENUM(BlueprintType)
enum class EBasicMobilityFootState : uint8 {
    Undetermined,
    Left,
    Right,
};

