#pragma once
#include "CoreMinimal.h"
#include "NPC_QBUpdate.h"
#include "Enemy_QBUpdate.generated.h"

UCLASS(Abstract, Blueprintable)
class UEnemy_QBUpdate : public UNPC_QBUpdate {
    GENERATED_BODY()
public:
    UEnemy_QBUpdate();
};

