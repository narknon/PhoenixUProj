#pragma once
#include "CoreMinimal.h"
#include "AblConditionalBranchTaskBase.h"
#include "EInteractionProject.h"
#include "GameplayTagContainer.h"
#include "AblConditionalLookupBranchTask.generated.h"

class UInteractionArchitectAsset;

UCLASS(Blueprintable, EditInlineNew)
class UAblConditionalLookupBranchTask : public UAblConditionalBranchTaskBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* InteractionArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractionProject Project;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowBranchingIntoCurrentAbility;
    
public:
    UAblConditionalLookupBranchTask();
};

