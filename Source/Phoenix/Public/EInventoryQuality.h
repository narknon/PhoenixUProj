#pragma once
#include "CoreMinimal.h"
#include "EInventoryQuality.generated.h"

UENUM(BlueprintType)
enum EInventoryQuality {
    DUMMY,
    NoQuality = 0x3,
    CountQuality = 0x1,
    EInventoryQuality_MAX = 0x4,
};

