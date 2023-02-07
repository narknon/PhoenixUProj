#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblBranchConditionReactionEndingScratchpad.generated.h"

class UAblReactionComponent;
class UAblReactionData;

UCLASS(Blueprintable, NonTransient)
class UAblBranchConditionReactionEndingScratchpad : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblReactionComponent* ReactionComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblReactionData* ReactionData;
    
    UAblBranchConditionReactionEndingScratchpad();
};

