#pragma once
#include "CoreMinimal.h"
#include "ECreatureTargetPredictionStraightLineReachableOption.generated.h"

UENUM()
enum class ECreatureTargetPredictionStraightLineReachableOption : int32 {
    FromCurrentLocation,
    FromInitialLocation,
};

