#pragma once
#include "CoreMinimal.h"
#include "EPlatforms.generated.h"

UENUM(BlueprintType)
enum class EPlatforms : uint8 {
    Platform_Switch = 0x1,
    Platform_LastGen = 0x0,
    Platform_NextGen = 0x4,
    Platform_PC = 0x8,
    Platform_MAX UMETA(Hidden),
};

