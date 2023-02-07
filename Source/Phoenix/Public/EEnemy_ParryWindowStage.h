#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryWindowStage.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryWindowStage : uint8 {
    None,
    LeadIn,
    Release,
    EEnemy_MAX UMETA(Hidden),
};

