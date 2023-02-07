#pragma once
#include "CoreMinimal.h"
#include "ELightCullingDumpFilterDuplicateCheck.generated.h"

UENUM(BlueprintType)
enum class ELightCullingDumpFilterDuplicateCheck : uint8 {
    None,
    PerLevel,
    AcrossLevels,
    Global,
};

