#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingBundleAndSwapType.generated.h"

UENUM(BlueprintType)
enum class EMaterialPermuterLoadingBundleAndSwapType : uint8 {
    SwapComponent,
    SwapComponentAutoRefresh,
    Raw,
    Hard,
    HardBatched,
};

