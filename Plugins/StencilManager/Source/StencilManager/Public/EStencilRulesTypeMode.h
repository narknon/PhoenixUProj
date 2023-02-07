#pragma once
#include "CoreMinimal.h"
#include "EStencilRulesTypeMode.generated.h"

UENUM(BlueprintType)
enum class EStencilRulesTypeMode : uint8 {
    Default,
    OnlySwap,
    NeverSwap,
};

