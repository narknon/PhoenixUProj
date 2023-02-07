#pragma once
#include "CoreMinimal.h"
#include "GearStatType.generated.h"

UENUM(BlueprintType)
enum GearStatType {
    None = -0x1,
    Offense,
    Defense,
    Cooldown,
};

