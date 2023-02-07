#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackThreatHoming.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackThreatHoming : uint8 {
    Unset,
    Stop,
    Stopped,
    EEnemy_MAX UMETA(Hidden),
};

