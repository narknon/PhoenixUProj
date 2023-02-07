#pragma once
#include "CoreMinimal.h"
#include "ETargetOrientation.generated.h"

UENUM(BlueprintType)
enum class ETargetOrientation : uint8 {
    AnyDirection,
    TargetAxis,
    TargetDirection,
};

