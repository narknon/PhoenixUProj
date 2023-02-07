#pragma once
#include "CoreMinimal.h"
#include "ETimeRigElement_FlagType.generated.h"

UENUM(BlueprintType)
enum class ETimeRigElement_FlagType : uint8 {
    None,
    Red,
    Orange,
    Yellow,
    Green,
    Cyan,
    Blue,
    Magenta,
    White,
    Grey,
    Black,
    ETimeRigElement_MAX UMETA(Hidden),
};

