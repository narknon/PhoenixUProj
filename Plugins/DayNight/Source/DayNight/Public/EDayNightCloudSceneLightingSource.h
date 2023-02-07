#pragma once
#include "CoreMinimal.h"
#include "EDayNightCloudSceneLightingSource.generated.h"

UENUM(BlueprintType)
enum class EDayNightCloudSceneLightingSource : uint8 {
    DirectionalLight,
    SunLight,
    SunDisk,
    MoonLight,
    Manual,
    Automatic,
};

