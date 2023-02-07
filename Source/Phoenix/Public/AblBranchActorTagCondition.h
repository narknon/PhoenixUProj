#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchActorTagCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchActorTagCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagName;
    
public:
    UAblBranchActorTagCondition();
};

