#pragma once
#include "CoreMinimal.h"
#include "EMountFlyingGait.generated.h"

UENUM(BlueprintType)
enum class EMountFlyingGait : uint8 {
    Stop,
    Hover,
    Slow,
    Fast,
    Num,
};

