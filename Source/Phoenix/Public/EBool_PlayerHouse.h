#pragma once
#include "CoreMinimal.h"
#include "EBool_PlayerHouse.generated.h"

UENUM()
enum class EBool_PlayerHouse : int32 {
    Gryffindor,
    Hufflepuff,
    Ravenclaw,
    Slytherin,
    EBool_MAX UMETA(Hidden),
};

