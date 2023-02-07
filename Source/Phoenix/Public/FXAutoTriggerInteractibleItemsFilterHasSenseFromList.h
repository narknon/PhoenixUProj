#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerInteractibleItemsFilter.h"
#include "FXAutoTriggerInteractibleItemsFilterHasSenseFromList.generated.h"

class UAISense_CogGroup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterHasSenseFromList : public UFXAutoTriggerInteractibleItemsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UAISense_CogGroup>> Senses;
    
    UFXAutoTriggerInteractibleItemsFilterHasSenseFromList();
};

