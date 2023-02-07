#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerInteractibleItemsFilter.h"
#include "FXAutoTriggerInteractibleItemsFilterActorClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerInteractibleItemsFilterActorClass : public UFXAutoTriggerInteractibleItemsFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> OfActorTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeSubclasses;
    
    UFXAutoTriggerInteractibleItemsFilterActorClass();
};

