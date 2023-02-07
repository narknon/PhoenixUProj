#pragma once
#include "CoreMinimal.h"
#include "EBaseCharFocusInterestPriority.generated.h"

UENUM(BlueprintType)
enum class EBaseCharFocusInterestPriority : uint8 {
    StationBehavior,
    CombatBehavior,
    ScriptedBehavior,
};

