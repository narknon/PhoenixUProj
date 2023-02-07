#pragma once
#include "CoreMinimal.h"
#include "NPC_PerceptionChoice.h"
#include "Enemy_PerceptionChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_PerceptionChoice : public UNPC_PerceptionChoice {
    GENERATED_BODY()
public:
    UEnemy_PerceptionChoice();
};

