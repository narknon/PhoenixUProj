#pragma once
#include "CoreMinimal.h"
#include "EPerformTaskContainerType.generated.h"

UENUM(BlueprintType)
enum class EPerformTaskContainerType : uint8 {
    LeadingPlayer,
    EnemyPatrol,
    Custom,
};

