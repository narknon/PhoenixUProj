#pragma once
#include "CoreMinimal.h"
#include "HitTrackerTypes.generated.h"

UENUM(BlueprintType)
enum class HitTrackerTypes : uint8 {
    Irrelevant,
    NonConsecutiveDifferent,
    NonConsecutiveSame,
    ConsecutiveSame,
    ConsecutiveDifferent,
};

