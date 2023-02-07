#pragma once
#include "CoreMinimal.h"
#include "EDoorFastTravelType.generated.h"

UENUM(BlueprintType)
enum class EDoorFastTravelType : uint8 {
    NotUsingFastTravel,
    TravelToOtherSideOfDoor,
    TravelToNamedLocation,
    TravelToDifferentNamedLocationBasedOnSide,
};

