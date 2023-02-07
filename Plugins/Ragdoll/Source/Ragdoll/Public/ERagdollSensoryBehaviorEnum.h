#pragma once
#include "CoreMinimal.h"
#include "ERagdollSensoryBehaviorEnum.generated.h"

UENUM(BlueprintType)
enum class ERagdollSensoryBehaviorEnum : uint8 {
    RSBE_CurrentlyActive,
    RSBE_PriorActive,
    RSBE_HadActive,
    RSBE_MAX UMETA(Hidden),
};

