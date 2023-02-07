#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchIsBroomMoving.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchIsBroomMoving : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckHorizontal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckVertical;
    
    UAblBranchIsBroomMoving();
};

