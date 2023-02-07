#pragma once
#include "CoreMinimal.h"
#include "EEnemy_TicketScoreType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_TicketScoreType : uint8 {
    Allowed,
    HasTicket,
    NotAllowed,
    EEnemy_MAX UMETA(Hidden),
};

