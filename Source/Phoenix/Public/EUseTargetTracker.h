#pragma once
#include "CoreMinimal.h"
#include "EUseTargetTracker.generated.h"

UENUM(BlueprintType)
namespace EUseTargetTracker {
    enum Type {
        Facing,
        LookAt,
        AimAt,
    };
}

