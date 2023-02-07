#pragma once
#include "CoreMinimal.h"
#include "EPhoenixControlMode.generated.h"

UENUM(BlueprintType)
namespace EPhoenixControlMode {
    enum Type {
        Player,
        HoverDrone,
        MAX,
    };
}

