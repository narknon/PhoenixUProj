#pragma once
#include "CoreMinimal.h"
#include "EStencilTagRule.generated.h"

UENUM(BlueprintType)
enum class EStencilTagRule : uint8 {
    DoNotStencil,
    StencilOnly,
    ConditionalStencil,
    ShowOnStencil,
    HideOnStencil,
};

