#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NPC_TurnAssistStateChoice.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UNPC_TurnAssistStateChoice : public UObject {
    GENERATED_BODY()
public:
    UNPC_TurnAssistStateChoice();
};

