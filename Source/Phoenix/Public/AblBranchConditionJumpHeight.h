#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "UObject/NoExportTypes.h"
#include "AblBranchConditionJumpHeight.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionJumpHeight : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Range;
    
public:
    UAblBranchConditionJumpHeight();
};

