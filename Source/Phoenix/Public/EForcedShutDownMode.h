#pragma once
#include "CoreMinimal.h"
#include "EForcedShutDownMode.generated.h"

UENUM(BlueprintType)
enum class EForcedShutDownMode : uint8 {
    None,
    NoForcedShutDownAllowed,
    ForcedHiddenRenderShutdDown,
    ForcedRenderShutDown,
    ForcedHiddenFleshCacheShutDown,
    ForcedFleshCacheShutDown,
    ForcedAllowRenderShutDown,
};

