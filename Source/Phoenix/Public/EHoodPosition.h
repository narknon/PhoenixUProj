#pragma once
#include "CoreMinimal.h"
#include "EHoodPosition.generated.h"

UENUM(BlueprintType)
enum class EHoodPosition : uint8 {
    Unset,
    UP,
    DOWN,
};

