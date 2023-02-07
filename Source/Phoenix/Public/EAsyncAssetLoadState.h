#pragma once
#include "CoreMinimal.h"
#include "EAsyncAssetLoadState.generated.h"

UENUM(BlueprintType)
enum class EAsyncAssetLoadState : uint8 {
    ASSETLOAD_NOT_REQUESTED,
    ASSETLOAD_IN_PROGRESS,
    ASSETLOAD_COMPLETED,
    ASSETLOAD_MAX_STATES,
    ASSETLOAD_MAX UMETA(Hidden),
};

