#pragma once
#include "CoreMinimal.h"
#include "GazeStatesEnum.generated.h"

UENUM(BlueprintType)
enum class GazeStatesEnum : uint8 {
    RANDOM_BY_WEIGHT,
    CENTRAL_FOCUS,
    INTERNAL_MEMORY_NW,
    AUDITORY_MEMORY_W,
    EMOTIONAL_MEMORY_SW,
    VISUAL_CONSTRUCTION_NE,
    AUDITORY_CONSTRUCTION_E,
    BODY_SENSATION_RECALL_SE,
    SMELL_N,
    TASTE_S,
};

