#pragma once
#include "CoreMinimal.h"
#include "EStencilValueRenderCustomDepthRule.generated.h"

UENUM(BlueprintType)
enum class EStencilValueRenderCustomDepthRule : uint8 {
    DoNotStencil,
    OnlyStencil,
};

