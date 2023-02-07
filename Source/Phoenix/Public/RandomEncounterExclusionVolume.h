#pragma once
#include "CoreMinimal.h"
#include "PhoenixTrackingVolume.h"
#include "RandomEncounterExclusionVolume.generated.h"

UCLASS(Blueprintable)
class ARandomEncounterExclusionVolume : public APhoenixTrackingVolume {
    GENERATED_BODY()
public:
    ARandomEncounterExclusionVolume();
};

