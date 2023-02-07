#pragma once
#include "CoreMinimal.h"
#include "ECategoryGenerationType.generated.h"

UENUM(BlueprintType)
enum class ECategoryGenerationType : uint8 {
    Normal,
    RelativeToPlayerLevel,
};

