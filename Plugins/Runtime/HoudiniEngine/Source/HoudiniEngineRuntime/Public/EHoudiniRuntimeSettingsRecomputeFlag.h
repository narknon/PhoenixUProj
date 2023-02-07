#pragma once
#include "CoreMinimal.h"
#include "EHoudiniRuntimeSettingsRecomputeFlag.generated.h"

UENUM(BlueprintType)
enum EHoudiniRuntimeSettingsRecomputeFlag {
    HRSRF_Always,
    HRSRF_OnlyIfMissing,
    HRSRF_Nothing,
    HRSRF_MAX UMETA(Hidden),
};

