#pragma once
#include "CoreMinimal.h"
#include "NPC_Update.h"
#include "NPC_PerceptionUpdate.generated.h"

UCLASS(Abstract, Blueprintable)
class UNPC_PerceptionUpdate : public UNPC_Update {
    GENERATED_BODY()
public:
    UNPC_PerceptionUpdate();
};

