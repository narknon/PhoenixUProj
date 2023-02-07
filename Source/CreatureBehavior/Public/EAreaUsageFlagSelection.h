#pragma once
#include "CoreMinimal.h"
#include "EAreaUsageFlagSelection.generated.h"

UENUM(BlueprintType)
enum class EAreaUsageFlagSelection : uint8 {
    AreaUsageFlagSelection_Preferred,
    AreaUsageFlagSelection_Flee,
    AreaUsageFlagSelection_Custom,
    AreaUsageFlagSelection_MAX UMETA(Hidden),
};

