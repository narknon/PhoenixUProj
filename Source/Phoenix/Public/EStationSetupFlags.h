#pragma once
#include "CoreMinimal.h"
#include "EStationSetupFlags.generated.h"

UENUM(BlueprintType)
enum class EStationSetupFlags : uint8 {
    DisallowParentProps,
    Breakable,
    NeedsServiceProvider,
};

