#pragma once
#include "CoreMinimal.h"
#include "EVolumeLoadIdentifier.generated.h"

UENUM(BlueprintType)
enum class EVolumeLoadIdentifier : uint8 {
    OutsideOnly,
    NearHogwarts,
    NearHogsmeade,
    OverlandBig,
    OverlandMedium,
    OverlandSmall,
    InsideLoaded,
    LastItem,
};

