#pragma once
#include "CoreMinimal.h"
#include "FBoneParticleAction.generated.h"

UENUM(BlueprintType)
enum class FBoneParticleAction : uint8 {
    Activate,
    Deactivate,
    Destroy,
};

