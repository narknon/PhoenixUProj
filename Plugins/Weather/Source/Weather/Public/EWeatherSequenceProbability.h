#pragma once
#include "CoreMinimal.h"
#include "EWeatherSequenceProbability.generated.h"

UENUM(BlueprintType)
enum class EWeatherSequenceProbability : uint8 {
    Common,
    Infrequent,
    Rare,
    VeryRare,
    Never,
};

