#pragma once
#include "CoreMinimal.h"
#include "ENPC_QBUpdateEvent.generated.h"

UENUM(BlueprintType)
enum class ENPC_QBUpdateEvent : uint8 {
    Ticket,
    MoveChance,
    MoveStop,
    MoveStart,
    Attacked,
    ENPC_MAX UMETA(Hidden),
};

