#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "GameplayTagContainer.h"
#include "AblBranchConditionRPGTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchConditionRPGTag : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag RPGTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
    UAblBranchConditionRPGTag();
};

