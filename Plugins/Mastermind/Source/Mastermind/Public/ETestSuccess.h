#pragma once
#include "CoreMinimal.h"
#include "ETestSuccess.generated.h"

UENUM(BlueprintType)
enum class ETestSuccess : uint8 {
    Default,
    Success,
    Failure,
};

