#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapPriority.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapPriority : uint8 {
    AlwaysInterrupt,
    VeryLow,
    Low,
    Normal,
    Important,
    VeryImportant,
    NeverInterrupt,
    Fundamental,
};

