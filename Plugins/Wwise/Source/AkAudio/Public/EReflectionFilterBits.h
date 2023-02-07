#pragma once
#include "CoreMinimal.h"
#include "EReflectionFilterBits.generated.h"

UENUM(BlueprintType)
enum class EReflectionFilterBits : uint8 {
    Wall,
    Ceiling,
    Floor,
};

