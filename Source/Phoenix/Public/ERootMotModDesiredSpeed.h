#pragma once
#include "CoreMinimal.h"
#include "ERootMotModDesiredSpeed.generated.h"

UENUM(BlueprintType)
namespace ERootMotModDesiredSpeed {
    enum Type {
        UseProvided,
        GetFromAnimInstance,
    };
}

