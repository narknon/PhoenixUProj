#pragma once
#include "CoreMinimal.h"
#include "EBoneEvaluationRootMode.generated.h"

UENUM(BlueprintType)
enum class EBoneEvaluationRootMode : uint8 {
    UseContentSetting,
    IgnoreRoot,
    IncludeRoot,
};

