#pragma once
#include "CoreMinimal.h"
#include "EPostDeathState.generated.h"

UENUM(BlueprintType)
enum class EPostDeathState : uint8 {
    Enabled,
    Disabled,
};

