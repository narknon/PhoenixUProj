#pragma once
#include "CoreMinimal.h"
#include "EPSOCachePreviewMode.generated.h"

UENUM(BlueprintType)
enum class EPSOCachePreviewMode : uint8 {
    FrameCount,
    Time,
};

