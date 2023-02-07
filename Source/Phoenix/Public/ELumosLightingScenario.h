#pragma once
#include "CoreMinimal.h"
#include "ELumosLightingScenario.generated.h"

UENUM(BlueprintType)
enum class ELumosLightingScenario : uint8 {
    Legacy,
    CheapSpot,
    SanderRework,
};

