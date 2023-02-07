#pragma once
#include "CoreMinimal.h"
#include "ELocalStencilMaterialMode.generated.h"

UENUM(BlueprintType)
enum class ELocalStencilMaterialMode : uint8 {
    Default,
    DefaultMID,
    Custom,
    CustomMID,
};

