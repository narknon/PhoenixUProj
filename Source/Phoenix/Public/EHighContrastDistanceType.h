#pragma once
#include "CoreMinimal.h"
#include "EHighContrastDistanceType.generated.h"

UENUM(BlueprintType)
enum class EHighContrastDistanceType : uint8 {
    Item,
    Door,
    Creature,
    Mount,
    Characters,
    Infinity,
};

