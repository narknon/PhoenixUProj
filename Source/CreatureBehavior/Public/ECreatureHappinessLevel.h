#pragma once
#include "CoreMinimal.h"
#include "ECreatureHappinessLevel.generated.h"

UENUM(BlueprintType)
enum class ECreatureHappinessLevel : uint8 {
    CreatureHappinessLevel_Low,
    CreatureHappinessLevel_Medium,
    CreatureHappinessLevel_High,
    CreatureHappinessLevel_MAX UMETA(Hidden),
};

