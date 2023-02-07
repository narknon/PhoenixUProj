#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackChoiceSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackChoiceSource : uint8 {
    Normal,
    Interrupt,
    Split,
    PreAttack,
    EEnemy_MAX UMETA(Hidden),
};

