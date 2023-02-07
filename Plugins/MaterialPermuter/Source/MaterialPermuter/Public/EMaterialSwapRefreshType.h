#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapRefreshType.generated.h"

UENUM(BlueprintType)
enum class EMaterialSwapRefreshType : uint8 {
    Unsupported,
    Key,
    MIDOnly,
};

