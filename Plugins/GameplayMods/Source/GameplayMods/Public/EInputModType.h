#pragma once
#include "CoreMinimal.h"
#include "EInputModType.generated.h"

UENUM(BlueprintType)
enum class EInputModType : uint8 {
    UnaffectedByExternalInput,
    ValueOfExternalInput,
    ValueOfInputCurveEvaluatedByExternalInput,
};

