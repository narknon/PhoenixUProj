#pragma once
#include "CoreMinimal.h"
#include "ECLothInteractorValueType.generated.h"

UENUM(BlueprintType)
enum class ECLothInteractorValueType : uint8 {
    DEFAULT,
    SET,
    SCALE,
    OFFSET,
};

