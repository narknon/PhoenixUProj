#pragma once
#include "CoreMinimal.h"
#include "EInteractiveState.h"
#include "FXAutoTriggerInteractibleItemsFilter.h"
#include "FXAutoTriggerInteractibleItemsFilterIsStateFromList.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterIsStateFromList : public UFXAutoTriggerInteractibleItemsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EInteractiveState> States;
    
    UFXAutoTriggerInteractibleItemsFilterIsStateFromList();
};

