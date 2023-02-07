#pragma once
#include "CoreMinimal.h"
#include "ECreatureCombatDebugBehaviorType.generated.h"

UENUM(BlueprintType)
enum class ECreatureCombatDebugBehaviorType : uint8 {
    None,
    Exclude,
    Forced,
};

