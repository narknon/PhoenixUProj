#pragma once
#include "CoreMinimal.h"
#include "EAblNpcReactEventAction.generated.h"

UENUM(BlueprintType)
enum class EAblNpcReactEventAction : uint8 {
    Ignore,
    Enable,
    Disable,
};

