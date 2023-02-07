#pragma once
#include "CoreMinimal.h"
#include "EStencilFilterPrimitiveMatchMode.generated.h"

UENUM(BlueprintType)
enum class EStencilFilterPrimitiveMatchMode : uint8 {
    Exact,
    SubStringCaseSensitve,
    SubStringIgnoreCase,
};

