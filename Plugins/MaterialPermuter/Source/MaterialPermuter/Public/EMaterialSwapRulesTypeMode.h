#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRulesTypeMode.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapRulesTypeMode : uint8 {
    Default,
    OnlySwap,
    NeverSwap,
};

