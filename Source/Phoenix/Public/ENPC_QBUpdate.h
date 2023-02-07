#pragma once
#include "CoreMinimal.h"
#include "ENPC_QBUpdate.generated.h"

UENUM(BlueprintType)
enum class ENPC_QBUpdate : uint8 {
    PieCut,
    Direct,
    Close,
    Evade,
    Follow,
    InOut,
    SeekWeapon,
    Cover,
    Ticket,
    Reposition,
    Sidekick,
    TombProtector,
    Around,
    SeekTarget,
    BackOnNav,
    LeadPlayer,
    TooClose,
    SwimToShore,
    Standby,
    Duel,
    Alert,
    Companion,
    Combat,
    RecoverWeapon,
    POI,
    ENPC_MAX UMETA(Hidden),
};

