#pragma once
#include "CoreMinimal.h"
#include "ETask_TargetType.generated.h"

UENUM(BlueprintType)
enum class ETask_TargetType : uint8 {
    None,
    Location,
    Actor,
    DesiredDirection,
    CognitionTarget,
    FwdLoop,
    ETask_MAX UMETA(Hidden),
};

