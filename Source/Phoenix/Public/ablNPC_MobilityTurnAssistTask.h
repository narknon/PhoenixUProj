#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ENPC_TurnAssist.h"
#include "ablNPC_MobilityTurnAssistTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablNPC_MobilityTurnAssistTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssist TurnAssistMode;
    
public:
    UablNPC_MobilityTurnAssistTask();
};

