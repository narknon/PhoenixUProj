#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "UObject/NoExportTypes.h"
#include "AblBranchConditionQuadrupedSpineAngle.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionQuadrupedSpineAngle : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AngleRange;
    
public:
    UAblBranchConditionQuadrupedSpineAngle();
};

