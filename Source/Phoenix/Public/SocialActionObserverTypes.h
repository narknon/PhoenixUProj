#pragma once
#include "CoreMinimal.h"
#include "SocialActionObserverTypes.generated.h"

UENUM(BlueprintType)
enum SocialActionObserverTypes {
    OBSERVER_TYPE_SOCIALACTIONHEARSAY,
    OBSERVER_TYPE_SOCIALACTIONTARGET,
    OBSERVER_TYPE_SOCIALACTIONWITNESS,
    OBSERVER_TYPE_COUNT,
    OBSERVER_TYPE_MAX UMETA(Hidden),
};

