#pragma once
#include "CoreMinimal.h"
#include "EActionsCompleteBehaviour.generated.h"

UENUM(BlueprintType)
enum class EActionsCompleteBehaviour : uint8 {
    None,
    Dismount,
    MoveToNewSpline,
};

