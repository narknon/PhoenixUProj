#pragma once
#include "CoreMinimal.h"
#include "EMercunaPathEvent.generated.h"

UENUM(BlueprintType)
namespace EMercunaPathEvent {
    enum Type {
        Ready,
        Updated,
        Invalid,
    };
}

