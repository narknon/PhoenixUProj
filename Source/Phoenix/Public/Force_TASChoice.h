#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssistState.h"
#include "NPC_TurnAssistStateChoice.h"
#include "Force_TASChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UForce_TASChoice : public UNPC_TurnAssistStateChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssistState ForcedState;
    
    UForce_TASChoice();
};

