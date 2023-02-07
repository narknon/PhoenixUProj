#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionProvider.h"
#include "StoryGraphCondition_OR.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphCondition_OR : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStoryGraphConditionProvider*> Conditions;
    
    UStoryGraphCondition_OR();
};

