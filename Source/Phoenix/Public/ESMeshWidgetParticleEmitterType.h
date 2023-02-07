#pragma once
#include "CoreMinimal.h"
#include "ESMeshWidgetParticleEmitterType.generated.h"

UENUM(BlueprintType)
enum class ESMeshWidgetParticleEmitterType : uint8 {
    Continuous,
    Explode,
};

