#pragma once
#include "CoreMinimal.h"
#include "ESaveType.generated.h"

UENUM(BlueprintType)
enum class ESaveType : uint8 {
    NONE,
    AUTO,
    USER,
    ALL,
};

