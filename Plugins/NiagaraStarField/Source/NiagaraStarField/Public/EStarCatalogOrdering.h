#pragma once
#include "CoreMinimal.h"
#include "EStarCatalogOrdering.generated.h"

UENUM(BlueprintType)
enum class EStarCatalogOrdering : uint8 {
    XYZ,
    XZY,
    YXZ,
    YZX,
    ZXY,
    ZYX,
};

