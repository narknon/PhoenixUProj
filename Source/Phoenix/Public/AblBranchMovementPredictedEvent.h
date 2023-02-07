#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchMovementPredictedEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchMovementPredictedEvent : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeThreshold;
    
    UAblBranchMovementPredictedEvent();
};

