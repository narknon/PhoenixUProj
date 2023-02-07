#pragma once
#include "CoreMinimal.h"
#include "EMurmurationValueType.generated.h"

UENUM(BlueprintType)
enum class EMurmurationValueType : uint8 {
    Absolute,
    Relative,
};

