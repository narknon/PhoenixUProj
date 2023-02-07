#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsDirectionalLightMode.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsDirectionalLightMode : uint8 {
    Unknown,
    Sun,
    Moon,
};

