#pragma once
#include "CoreMinimal.h"
#include "EWindParametersTimeBase.generated.h"

UENUM(BlueprintType)
enum class EWindParametersTimeBase : uint8 {
    GameSeconds,
    GameMinutes,
    GameHours,
    RealSeconds,
    RealMinutes,
    RealHours,
};

