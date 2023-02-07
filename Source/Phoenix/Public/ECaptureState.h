#pragma once
#include "CoreMinimal.h"
#include "ECaptureState.generated.h"

UENUM(BlueprintType)
enum class ECaptureState : uint8 {
    None,
    PreStart,
    Progressing,
    Succeeding,
    Succeeded,
    Cancelling,
    Cancelled,
    Interrupted,
    Failing,
};

