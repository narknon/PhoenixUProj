#pragma once
#include "CoreMinimal.h"
#include "ELookAtTargetMode.generated.h"

UENUM(BlueprintType)
namespace ELookAtTargetMode {
    enum Type {
        None,
        TargetLocation,
        TargetActor,
        CameraDirection,
    };
}

