#pragma once
#include "CoreMinimal.h"
#include "EVanishmentEventType.generated.h"

UENUM(BlueprintType)
enum class EVanishmentEventType : uint8 {
    Instant,
    LeftToRight,
    RightToLeft,
    TopToBottom,
    HorizontallyOutward,
};

