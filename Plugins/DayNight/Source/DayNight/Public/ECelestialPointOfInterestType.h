#pragma once
#include "CoreMinimal.h"
#include "ECelestialPointOfInterestType.generated.h"

UENUM(BlueprintType)
enum class ECelestialPointOfInterestType : uint8 {
    Unknown,
    Star,
    MajorConstellation,
    Constellation,
    Zodiac,
    MessierObject,
};

