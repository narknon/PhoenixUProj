#pragma once
#include "CoreMinimal.h"
#include "EMultiFXRepeat.generated.h"

UENUM(BlueprintType)
enum class EMultiFXRepeat : uint8 {
    Restart,
    Ignore,
    RestartInstigator,
    IgnoreInstigator,
};

