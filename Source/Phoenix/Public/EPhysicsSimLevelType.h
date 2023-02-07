#pragma once
#include "CoreMinimal.h"
#include "EPhysicsSimLevelType.generated.h"

UENUM(BlueprintType)
enum class EPhysicsSimLevelType : uint8 {
    Attacks,
    Flying,
    LODs,
    Mechanics,
    Misc,
    Mounts,
    Reactions,
    Stations,
    ClothAnimCurves,
};

