#pragma once
#include "CoreMinimal.h"
#include "EStencilRule.generated.h"

UENUM(BlueprintType)
enum class EStencilRule : uint8 {
    DoNotStencil,
    OnlyStencil,
};

