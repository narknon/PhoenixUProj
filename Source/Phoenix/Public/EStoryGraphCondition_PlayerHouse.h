#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphCondition_PlayerHouse.generated.h"

UENUM()
enum class EStoryGraphCondition_PlayerHouse : int32 {
    Gryffindor,
    Hufflepuff,
    Ravenclaw,
    Slytherin,
    EStoryGraphCondition_MAX UMETA(Hidden),
};

