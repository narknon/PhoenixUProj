#pragma once
#include "CoreMinimal.h"
#include "ETimeDateChangeValueType.generated.h"

UENUM(BlueprintType)
enum class ETimeDateChangeValueType : uint8 {
    None,
    Relative,
    Absolute,
};

