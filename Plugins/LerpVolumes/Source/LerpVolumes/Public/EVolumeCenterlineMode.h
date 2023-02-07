#pragma once
#include "CoreMinimal.h"
#include "EVolumeCenterlineMode.generated.h"

UENUM(BlueprintType)
enum class EVolumeCenterlineMode : uint8 {
    None,
    XAxis,
    YAxis,
    ZAxis,
};

