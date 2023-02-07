#pragma once
#include "CoreMinimal.h"
#include "EGameEvent_Intensity.generated.h"

UENUM(BlueprintType)
enum class EGameEvent_Intensity : uint8 {
    None,
    White,
    Yellow,
    Red,
    EGameEvent_MAX UMETA(Hidden),
};

