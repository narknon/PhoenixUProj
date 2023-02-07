#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionProvider.h"
#include "StoryGraphCondition_NOT.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphCondition_NOT : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStoryGraphConditionProvider* ConditionToInvert;
    
    UStoryGraphCondition_NOT();
};

