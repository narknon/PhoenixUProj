#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIActionDoneReason.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIActionDoneReason : uint8 {
    Stop,
    Abort,
};

