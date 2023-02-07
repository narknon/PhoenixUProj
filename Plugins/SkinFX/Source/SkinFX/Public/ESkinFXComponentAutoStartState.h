#pragma once
#include "CoreMinimal.h"
#include "ESkinFXComponentAutoStartState.generated.h"

UENUM(BlueprintType)
enum class ESkinFXComponentAutoStartState : uint8 {
    WaitingToStart,
    Running,
    Done,
};

