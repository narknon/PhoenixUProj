#pragma once
#include "CoreMinimal.h"
#include "ECreatureFeedState.generated.h"

UENUM(BlueprintType)
enum class ECreatureFeedState : uint8 {
    Inactive,
    Thrown,
    MoveToCreature,
    Eating,
    Vanishing,
};

