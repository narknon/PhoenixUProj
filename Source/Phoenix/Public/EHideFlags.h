#pragma once
#include "CoreMinimal.h"
#include "EHideFlags.generated.h"

UENUM(BlueprintType)
enum class EHideFlags : uint8 {
    All,
    All_Tier1,
    All_Tier3,
    SplineWalkers,
    SeatFillers,
    Creatures,
    All_Tier4,
    Companions,
};

