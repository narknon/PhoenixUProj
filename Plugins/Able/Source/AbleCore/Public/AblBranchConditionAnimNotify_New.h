#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblBranchConditionAnimNotify_New.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchConditionAnimNotify_New : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> Names;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResultIfNotifyDoesNotExist;
    
    UAblBranchConditionAnimNotify_New();
};

