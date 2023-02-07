#pragma once
#include "CoreMinimal.h"
#include "ENPC_LOSCheckType.generated.h"

UENUM(BlueprintType)
enum class ENPC_LOSCheckType : uint8 {
    None,
    AttackLocToTarget,
    EnemyToTarget,
    ENPC_MAX UMETA(Hidden),
};

