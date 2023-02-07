#pragma once
#include "CoreMinimal.h"
#include "EInteractiveState.h"
#include "FXAutoTriggerInteractibleItemsFilter.h"
#include "FXAutoTriggerInteractibleItemsFilterIsState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterIsState : public UFXAutoTriggerInteractibleItemsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractiveState State;
    
    UFXAutoTriggerInteractibleItemsFilterIsState();
};

