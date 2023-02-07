#pragma once
#include "CoreMinimal.h"
#include "EStreamingBehaviorTactic.generated.h"

UENUM(BlueprintType)
enum class EStreamingBehaviorTactic : uint8 {
    Balanced,
    PrioritizeUnloads,
    PrioritizeLoads,
};

