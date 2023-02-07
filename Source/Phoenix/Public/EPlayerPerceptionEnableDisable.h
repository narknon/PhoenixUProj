#pragma once
#include "CoreMinimal.h"
#include "EPlayerPerceptionEnableDisable.generated.h"

UENUM(BlueprintType)
enum class EPlayerPerceptionEnableDisable : uint8 {
    Ignore,
    Enable,
    Disable,
};

