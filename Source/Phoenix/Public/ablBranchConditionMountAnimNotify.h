#pragma once
#include "CoreMinimal.h"
#include "AblBranchConditionAnimNotify.h"
#include "ablBranchConditionMountAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UablBranchConditionMountAnimNotify : public UAblBranchConditionAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReturnTrueIfMount;
    
    UablBranchConditionMountAnimNotify();
};

