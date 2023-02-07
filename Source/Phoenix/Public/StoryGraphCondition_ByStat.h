#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionProvider.h"
#include "StoryGraphCondition_ByStat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UStoryGraphCondition_ByStat : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StatValue;
    
    UStoryGraphCondition_ByStat();
};

