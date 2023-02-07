#pragma once
#include "CoreMinimal.h"
#include "ECreatureFleeFlyingOption.generated.h"

UENUM(BlueprintType)
enum class ECreatureFleeFlyingOption : uint8 {
    DontFly,
    TakeoffImmediately,
    TakeoffFromSprint,
};

