#pragma once
#include "CoreMinimal.h"
#include "ECreatureStoppingMode.generated.h"

UENUM(BlueprintType)
enum class ECreatureStoppingMode : uint8 {
    Standard,
    Rapid,
    Num,
};

