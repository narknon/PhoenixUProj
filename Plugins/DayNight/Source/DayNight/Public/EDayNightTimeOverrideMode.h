#pragma once
#include "CoreMinimal.h"
#include "EDayNightTimeOverrideMode.generated.h"

UENUM(BlueprintType)
enum class EDayNightTimeOverrideMode : uint8 {
    DateTime,
    TimeOnly,
};

