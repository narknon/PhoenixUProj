#pragma once
#include "CoreMinimal.h"
#include "ESpeedType.generated.h"

UENUM(BlueprintType)
namespace ESpeedType {
    enum Type {
        DesiredSpeed,
        AverageSpeed,
        ActualSpeed,
        LastDesiredSpeed,
        BufferedDesiredSpeed,
    };
}

