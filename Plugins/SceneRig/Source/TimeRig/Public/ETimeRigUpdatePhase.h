#pragma once
#include "CoreMinimal.h"
#include "ETimeRigUpdatePhase.generated.h"

UENUM(BlueprintType)
enum class ETimeRigUpdatePhase : uint8 {
    None,
    HandleUpdate = 0x2,
    HandleExternalEvents,
    LastPhase = 0x3,
};

