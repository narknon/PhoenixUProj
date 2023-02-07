#pragma once
#include "CoreMinimal.h"
#include "EStationState.generated.h"

UENUM(BlueprintType)
namespace EStationState {
    enum Type {
        None,
        EnterStation,
        InStation,
        ExitStation,
    };
}

