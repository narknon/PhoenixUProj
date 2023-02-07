#pragma once
#include "CoreMinimal.h"
#include "EMiniMapIconSize.generated.h"

UENUM(BlueprintType)
enum EMiniMapIconSize {
    MINIMAP_ICONSIZE_SMALL,
    MINIMAP_ICONSIZE_NORMAL,
    MINIMAP_ICONSIZE_LARGE,
    MINIMAP_ICONSIZE_MAX UMETA(Hidden),
};

