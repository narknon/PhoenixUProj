#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchMovementPredictedCollision.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchMovementPredictedCollision : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxGlancingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTimeFromNow;
    
    UAblBranchMovementPredictedCollision();
};

