#pragma once
#include "CoreMinimal.h"
#include "EAnimSpeedType.generated.h"

UENUM(BlueprintType)
namespace EAnimSpeedType {
    enum Type {
        Stopped,
        Undetermined,
        WalkSlow,
        Walk,
        Jog,
        Sprint,
    };
}

