#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionProvider.h"
#include "StoryGraphCondition_ConversationResult.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UStoryGraphCondition_ConversationResult : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConversationResult;
    
    UStoryGraphCondition_ConversationResult();
};

