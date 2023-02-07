#pragma once
#include "CoreMinimal.h"
#include "EHarvestState.generated.h"

UENUM(BlueprintType)
namespace EHarvestState {
    enum Type {
        PullFail,
        PullSucceed,
        PickFail,
        PickSucceed,
    };
}

