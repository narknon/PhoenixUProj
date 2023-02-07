#pragma once
#include "CoreMinimal.h"
#include "EScoreOverrideReturnConfigurationType.generated.h"

UENUM()
enum class EScoreOverrideReturnConfigurationType : int32 {
    Value_A,
    Value_B,
    Value_Custom,
    Value_MAX UMETA(Hidden),
};

