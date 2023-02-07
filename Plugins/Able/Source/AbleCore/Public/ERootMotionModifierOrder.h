#pragma once
#include "CoreMinimal.h"
#include "ERootMotionModifierOrder.generated.h"

UENUM(BlueprintType)
enum class ERootMotionModifierOrder : uint8 {
    Primary,
    Secondary,
    RankAndFile,
    Penultimate,
    Ultimate,
};

