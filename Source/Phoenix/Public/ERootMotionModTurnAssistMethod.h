#pragma once
#include "CoreMinimal.h"
#include "ERootMotionModTurnAssistMethod.generated.h"

UENUM(BlueprintType)
namespace ERootMotionModTurnAssistMethod {
    enum Type {
        UseCurve,
        UseCustomInterp,
        UseDampedSpring,
    };
}

