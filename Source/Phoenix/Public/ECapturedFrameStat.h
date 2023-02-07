#pragma once
#include "CoreMinimal.h"
#include "ECapturedFrameStat.generated.h"

UENUM(BlueprintType)
enum class ECapturedFrameStat : uint8 {
    Frame,
    Game,
    Render,
    Gpu,
    Cpu,
    Count,
};

