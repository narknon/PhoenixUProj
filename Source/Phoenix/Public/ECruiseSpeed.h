#pragma once
#include "CoreMinimal.h"
#include "ECruiseSpeed.generated.h"

UENUM(BlueprintType)
enum class ECruiseSpeed : uint8 {
    FastestMotion,
    SlowestMotion,
    AverageSpeed,
    SpecifiedCruisingSpeed,
};

