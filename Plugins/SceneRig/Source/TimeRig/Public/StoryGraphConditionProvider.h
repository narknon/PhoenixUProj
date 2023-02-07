#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "StoryGraphConditionProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphConditionProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UStoryGraphConditionProvider();
};

