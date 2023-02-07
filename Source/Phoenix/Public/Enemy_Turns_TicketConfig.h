#pragma once
#include "CoreMinimal.h"
#include "Enemy_TicketConfig.h"
#include "Enemy_Turns_TicketConfig.generated.h"

class UDataTable;

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_Turns_TicketConfig : public UEnemy_TicketConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CooldownTable;
    
    UEnemy_Turns_TicketConfig();
};

