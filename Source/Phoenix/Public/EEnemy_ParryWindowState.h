#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryWindowState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryWindowState : uint8 {
    None,
    PreStart,
    Active,
    Parry,
    Fired,
    Aborted,
    EEnemy_MAX UMETA(Hidden),
};

