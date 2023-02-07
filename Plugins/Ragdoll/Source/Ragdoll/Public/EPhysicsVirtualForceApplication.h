#pragma once
#include "CoreMinimal.h"
#include "EPhysicsVirtualForceApplication.generated.h"

UENUM(BlueprintType)
enum class EPhysicsVirtualForceApplication : uint8 {
    PartialBodyOnly,
    FullBodyOnly,
    Always,
    Never,
};

