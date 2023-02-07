#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchProbability.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchProbability : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
public:
    UAblBranchProbability();
};

