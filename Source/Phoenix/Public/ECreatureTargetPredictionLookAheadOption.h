#pragma once
#include "CoreMinimal.h"
#include "ECreatureTargetPredictionLookAheadOption.generated.h"

UENUM()
enum class ECreatureTargetPredictionLookAheadOption : int32 {
    FromServiceActivation,
    Fixed,
};

