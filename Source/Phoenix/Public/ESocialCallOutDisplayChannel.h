#pragma once
#include "CoreMinimal.h"
#include "ESocialCallOutDisplayChannel.generated.h"

UENUM(BlueprintType)
namespace ESocialCallOutDisplayChannel {
    enum Type {
        SocialCapitalMovement,
        StationSelection,
        ScheduledGoal,
        Name,
        TravelGoalSite,
        NUM_CHANNELS,
    };
}

