#pragma once
#include "CoreMinimal.h"
#include "EStationMode.generated.h"

UENUM(BlueprintType)
namespace EStationMode {
    enum Type {
        FullBody,
        PartialBody,
    };
}

