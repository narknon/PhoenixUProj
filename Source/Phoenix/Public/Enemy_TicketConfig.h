#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Enemy_TicketConfig.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, Config=Game)
class UEnemy_TicketConfig : public UObject {
    GENERATED_BODY()
public:
    UEnemy_TicketConfig();
};

