#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphBranchIcon.h"
#include "StoryGraphConditionBranchReference.h"
#include "StoryGraphConditionProvider.h"
#include "StoryGraphCondition_Branch.generated.h"

class UBoolProvider;
class UStringProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphCondition_Branch : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStoryGraphConditionBranchReference BranchID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* IsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* IsSelectable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStringProvider* DisplayTextID;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EStoryGraphBranchIcon DisplayIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NonSelectableHandling;
    
    UStoryGraphCondition_Branch();
};

