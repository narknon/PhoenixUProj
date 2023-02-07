#pragma once
#include "CoreMinimal.h"
#include "AkActionOnEventType.generated.h"

UENUM(BlueprintType)
enum class AkActionOnEventType : uint8 {
    Stop,
    Pause,
    Resume,
    Break,
    ReleaseEnvelope,
};

