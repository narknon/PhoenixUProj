#pragma once
#include "CoreMinimal.h"
#include "NPC_Update.h"
#include "NPC_QBUpdate.generated.h"

UCLASS(Abstract, Blueprintable)
class UNPC_QBUpdate : public UNPC_Update {
    GENERATED_BODY()
public:
    UNPC_QBUpdate();
};

