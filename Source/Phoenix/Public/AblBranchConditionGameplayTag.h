#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "GameplayTagContainer.h"
#include "AblBranchConditionGameplayTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchConditionGameplayTag : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
    UAblBranchConditionGameplayTag();
};

