#pragma once
#include "CoreMinimal.h"
#include "EOverrideNPCStateOnFinish.generated.h"

UENUM(BlueprintType)
enum class EOverrideNPCStateOnFinish : uint8 {
    None,
    Idle,
    Move,
    Attack,
    Disengage,
    Dead,
    Destroy,
    Custom,
};

