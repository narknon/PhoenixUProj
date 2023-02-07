#pragma once
#include "CoreMinimal.h"
#include "ECreatureAIState.generated.h"

UENUM(BlueprintType)
enum class ECreatureAIState : uint8 {
    UtilitySelection,
    SpawnOnDen,
    FollowActor,
    PostGrowUp,
    Dead,
    Wander_DEPRECATED,
    NearDeathKneeling,
    InCage,
    CustomAbility,
    Mounted,
    Cinematic,
    ScheduledEntityMode,
};

