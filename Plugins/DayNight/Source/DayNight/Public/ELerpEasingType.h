#pragma once
#include "CoreMinimal.h"
#include "ELerpEasingType.generated.h"

UENUM(BlueprintType)
enum class ELerpEasingType : uint8 {
    EaseIn,
    EaseOut,
    EaseInOut,
};

