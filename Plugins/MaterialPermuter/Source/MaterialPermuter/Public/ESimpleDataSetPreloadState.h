#pragma once
#include "CoreMinimal.h"
#include "ESimpleDataSetPreloadState.generated.h"

UENUM(BlueprintType)
enum class ESimpleDataSetPreloadState : uint8 {
    Idle,
    BuildingPreloadList,
    Preloading,
    Done,
    Cancelling,
};

