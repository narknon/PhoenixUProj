#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetPerceptionIntent.generated.h"

UENUM(BlueprintType)
enum class ENPC_TargetPerceptionIntent : uint8 {
    None,
    AsEnemy,
    AsScheduledEntity,
    ENPC_MAX UMETA(Hidden),
};

