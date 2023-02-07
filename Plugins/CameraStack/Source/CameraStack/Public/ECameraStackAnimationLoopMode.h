#pragma once
#include "CoreMinimal.h"
#include "ECameraStackAnimationLoopMode.generated.h"

UENUM(BlueprintType)
enum class ECameraStackAnimationLoopMode : uint8 {
    Loop,
    Remove,
    Pause,
};

