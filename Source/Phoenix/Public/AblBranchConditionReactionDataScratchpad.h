#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionReactionDataScratchpad.generated.h"

class UNPC_ReactionComponent;

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionReactionDataScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNPC_ReactionComponent> ReactionComp;
    
    UAblBranchConditionReactionDataScratchpad();
};

