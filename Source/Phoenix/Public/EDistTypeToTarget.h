#pragma once
#include "CoreMinimal.h"
#include "EDistTypeToTarget.generated.h"

UENUM(BlueprintType)
enum class EDistTypeToTarget : uint8 {
    None,
    Attack,
    Pressure,
    Far,
    Count,
};

