#pragma once
#include "CoreMinimal.h"
#include "EObjectStateBranchCondition.generated.h"

UENUM(BlueprintType)
enum class EObjectStateBranchCondition : uint8 {
    IsDead,
    IsDazed,
    IsWoundedKneeling,
};

