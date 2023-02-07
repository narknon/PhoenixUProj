#pragma once
#include "CoreMinimal.h"
#include "EWindSpeedOverlapEffectsMode.generated.h"

UENUM(BlueprintType)
enum class EWindSpeedOverlapEffectsMode : uint8 {
    IndoorsAndOutdoors,
    IndoorsOnly,
    OutdoorsOnly,
};

