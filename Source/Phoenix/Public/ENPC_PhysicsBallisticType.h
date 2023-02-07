#pragma once
#include "CoreMinimal.h"
#include "ENPC_PhysicsBallisticType.generated.h"

UENUM(BlueprintType)
enum class ENPC_PhysicsBallisticType : uint8 {
    Target,
    JumpTarget,
    NamedPoint,
    MoveGoal,
    ENPC_MAX UMETA(Hidden),
};

