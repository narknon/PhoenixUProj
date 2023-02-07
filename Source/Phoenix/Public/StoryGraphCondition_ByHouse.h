#pragma once
#include "CoreMinimal.h"
#include "StoryGraphConditionProvider.h"
#include "EStoryGraphCondition_PlayerHouse.h"
#include "StoryGraphCondition_ByHouse.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UStoryGraphCondition_ByHouse : public UStoryGraphConditionProvider {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EStoryGraphCondition_PlayerHouse PlayerHouse;
    
    UStoryGraphCondition_ByHouse();
};

