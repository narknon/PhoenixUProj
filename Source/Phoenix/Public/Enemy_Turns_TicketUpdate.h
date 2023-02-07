#pragma once
#include "CoreMinimal.h"
#include "Enemy_TicketUpdate.h"
#include "Enemy_Turns_TicketUpdate.generated.h"

UCLASS(Blueprintable)
class UEnemy_Turns_TicketUpdate : public UEnemy_TicketUpdate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateInterval;
    
    UEnemy_Turns_TicketUpdate();
};

