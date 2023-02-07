#pragma once
#include "CoreMinimal.h"
#include "EBasicMobilityMode.generated.h"

UENUM(BlueprintType)
namespace EBasicMobilityMode {
    enum Type {
        Normal,
        Crouching,
        Stealth,
    };
}

