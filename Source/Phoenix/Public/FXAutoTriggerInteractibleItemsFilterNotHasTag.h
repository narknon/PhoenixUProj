#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerInteractibleItemsFilterHasTag.h"
#include "FXAutoTriggerInteractibleItemsFilterNotHasTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterNotHasTag : public UFXAutoTriggerInteractibleItemsFilterHasTag {
    GENERATED_BODY()
public:
    UFXAutoTriggerInteractibleItemsFilterNotHasTag();
};

