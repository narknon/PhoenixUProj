#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityTaskResult.generated.h"

UENUM(BlueprintType)
enum EAblAbilityTaskResult {
    Successful,
    Branched,
    Interrupted,
};

