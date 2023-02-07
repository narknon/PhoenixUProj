#pragma once
#include "CoreMinimal.h"
#include "EIconButtonState.generated.h"

UENUM(BlueprintType)
enum class EIconButtonState : uint8 {
    BS_Enabled,
    BS_Disabled,
    BS_Missing,
    BS_NonExistant,
    BS_MAX UMETA(Hidden),
};

