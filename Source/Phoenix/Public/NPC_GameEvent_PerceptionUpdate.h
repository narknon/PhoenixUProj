#pragma once
#include "CoreMinimal.h"
#include "NPC_PerceptionUpdate.h"
#include "NPC_GameEvent_PerceptionUpdate.generated.h"

UCLASS(Blueprintable)
class UNPC_GameEvent_PerceptionUpdate : public UNPC_PerceptionUpdate {
    GENERATED_BODY()
public:
    UNPC_GameEvent_PerceptionUpdate();
};

