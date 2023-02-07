#pragma once
#include "CoreMinimal.h"
#include "EStationBreakableStates.generated.h"

UENUM(BlueprintType)
enum EStationBreakableStates {
    Unbroken,
    Broken,
    Protected,
};

