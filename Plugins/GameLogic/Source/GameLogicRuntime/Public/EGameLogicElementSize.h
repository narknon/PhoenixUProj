#pragma once
#include "CoreMinimal.h"
#include "EGameLogicElementSize.generated.h"

UENUM(BlueprintType)
enum class EGameLogicElementSize : uint8 {
    Smallest,
    Small,
    Normal,
    Large,
    Largest,
    MAX_SIZE,
};

