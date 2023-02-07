#pragma once
#include "CoreMinimal.h"
#include "EInteractUseTargetTracker.generated.h"

UENUM(BlueprintType)
enum class EInteractUseTargetTracker : uint8 {
    FaceTracker,
    AimAtTracker,
    LookAtTracker,
};

