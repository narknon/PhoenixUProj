#pragma once
#include "CoreMinimal.h"
#include "NPC_PerceptionUpdate.h"
#include "Enemy_Target_PerceptionUpdate.generated.h"

UCLASS(Blueprintable)
class UEnemy_Target_PerceptionUpdate : public UNPC_PerceptionUpdate {
    GENERATED_BODY()
public:
    UEnemy_Target_PerceptionUpdate();
};

