#pragma once
#include "CoreMinimal.h"
#include "ECabbage_Mobility.generated.h"

UENUM(BlueprintType)
enum class ECabbage_Mobility : uint8 {
    Spawn,
    Attack,
    Bounce,
    Idle,
    Slide,
    ECabbage_MAX UMETA(Hidden),
};

