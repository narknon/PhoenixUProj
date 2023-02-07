#pragma once
#include "CoreMinimal.h"
#include "EAimAtAxisType.generated.h"

UENUM()
enum class EAimAtAxisType : int8 {
    Up,
    Down,
    Forward,
    Backward,
    Right,
    Left,
};

