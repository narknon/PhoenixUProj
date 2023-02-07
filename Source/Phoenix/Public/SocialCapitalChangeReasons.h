#pragma once
#include "CoreMinimal.h"
#include "SocialCapitalChangeReasons.generated.h"

UENUM(BlueprintType)
enum SocialCapitalChangeReasons {
    SOCAP_CHANGE_DEBUG,
    SOCAP_CHANGE_MISSION,
    SOCAP_CHANGE_KNOWLEDGE,
    SOCAP_CHANGE_SOCIALACTION,
    SOCAP_CHANGE_SOCIALSTATUS,
    SOCAP_CHANGE_CONVERSATION,
    SOCAP_CHANGE_FACTIONSTATUS,
    SOCAP_CHANGE_COUNT,
    SOCAP_CHANGE_MAX UMETA(Hidden),
};

