#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingBundleState.generated.h"

UENUM(BlueprintType)
enum class EMaterialPermuterLoadingBundleState : uint8 {
    Init,
    WaitingOnLoad,
    SignalLoaded,
    Loaded,
};

