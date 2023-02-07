#pragma once
#include "CoreMinimal.h"
#include "EStationSetupHouseAndGender.generated.h"

UENUM(BlueprintType)
enum class EStationSetupHouseAndGender : uint8 {
    Random,
    Female,
    Male,
    Gryffindor,
    Slytherin,
    Ravenclaw,
    Hufflepuff,
};

