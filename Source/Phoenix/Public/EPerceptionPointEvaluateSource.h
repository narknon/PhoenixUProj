#pragma once
#include "CoreMinimal.h"
#include "EPerceptionPointEvaluateSource.generated.h"

UENUM(BlueprintType)
enum class EPerceptionPointEvaluateSource : uint8 {
    None,
    Enemy,
    Target,
};

