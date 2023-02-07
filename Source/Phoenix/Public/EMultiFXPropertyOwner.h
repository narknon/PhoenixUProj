#pragma once
#include "CoreMinimal.h"
#include "EMultiFXPropertyOwner.generated.h"

UENUM(BlueprintType)
enum class EMultiFXPropertyOwner : uint8 {
    FX,
    Target,
    Instigator,
};

