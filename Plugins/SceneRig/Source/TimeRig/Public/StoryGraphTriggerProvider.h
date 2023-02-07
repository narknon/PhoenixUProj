#pragma once
#include "CoreMinimal.h"
#include "BaseProvider.h"
#include "StoryGraphTriggerProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphTriggerProvider : public UBaseProvider {
    GENERATED_BODY()
public:
    UStoryGraphTriggerProvider();
};

