#pragma once
#include "CoreMinimal.h"
#include "ETrackingVolumeType.generated.h"

UENUM(BlueprintType)
enum class ETrackingVolumeType : uint8 {
    None,
    RandomEncounter,
    EncounterExclusion,
    Perception,
    ForceAction,
};

