#pragma once
#include "CoreMinimal.h"
#include "ESkyAtmosphereDirectionalLight.generated.h"

UENUM(BlueprintType)
enum class ESkyAtmosphereDirectionalLight : uint8 {
    None,
    Sun,
    Moon,
    Auto,
};

