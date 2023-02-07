#pragma once
#include "CoreMinimal.h"
#include "EHeadTrackingState.generated.h"

UENUM(BlueprintType)
namespace EHeadTrackingState {
    enum Type {
        None,
        Disallow,
        Allow,
        AllowHeadOnly,
        Allow360,
        AllowHeadOnly360,
    };
}

