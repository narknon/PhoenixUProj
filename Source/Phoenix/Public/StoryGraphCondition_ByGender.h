#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionProvider.h"
#include "ESexType.h"
#include "StoryGraphCondition_ByGender.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UStoryGraphCondition_ByGender : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESexType PlayerGender;
    
    UStoryGraphCondition_ByGender();
};

