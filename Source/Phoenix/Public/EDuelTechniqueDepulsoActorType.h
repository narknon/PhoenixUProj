#pragma once
#include "CoreMinimal.h"
#include "EDuelTechniqueDepulsoActorType.generated.h"

UENUM(BlueprintType)
enum class EDuelTechniqueDepulsoActorType : uint8 {
    Any,
    EnvironmentObstacles,
    Enemies,
};

