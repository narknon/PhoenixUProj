#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerInteractibleItemsFilter.h"
#include "FXAutoTriggerInteractibleItemsFilterNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterNot : public UFXAutoTriggerInteractibleItemsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerInteractibleItemsFilter* Filter;
    
    UFXAutoTriggerInteractibleItemsFilterNot();
};

