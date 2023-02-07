#pragma once
#include "CoreMinimal.h"
#include "ECameraStackBehaviorFilterFlags.generated.h"

UENUM(BlueprintType)
enum class ECameraStackBehaviorFilterFlags : uint8 {
    DontListInactiveBehaviors,
    ListBehaviorsAboveCoreBehaviors,
};

