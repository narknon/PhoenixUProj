#pragma once
#include "CoreMinimal.h"
#include "EFixedSunPositionType.generated.h"

UENUM(BlueprintType)
enum class EFixedSunPositionType : uint8 {
    Noon,
    Midnight,
    SunRise,
    SunSet,
    Rising,
    Setting,
};

