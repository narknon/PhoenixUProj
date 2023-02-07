#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdate.h"
#include "Enemy_TicketUpdate.generated.h"

UCLASS(Abstract, Blueprintable)
class UEnemy_TicketUpdate : public UEnemy_QBUpdate {
    GENERATED_BODY()
public:
    UEnemy_TicketUpdate();
};

