#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityLevel.generated.h"

UENUM(BlueprintType)
enum class EPhoenixScalabilityLevel : uint8 {
    Low,
    Medium,
    High,
    Epic,
    Cinematic,
};

