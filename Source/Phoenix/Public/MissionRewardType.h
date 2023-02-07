#pragma once
#include "CoreMinimal.h"
#include "MissionRewardType.generated.h"

UENUM(BlueprintType)
enum MissionRewardType {
    MISSION_REWARD_TYPE_CONTAINER,
    MISSION_REWARD_TYPE_ITEM,
    MISSION_REWARD_TYPE_KNOWLEDGE,
    MISSION_REWARD_TYPE_SPELL,
    MISSION_REWARD_TYPE_MAX UMETA(Hidden),
};

