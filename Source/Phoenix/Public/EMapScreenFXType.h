#pragma once
#include "CoreMinimal.h"
#include "EMapScreenFXType.generated.h"

UENUM(BlueprintType)
enum EMapScreenFXType {
    MAP_FX_TYPE_NONE,
    MAP_FX_TYPE_ALL,
    MAP_FX_TYPE_ACTIVE,
    MAP_FX_TYPE_INACTIVE,
    MAP_FX_TYPE_MAX UMETA(Hidden),
};

