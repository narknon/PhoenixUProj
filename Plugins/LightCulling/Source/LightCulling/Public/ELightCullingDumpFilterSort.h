#pragma once
#include "CoreMinimal.h"
#include "ELightCullingDumpFilterSort.generated.h"

UENUM(BlueprintType)
enum class ELightCullingDumpFilterSort : uint8 {
    None,
    Distance,
    Component,
    Name,
    Level,
};

