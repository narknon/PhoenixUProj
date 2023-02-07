#pragma once
#include "CoreMinimal.h"
#include "EFacingTargetMode.generated.h"

UENUM(BlueprintType)
namespace EFacingTargetMode {
    enum Type {
        None,
        TargetLocation,
        TargetActor,
        CameraDirection,
    };
}

