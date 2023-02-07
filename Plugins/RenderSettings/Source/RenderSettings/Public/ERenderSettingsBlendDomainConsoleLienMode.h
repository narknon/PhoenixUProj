#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsBlendDomainConsoleLienMode.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsBlendDomainConsoleLienMode : uint8 {
    IsZero,
    IsOne,
    GreaterThanOneHalf,
    LessThanOneHalf,
};

