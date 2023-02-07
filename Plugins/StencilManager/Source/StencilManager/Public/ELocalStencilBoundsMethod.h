#pragma once
#include "CoreMinimal.h"
#include "ELocalStencilBoundsMethod.generated.h"

UENUM(BlueprintType)
enum class ELocalStencilBoundsMethod : uint8 {
    Default,
    Local,
    World,
};

