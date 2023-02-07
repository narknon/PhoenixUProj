#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABLECORE_API UAblBranchConditionAnimNotify : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResultIfNotifyDoesNotExist;
    
    UAblBranchConditionAnimNotify();
};

