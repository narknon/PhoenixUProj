#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ECreatureStoppingMode.h"
#include "AblBranchCreatureStoppingModeCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchCreatureStoppingModeCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStoppingMode StoppingMode;
    
public:
    UAblBranchCreatureStoppingModeCondition();
};

