#pragma once
#include "CoreMinimal.h"
#include "EAblReactionState.generated.h"

UENUM(BlueprintType)
enum class EAblReactionState : uint8 {
    Queued,
    Active,
    Ending,
    Inactive,
    Finished,
};

