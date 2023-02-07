#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ENPC_TurnAssist.h"
#include "RootMotionModifierProperties_NPCMobilityTurnAssist.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_NPCMobilityTurnAssist : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssist TurnAssistMode;
    
    URootMotionModifierProperties_NPCMobilityTurnAssist();
};

