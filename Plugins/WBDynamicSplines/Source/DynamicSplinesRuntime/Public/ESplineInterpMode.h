#pragma once
#include "CoreMinimal.h"
#include "ESplineInterpMode.generated.h"

UENUM()
enum class ESplineInterpMode : int32 {
    Auto,
    AutoClamped,
    User,
    Linear,
    Constant,
    Unknown,
};

