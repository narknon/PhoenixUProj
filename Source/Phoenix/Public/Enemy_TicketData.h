#pragma once
#include "CoreMinimal.h"
#include "Enemy_TicketData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TicketData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumTickets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumAttackedAddTickets;
    
    PHOENIX_API FEnemy_TicketData();
};

