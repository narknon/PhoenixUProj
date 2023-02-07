#pragma once
#include "CoreMinimal.h"
#include "FCPSupportType.generated.h"

UENUM()
enum class FCPSupportType : int32 {
    Ignore,
    None,
    Stairs,
    Slope,
};

