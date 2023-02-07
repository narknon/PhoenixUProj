#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionNodeReference.h"
#include "StoryGraphConditionProvider.h"
#include "StoryGraphCondition_NodeIsActive.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphCondition_NodeIsActive : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStoryGraphConditionNodeReference Node;
    
    UStoryGraphCondition_NodeIsActive();
};

