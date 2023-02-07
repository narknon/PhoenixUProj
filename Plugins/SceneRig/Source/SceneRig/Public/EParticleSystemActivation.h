#pragma once
#include "CoreMinimal.h"
#include "EParticleSystemActivation.generated.h"

UENUM()
enum class EParticleSystemActivation : int8 {
    Activate,
    Deactivate,
    ActivateAndDeactivate,
};

