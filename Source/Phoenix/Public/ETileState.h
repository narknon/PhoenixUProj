#pragma once
#include "CoreMinimal.h"
#include "ETileState.generated.h"

UENUM(BlueprintType)
enum class ETileState : uint8 {
    None,
    Near,
    Mid,
    Far,
};

