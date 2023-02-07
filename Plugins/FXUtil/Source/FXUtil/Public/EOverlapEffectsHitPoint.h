#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsHitPoint.generated.h"

UENUM(BlueprintType)
enum class EOverlapEffectsHitPoint : uint8 {
    Default,
    Instigator,
    InstigatorCenter,
    InstigatorBase,
    InstigatorTop,
    Victim,
    VictimCenter,
    VictimBase,
    VictimTop,
    Intersection,
};

