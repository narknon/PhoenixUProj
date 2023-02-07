#pragma once
#include "CoreMinimal.h"
#include "EAxisMapping.generated.h"

UENUM(BlueprintType)
enum class EAxisMapping : uint8 {
    PositiveX,
    NegativeX,
    PositiveY,
    NegativeY,
    PositiveZ,
    NegativeZ,
};

