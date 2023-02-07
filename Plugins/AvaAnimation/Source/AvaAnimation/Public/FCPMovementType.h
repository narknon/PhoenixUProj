#pragma once
#include "CoreMinimal.h"
#include "FCPMovementType.generated.h"

UENUM()
enum class FCPMovementType : int32 {
    Ignore,
    None,
    Upward,
    Downward,
};

