#pragma once
#include "CoreMinimal.h"
#include "ELoadingScreenLocation.generated.h"

UENUM(BlueprintType)
enum class ELoadingScreenLocation : uint8 {
    LSL_None,
    LSL_Frontend,
    LSL_Overland,
    LSL_Hogwarts,
    LSL_Hogsmeade,
    LSL_Sanctuary,
    LSL_Dungeon,
    LSL_MAX UMETA(Hidden),
};

