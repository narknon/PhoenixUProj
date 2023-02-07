#pragma once
#include "CoreMinimal.h"
#include "EConsiderationCurveType.generated.h"

UENUM(BlueprintType)
enum class EConsiderationCurveType : uint8 {
    Custom,
    Linear_Up,
    Linear_Down,
};

