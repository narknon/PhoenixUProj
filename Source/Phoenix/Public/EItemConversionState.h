#pragma once
#include "CoreMinimal.h"
#include "EItemConversionState.generated.h"

UENUM(BlueprintType)
enum class EItemConversionState : uint8 {
    Available,
    Converting,
    Converted,
    Pending,
};

