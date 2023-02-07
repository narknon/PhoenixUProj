#pragma once
#include "CoreMinimal.h"
#include "EModExternalInputMethod.generated.h"

UENUM(BlueprintType)
enum class EModExternalInputMethod : uint8 {
    CallExternalInputFunction,
    ReadExternalInputTagBlackboardValue,
};

