#pragma once
#include "CoreMinimal.h"
#include "ERelativeToEnum.generated.h"

UENUM(BlueprintType)
enum class ERelativeToEnum : uint8 {
    RELATIVETO_START,
    RELATIVETO_END,
    RELATIVETO_MAX UMETA(Hidden),
};

