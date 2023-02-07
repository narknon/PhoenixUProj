#pragma once
#include "CoreMinimal.h"
#include "EMercunaLevelOfDetail.generated.h"

UENUM(BlueprintType)
enum class EMercunaLevelOfDetail : uint8 {
    Full,
    Half,
    Quarter,
    Eighth,
    Sixteenth,
};

