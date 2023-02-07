#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackingState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackingState : uint8 {
    None,
    Init,
    Move,
    Execute,
    Reset,
    Finished,
    EEnemy_MAX UMETA(Hidden),
};

