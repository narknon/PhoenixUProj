#pragma once
#include "CoreMinimal.h"
#include "EBasicLightType.generated.h"

UENUM(BlueprintType)
enum class EBasicLightType : uint8 {
    Point,
    Spot,
    Rect,
};

