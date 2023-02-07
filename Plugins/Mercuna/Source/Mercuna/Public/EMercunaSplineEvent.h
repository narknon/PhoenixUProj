#pragma once
#include "CoreMinimal.h"
#include "EMercunaSplineEvent.generated.h"

UENUM(BlueprintType)
namespace EMercunaSplineEvent {
    enum Type {
        Ready,
        Updated,
        Invalid,
    };
}

