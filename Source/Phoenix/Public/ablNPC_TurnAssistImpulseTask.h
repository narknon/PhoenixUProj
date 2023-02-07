#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ENPC_TurnAssist.h"
#include "ENPC_TurnAssistType.h"
#include "ablNPC_TurnAssistImpulseTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablNPC_TurnAssistImpulseTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssistType TurnAssistType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFollow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelativeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssist TurnAssistMode;
    
public:
    UablNPC_TurnAssistImpulseTask();
};

