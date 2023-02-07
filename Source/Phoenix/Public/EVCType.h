#pragma once
#include "CoreMinimal.h"
#include "EVCType.generated.h"

UENUM(BlueprintType)
enum class EVCType : uint8 {
    ITEM,
    LOCK,
    UNKNOWN,
};

