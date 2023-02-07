#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingBundleAndSwapState.generated.h"

UENUM(BlueprintType)
enum class EMaterialPermuterLoadingBundleAndSwapState : uint8 {
    Uninitialized,
    Loading,
    LoadedPendingSwaps,
    Swapped,
    SwapFailed,
};

