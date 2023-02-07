#pragma once
#include "CoreMinimal.h"
#include "EEnemy_InvestigateState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_InvestigateState : uint8 {
    None,
    Start,
    Move,
    Investigate,
    Stop,
    DrawWeapon,
    Pause,
    EEnemy_MAX UMETA(Hidden),
};

