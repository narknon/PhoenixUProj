#pragma once
#include "CoreMinimal.h"
#include "ECreatureLookAtBehaviorMode.generated.h"

UENUM(BlueprintType)
enum class ECreatureLookAtBehaviorMode : uint8 {
    Disabled,
    Perception,
    LookAround,
    ForcedTarget,
};

