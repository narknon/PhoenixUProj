#pragma once
#include "CoreMinimal.h"
#include "EEnemy_TargetQuadrant.generated.h"

UENUM(BlueprintType)
enum class EEnemy_TargetQuadrant : uint8 {
    None,
    LeftForward,
    RightForward,
    LeftBack,
    RightBack,
    Block,
    EEnemy_MAX UMETA(Hidden),
};

