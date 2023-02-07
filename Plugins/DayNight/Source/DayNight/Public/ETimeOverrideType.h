#pragma once
#include "CoreMinimal.h"
#include "ETimeOverrideType.generated.h"

UENUM(BlueprintType)
enum class ETimeOverrideType : uint8 {
    ActualTime,
    NormalizedTime,
};

