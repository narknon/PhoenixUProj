#pragma once
#include "CoreMinimal.h"
#include "NPC_ParryCounterrState.generated.h"

UENUM(BlueprintType)
enum class NPC_ParryCounterrState : uint8 {
    ParryCounterNone,
    ParryCounterFirst,
    ParryCounterSecond,
    ParryCounterThird,
    ParryCounterFourth,
    ParryCounterFifth,
    ParryCounterBreak,
    NPC_MAX UMETA(Hidden),
};

