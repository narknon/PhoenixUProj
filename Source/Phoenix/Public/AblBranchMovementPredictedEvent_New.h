#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblBranchMovementPredictedEvent_New.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchMovementPredictedEvent_New : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeThreshold;
    
    UAblBranchMovementPredictedEvent_New();
};

