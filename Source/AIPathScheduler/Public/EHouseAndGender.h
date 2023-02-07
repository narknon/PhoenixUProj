#pragma once
#include "CoreMinimal.h"
#include "EHouseAndGender.generated.h"

UENUM(BlueprintType)
enum class EHouseAndGender : uint8 {
    Any,
    Male,
    Female,
    Gryffindor,
    Hufflepuff,
    Ravenclaw,
    Slytherin,
};

