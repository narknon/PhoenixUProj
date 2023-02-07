#pragma once
#include "CoreMinimal.h"
#include "EFlockPersonalityAxis.generated.h"

UENUM(BlueprintType)
enum class EFlockPersonalityAxis : uint8 {
    FPA_PITCH,
    FPA_YAW,
    FPA_ROLL,
    FPA_PITCHORYAW,
    FPA_PITCHORROLL,
    FPA_YAWORROLL,
    FPA_RANDOM,
    FPA_MAX UMETA(Hidden),
};

