#pragma once
#include "CoreMinimal.h"
#include "EPSOCachingLevelMode.generated.h"

UENUM(BlueprintType)
enum class EPSOCachingLevelMode : uint8 {
    Regular,
    DebugFast,
    PredefinedAssets,
};

