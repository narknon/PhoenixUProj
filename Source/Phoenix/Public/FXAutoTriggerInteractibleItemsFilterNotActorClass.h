#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerInteractibleItemsFilter.h"
#include "FXAutoTriggerInteractibleItemsFilterNotActorClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterNotActorClass : public UFXAutoTriggerInteractibleItemsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> NotOfActorTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeSubclasses;
    
    UFXAutoTriggerInteractibleItemsFilterNotActorClass();
};

