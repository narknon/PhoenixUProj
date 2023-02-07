#pragma once
#include "CoreMinimal.h"
#include "EGearHouseID.generated.h"

UENUM(BlueprintType)
enum class EGearHouseID : uint8 {
    HOUSE_GRYFFINDOR,
    HOUSE_HUFFLEPUFF,
    HOUSE_RAVENCLAW,
    HOUSE_SLYTHERIN,
    HOUSE_MAX UMETA(Hidden),
};

