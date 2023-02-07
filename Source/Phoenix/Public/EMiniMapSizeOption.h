#pragma once
#include "CoreMinimal.h"
#include "EMiniMapSizeOption.generated.h"

UENUM(BlueprintType)
enum EMiniMapSizeOption {
    MINIMAP_SIZE_OFF,
    MINIMAP_SIZE_SMALL,
    MINIMAP_SIZE_NORMAL,
    MINIMAP_SIZE_LARGE,
    MINIMAP_SIZE_MAX UMETA(Hidden),
};

