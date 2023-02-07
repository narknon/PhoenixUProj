#pragma once
#include "CoreMinimal.h"
#include "EVisibilityTimeWindowState.generated.h"

UENUM(BlueprintType)
enum class EVisibilityTimeWindowState : uint8 {
    WithinTimeWindow,
    OutSideTimeWindow,
    WithinTimeWindowSpawn,
};

